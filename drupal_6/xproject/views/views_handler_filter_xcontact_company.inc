<?php

class views_handler_filter_xcontact_company extends views_handler_filter_many_to_one {
  function get_value_options() {
    $this->value_options = xcontact_get_companies();
  }
}

?>