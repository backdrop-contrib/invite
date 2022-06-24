<?php
/**
 * Field handler to present a link to resend invitation.
 */
class views_handler_resend_link extends views_handler_field {
  /**
   * Add required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['reg_code'] = array(
      'table' => 'invite',
      'field' => 'reg_code',
    );
    $this->additional_fields['expiry'] = array(
      'table' => 'invite',
      'field' => 'expiry',
    );
  }

  function render($values) {

    // Providing Resend link for only expired invitations.
    $date = new DateTime();
    if ($date->getTimestamp() < $values->invite_expiry) {
      return;
    }

    $link = l(t('resend'), "invite/resend/$values->invite_reg_code");

    return $link;

  }
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

}

