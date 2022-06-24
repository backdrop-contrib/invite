<?php

/**
* Implements hook_views_data().
*/
function invite_views_data() {
  $data = array();

  $data['invite']['table']['group'] = t('Invite');

  $data['invite']['table']['base'] = array(
    'title' => t('Invite'),
    'help' => t('Contains Invite records we want to expose to Views.'),
  );

  $data['invite']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // The Invite ID field
  $data['invite']['iid'] = array(
    'title' => t('Invite ID'),
    'help' => t('The invite record ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

// The Registration code field
  $data['invite']['reg_code'] = array(
    'title' => t('Registration code'),
    'help' => t('The registration code name.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );


// The E-mail address field
  $data['invite']['email'] = array(
    'title' => t('E-mail address'),
    'help' => t('The e-mail address record.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );


  // The Inviter ID field
  $data['invite']['uid'] = array(
    'title' => t('Inviter'),
    'help' => t('The inviter user ID record.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Inviter'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'numeric' => TRUE,
      'validate type' => 'uid',
    ),
  );

  // The Invitee ID field
  $data['invite']['invitee'] = array(
    'title' => t('Invitee'),
    'help' => t('The invitee record ID.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'invitee',
      'handler' => 'views_handler_relationship',
      'label' => t('Invitee'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'numeric' => TRUE,
      'validate type' => 'uid',
    ),
  );

  // The Created field
  $data['invite']['created'] = array(
    'title' => t('Created'),
    'help' => t('The record created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // The Expiry field
  $data['invite']['expiry'] = array(
    'title' => t('Expiry'),
    'help' => t('The record expiry.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // The Joined field
  $data['invite']['joined'] = array(
    'title' => t('Joined'),
    'help' => t('The record joined.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // The Canceled field
  $data['invite']['canceled'] = array(
    'title' => t('Canceled'),
    'help' => t('The canceled record.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  // The Resent field
  $data['invite']['resent'] = array(
    'title' => t('Resent'),
    'help' => t('The resent record.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  // The accept link
  $data['invite']['invite_accept_link'] = array(
    'title' => t('Invite accept link'),
    'help' => t('Provide a link to accept invitation.'),
    'field' => array(
      'handler' => 'views_handler_accept_link',
    ),
  );

  // The withdraw link
  $data['invite']['invite_withdraw_link'] = array(
    'title' => t('Invite withdraw link'),
    'help' => t('Provide a link to withdraw invitation.'),
    'field' => array(
      'handler' => 'views_handler_withdraw_link',
    ),
  );

  // The resend link
  $data['invite']['invite_resend_link'] = array(
    'title' => t('Invite resend link'),
    'help' => t('Provide a link to resend invitation.'),
    'field' => array(
      'handler' => 'views_handler_resend_link',
    ),
  );

  // The status field
  $data['invite']['invite_status'] = array(
    'title' => t('Invite status'),
    'help' => t('Provide a status field.'),
    'field' => array(
      'handler' => 'views_handler_status',
    ),
    'filter' => array(
      'handler' => 'views_handler_status_filter',
    ),
  );

  return $data;
}
