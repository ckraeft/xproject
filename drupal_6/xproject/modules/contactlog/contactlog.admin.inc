<?php

/**
 * @file
 * Admin page callbacks for the contactlog module.
 */

/**
 * Menu callback; present an administrative contactlog listing.
 */
function contactlog_admin($type = 'new') {
  $edit = $_POST;

  if (isset($edit['operation']) && ($edit['operation'] == 'delete') && isset($edit['contactlogs']) && $edit['contactlogs']) {
    return drupal_get_form('contactlog_multiple_delete_confirm');
  }
  else {
    return drupal_get_form('contactlog_admin_overview', $type, arg(4));
  }
}

/**
 * Form builder; Builds the contactlog overview form for the admin.
 *
 * @param $type
 *   Not used.
 * @param $arg
 *   Current path's fourth component deciding the form type (Published contactlogs/Approval queue)
 * @return
 *   The form structure.
 * @ingroup forms
 * @see contactlog_admin_overview_validate()
 * @see contactlog_admin_overview_submit()
 * @see theme_contactlog_admin_overview()
 */
function contactlog_admin_overview($type = 'new', $arg) {
  // build an 'Update options' form
  $form['options'] = array(
    '#type' => 'fieldset', '#title' => t('Update options'),
    '#prefix' => '<div class="container-inline">', '#suffix' => '</div>'
  );
  $options = array();
  foreach (contactlog_operations($arg == 'approval' ? 'publish' : 'unpublish') as $key => $value) {
    $options[$key] = $value[0];
  }
  $form['options']['operation'] = array('#type' => 'select', '#options' => $options, '#default_value' => 'publish');
  $form['options']['submit'] = array('#type' => 'submit', '#value' => t('Update'));

  // load the contactlogs that we want to display
  $status = ($arg == 'approval') ? COMMENT_NOT_PUBLISHED : COMMENT_PUBLISHED;
  $form['header'] = array('#type' => 'value', '#value' => array(
    theme('table_select_header_cell'),
    array('data' => t('Subject'), 'field' => 'subject'),
    array('data' => t('Author'), 'field' => 'name'),
    array('data' => t('Posted in'), 'field' => 'node_title'),
    array('data' => t('Time'), 'field' => 'timestamp', 'sort' => 'desc'),
    array('data' => t('Operations'))
  ));
  $result = pager_query('SELECT c.subject, c.nid, c.lid, c.contactlog, c.timestamp, c.status, c.name, c.homepage, u.name AS registered_name, u.uid, n.title as node_title FROM {contactlogs} c INNER JOIN {users} u ON u.uid = c.uid INNER JOIN {node} n ON n.nid = c.nid WHERE c.status = %d'. tablesort_sql($form['header']['#value']), 50, 0, NULL, $status);

  // build a table listing the appropriate contactlogs
  $destination = drupal_get_destination();
  while ($contactlog = db_fetch_object($result)) {
    $contactlogs[$contactlog->lid] = '';
    $contactlog->name = $contactlog->uid ? $contactlog->registered_name : $contactlog->name;
    $form['subject'][$contactlog->lid] = array('#value' => l($contactlog->subject, 'node/'. $contactlog->nid, array('attributes' => array('title' => truncate_utf8($contactlog->contactlog, 128)), 'fragment' => 'contactlog-'. $contactlog->lid)));
    $form['username'][$contactlog->lid] = array('#value' => theme('username', $contactlog));
    $form['node_title'][$contactlog->lid] = array('#value' => l($contactlog->node_title, 'node/'. $contactlog->nid));
    $form['timestamp'][$contactlog->lid] = array('#value' => format_date($contactlog->timestamp, 'small'));
    $form['operations'][$contactlog->lid] = array('#value' => l(t('edit'), 'contactlog/edit/'. $contactlog->lid, array('query' => $destination)));
  }
  $form['contactlogs'] = array('#type' => 'checkboxes', '#options' => isset($contactlogs) ? $contactlogs: array());
  $form['pager'] = array('#value' => theme('pager', NULL, 50, 0));
  return $form;
}

