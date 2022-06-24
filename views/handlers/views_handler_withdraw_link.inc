<?php
/**
 * Field handler to present a link to withdraw invitation.
 */
class views_handler_withdraw_link extends views_handler_field {

  /**
   * Add required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['reg_code'] = array(
      'table' => 'invite',
      'field' => 'reg_code',
    );
  }

  function render($values) {

    // Prevent providing Withdraw link for already canceled invitations.
    if ($values->invite_canceled == TRUE) {
      return;
    }

    $link = l(t('withdraw'), "invite/withdraw/$values->invite_reg_code", array('query' => backdrop_get_destination()));
    return $link;


  }
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

}

