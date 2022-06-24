<?php
/**
 * Field handler to present a status field.
 */
class views_handler_status extends views_handler_field {

  /**
   * Add required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['expiry'] = array(
      'table' => 'invite',
      'field' => 'expiry',
    );
    $this->additional_fields['canceled'] = array(
      'table' => 'invite',
      'field' => 'canceled',
    );
    $this->additional_fields['joined'] = array(
      'table' => 'invite',
      'field' => 'joined',
    );
  }

  function render($values) {

    $date = new DateTime();
    if ($date->getTimestamp() > $values->invite_expiry) {
      return 'Expired';
    }
    elseif ($values->invite_canceled == TRUE) {
      return 'Canceled';
    }
    elseif (!empty($values->invite_joined)) {
      return 'Accepted';
    }
    else {
      return 'Pending';
    }

  }
  function query() {
    $this->add_additional_fields();
  }

}

