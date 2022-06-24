<?php
/**
 * Field handler to present a link to accept invitation.
 */
class views_handler_accept_link extends views_handler_field {

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

    // Prevent providing Accept link for canceled, already joined or expired invitations.
    $date = new DateTime();
    if ($values->invite_canceled == TRUE || $values->invite_joined != FALSE || $date->getTimestamp() > $values->invite_expiry) {
      return;
    }

    $link = l(t('show link'), 'invite/accept/' . $values->invite_reg_code, array('attributes' => array('class' => array('invite-reg-link'), 'title' => t('Registration link for @email', array('@email' => $values->invite_email))), 'absolute' => TRUE));

    return $link;

  }
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

}

