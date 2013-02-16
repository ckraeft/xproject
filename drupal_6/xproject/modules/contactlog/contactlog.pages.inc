<?php

/**
 * @file
 * User page callbacks for the contactlog module.
 */

/**
 * Form builder; generate a contactlog editing form.
 *
 * @param $cid
 *   ID of the contactlog to be edited.
 * @ingroup forms
 */
function contactlog_edit($cid) {
  global $user;

  $contactlog = db_fetch_object(db_query('SELECT c.*, u.uid, u.name AS registered_name, u.data FROM {contactlogs} c INNER JOIN {users} u ON c.uid = u.uid WHERE c.lid = %d', $cid));
  $contactlog = drupal_unpack($contactlog);
  $contactlog->name = $contactlog->uid ? $contactlog->registered_name : $contactlog->name;
  if (contactlog_access('edit', $contactlog)) {
    return contactlog_form_box((array)$contactlog);
  }
  else {
    drupal_access_denied();
  }
}

/**
 * This function is responsible for generating a contactlog reply form.
 * There are several cases that have to be handled, including:
 *   - replies to contactlogs
 *   - replies to nodes
 *   - attempts to reply to nodes that can no longer accept contactlogs
 *   - respecting access permissions ('access contactlogs', 'post contactlogs', etc.)
 *
 * The node or contactlog that is being replied to must appear above the contactlog
 * form to provide the user context while authoring the contactlog.
 *
 * @param $node
 *   Every contactlog belongs to a node. This is that node.
 *
 * @return
 *   The rendered parent node or contactlog plus the new contactlog form.
 */
function contactlog_reply($node) {
  // Set the breadcrumb trail.
  drupal_set_breadcrumb(array(l(t('Home'), NULL), l($node->title, 'node/'. $node->nid)));
  $op = isset($_POST['op']) ? $_POST['op'] : '';

  $output = '';

  if (user_access('access contactlogs')) {
    // The user is previewing a contactlog prior to submitting it.
    if ($op == t('Preview')) {
      if (user_access('post contactlogs')) {
        $output .= contactlog_form_box(array('nid' => $node->nid), NULL);
      }
      else {
        drupal_set_message(t('You are not authorized to post contactlogs.'), 'error');
        drupal_goto("node/$node->nid");
      }
    }
    else {
      if (user_access('access content')) {
        $output .= node_view($node);
      }

      // Should we show the reply box?
      if (variable_get('contactlog_'. $node->type, CONTACTLOG_NODE_READ_WRITE) != COMMENT_NODE_READ_WRITE) {
        drupal_set_message(t("This discussion is closed: you can't post new contactlogs."), 'error');
        drupal_goto("node/$node->nid");
      }
      else if (user_access('post contactlogs')) {
        $output .= contactlog_form_box(array('nid' => $node->nid), t('Log Contact Details'));
      }
      else {
        drupal_set_message(t('You are not authorized to post contactlogs.'), 'error');
        drupal_goto("node/$node->nid");
      }
    }
  }
  else {
    drupal_set_message(t('You are not authorized to view contactlogs.'), 'error');
    drupal_goto("node/$node->nid");
  }

  return $output;
}
