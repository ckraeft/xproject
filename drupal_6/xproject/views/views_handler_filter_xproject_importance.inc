<?php
// $Id: views_handler_filter_node_type.inc,v 1.2 2009/06/02 17:57:48 merlinofchaos Exp $
/**
 * Filter by node type
 */
class views_handler_filter_xproject_importance extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Importance');
      $options = array(
            1 => 1, 
            2 => 2, 
            3 => 3,
            4 => 4,
            5 => 5,
            6 => 6,
            7 => 7,
            8 => 8,
            9 => 9,
      );
      $this->value_options = $options;
    }
  }
}
