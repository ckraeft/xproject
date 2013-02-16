<?php
// $Id: views_handler_filter_node_type.inc,v 1.2 2009/06/02 17:57:48 merlinofchaos Exp $
/**
 * Filter by node type
 */
class views_handler_filter_xproject_status extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Status');
      $options = array(
        'Draft' => t('Draft'), 
        'Pending' => t('Pending'), 
        'Active' => t('Active'),
        'On Hold' => t('On Hold'),
        'Archived' => t('Archived'),
      );
      $this->value_options = $options;
    }
  }
}
