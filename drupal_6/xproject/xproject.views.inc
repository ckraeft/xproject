<?php


/**
 * Implementation of hook_views_handlers().
 */
function xproject_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'xproject') .'/views',
    ),
    'handlers' => array(
      // filter
      'xproject_handler_filter_xproject_nid' => array(
        'parent' => 'views_handler_filter_many_to_one',
      ),
      'xproject_handler_filter_xproject_type_all' => array(
        'parent' => 'views_handler_filter',
      ),
      'xproject_handler_filter_xproject_type' => array(
        'parent' => 'views_handler_filter_node_type',
      ),
      'xproject_handler_filter_xproject_priority' => array(
        'parent' => 'views_handler_filter',
      ),
      'xproject_handler_filter_xproject_importance' => array(
        'parent' => 'views_handler_filter',
      ),
      'xproject_handler_filter_xproject_hours_remaining' => array(
        'parent' => 'views_handler_filter',
      ),
      // field
      'xproject_handler_field_xproject_tpl_projectid' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_is_template' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_status' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_importance' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_priority' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_is_private' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_hours_planned' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_hours_spent' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_hours_remaining' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_is_approved' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_planned_start' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_planned_end' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_actual_start' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'xproject_handler_field_xproject_actual_end' => array(
        'parent' => 'views_handler_field_numeric',
      ),

    ),
  );
}

?>