/**
 * Validate contactlog_admin_overview form submissions.
 *
 * We can't execute any 'Update options' if no contactlogs were selected.
 */
function contactlog_admin_overview_validate($form, &$form_state) {
  $form_state['values']['contactlogs'] = array_diff($form_state['values']['contactlogs'], array(0));
  if (count($form_state['values']['contactlogs']) == 0) {
    form_set_error('', t('Please select one or more contactlogs to perform the update on.'));
  }
}

/**
 * Process contactlog_admin_overview form submissions.
 *
 * Execute the chosen 'Update option' on the selected contactlogs, such as
 * publishing, unpublishing or deleting.
 */
function contactlog_admin_overview_submit($form, &$form_state) {
  $operations = contactlog_operations();
  if (!empty($operations[$form_state['values']['operation']][1])) {
    // extract the appropriate database query operation
    $query = $operations[$form_state['values']['operation']][1];
    foreach ($form_state['values']['contactlogs'] as $lid => $value) {
      if ($value) {
        // perform the update action, then refresh node statistics
        db_query($query, $lid);
        $contactlog = _contactlog_load($lid);
        _contactlog_update_node_statistics($contactlog->nid);
        // Allow modules to respond to the updating of a contactlog.
        contactlog_invoke_contactlog($contactlog, $form_state['values']['operation']);
        // Add an entry to the watchdog log.
        watchdog('content', 'Contact Log: updated %subject.', array('%subject' => $contactlog->subject), WATCHDOG_NOTICE, l(t('view'), 'node/'. $contactlog->nid, array('fragment' => 'contactlog-'. $contactlog->lid)));
      }
    }
    cache_clear_all();
    drupal_set_message(t('The update has been performed.'));
    $form_state['redirect'] = 'admin/content/contactlog';
  }
}

/**
 * Theme the contactlog admin form.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @ingroup themeable
 */
function theme_contactlog_admin_overview($form) {
  $output = drupal_render($form['options']);
  if (isset($form['subject']) && is_array($form['subject'])) {
    foreach (element_children($form['subject']) as $key) {
      $row = array();
      $row[] = drupal_render($form['contactlogs'][$key]);
      $row[] = drupal_render($form['subject'][$key]);
      $row[] = drupal_render($form['username'][$key]);
      $row[] = drupal_render($form['node_title'][$key]);
      $row[] = drupal_render($form['timestamp'][$key]);
      $row[] = drupal_render($form['operations'][$key]);
      $rows[] = $row;
    }
  }
  else {
    $rows[] = array(array('data' => t('No contactlogs available.'), 'colspan' => '6'));
  }

  $output .= theme('table', $form['header']['#value'], $rows);
  if ($form['pager']['#value']) {
    $output .= drupal_render($form['pager']);
  }

  $output .= drupal_render($form);

  return $output;
}

/**
 * List the selected contactlogs and verify that the admin really wants to delete
 * them.
 *
 * @param $form_state
 *   An associative array containing the current state of the form.
 * @return
 *   TRUE if the contactlogs should be deleted, FALSE otherwise.
 * @ingroup forms
 * @see contactlog_multiple_delete_confirm_submit()
 */
