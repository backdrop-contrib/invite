<?php
class views_handler_status_filter extends views_handler_filter {

  public function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'select',
      '#title' => 'Options',
      '#options' => array(
        'Accepted' => 'Accepted',
        'Pending' => 'Pending',
        'Expired' => 'Expired',
      ),
      '#default_value' => $this->value,
    );
  }

  public function query() {
    $this->ensure_my_table();

    if ($this->value == 'Accepted') {
      $this->query->add_where_expression(0, "invite.joined > 0");
      $this->query->add_where_expression(0, "invite.canceled = :value", array(':value' => FALSE));
    }

    if ($this->value == 'Pending') {
      $date = new DateTime();
      $now = $date->getTimestamp();
      $this->query->add_where_expression(0, "invite.expiry > $now");
      $this->query->add_where_expression(0, "invite.joined = 0");
      $this->query->add_where_expression(0, "invite.canceled = :value", array(':value' => FALSE));
    }

    if ($this->value == 'Expired') {
      $date = new DateTime();
      $now = $date->getTimestamp();
      $this->query->add_where_expression(0, "invite.expiry < $now");
      $this->query->add_where_expression(0, "invite.canceled = :value", array(':value' => FALSE));
    }


  }


}