function contactlog_multiple_delete_confirm(&$form_state) {
  $edit = $form_state['post'];

  $form['contactlogs'] = array('#prefix' => '<ul>', '#suffix' => '</ul>', '#tree' => TRUE);
  // array_filter() returns only elements with actual values
  $contactlog_counter = 0;
  foreach (array_filter($edit['contactlogs']) as $lid => $value) {
    $contactlog = _contactlog_load($lid);
    if (is_object($contactlog) && is_numeric($contactlog->lid)) {
      $subject = db_result(db_query('SELECT subject FROM {contactlogs} WHERE lid = %d', $lid));
      $form['contactlogs'][$lid] = array('#type' => 'hidden', '#value' => $lid, '#prefix' => '<li>', '#suffix' => check_plain($subject) .'</li>');
      $contactlog_counter++;
    }
  }
  $form['operation'] = array('#type' => 'hidden', '#value' => 'delete');

  if (!$contactlog_counter) {
    drupal_set_message(t('There do not appear to be any contactlogs to delete or your selected contactlog was deleted by another administrator.'));
    drupal_goto('admin/content/contactlog');
  }
  else {
    return confirm_form($form,
                        t('Are you sure you want to delete these contactlogs and all their children?'),
                        'admin/content/contactlog', t('This action cannot be undone.'),
                        t('Delete contactlogs'), t('Cancel'));
  }
}

/**
 * Process contactlog_multiple_delete_confirm form submissions.
 *
 * Perform the actual contactlog deletion.
 */
function contactlog_multiple_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    foreach ($form_state['values']['contactlogs'] as $lid => $value) {
      $contactlog = _contactlog_load($lid);
      _contactlog_delete_thread($contactlog);
      _contactlog_update_node_statistics($contactlog->nid);
    }
    cache_clear_all();
    drupal_set_message(t('The contactlogs have been deleted.'));
  }
  $form_state['redirect'] = 'admin/content/contactlog';
}

/**
 * Menu callback; delete a contactlog.
 *
 * @param $lid
 *   The contactlog do be deleted.
 */
function contactlog_delete($lid = NULL) {
  $contactlog = db_fetch_object(db_query('SELECT c.*, u.name AS registered_name, u.uid FROM {contactlogs} c INNER JOIN {users} u ON u.uid = c.uid WHERE c.lid = %d', $lid));
  $contactlog->name = $contactlog->uid ? $contactlog->registered_name : $contactlog->name;

  $output = '';

  if (is_object($contactlog) && is_numeric($contactlog->lid)) {
    $output = drupal_get_form('contactlog_confirm_delete', $contactlog);
  }
  else {
    drupal_set_message(t('The contactlog no longer exists.'));
  }

  return $output;
}

/**
 * Form builder; Builds the confirmation form for deleting a single contactlog.
 *
 * @ingroup forms
 * @see contactlog_confirm_delete_submit()
 */
function contactlog_confirm_delete(&$form_state, $contactlog) {
  $form = array();
  $form['#contactlog'] = $contactlog;
  return confirm_form(
    $form,
    t('Are you sure you want to delete the contactlog %title?', array('%title' => $contactlog->subject)),
    'node/'. $contactlog->nid,
    t('Any replies to this contactlog will be lost. This action cannot be undone.'),
    t('Delete'),
    t('Cancel'),
    'contactlog_confirm_delete');
}

/**
 * Process contactlog_confirm_delete form submissions.
 */
function contactlog_confirm_delete_submit($form, &$form_state) {
  drupal_set_message(t('The contactlog and all its replies have been deleted.'));

  $contactlog = $form['#contactlog'];

  // Delete contactlog and its replies.
  _contactlog_delete_thread($contactlog);

  // Clear the cache so an anonymous user sees that his contactlog was deleted.
  cache_clear_all();

  $form_state['redirect'] = "node/$contactlog->nid";
}

/**
 * Perform the actual deletion of a contactlog and all its replies.
 *
 * @param $contactlog
 *   An associative array describing the contactlog to be deleted.
 */
function _contactlog_delete_thread($contactlog) {
  if (!is_object($contactlog) || !is_numeric($contactlog->lid)) {
    watchdog('content', 'Cannot delete non-existent contactlog.', array(), WATCHDOG_WARNING);
    return;
  }

  // Delete the contactlog:
  db_query('DELETE FROM {contactlogs} WHERE lid = %d', $contactlog->lid);
  watchdog('content', 'Comment: deleted %subject.', array('%subject' => $contactlog->subject));

  contactlog_invoke_contactlog($contactlog, 'delete');
}
