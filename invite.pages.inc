<?php

/**
 * @file
 * Page callbacks for invite module.
 */

/**
 * Menu callback; display an overview of sent invitations.
 *
 * @param $page
 *   Which invites to list: accepted, pending, or expired.
 */
function invite_user_overview($page, $account) {
  switch ($page) {
    case 'accepted':
      $result = views_embed_view('invite', 'block_1');
      break;
    case 'pending':
      $result = views_embed_view('invite', 'block_2');
      break;
    case 'expired':
      $result = views_embed_view('invite', 'block_3');
      break;
  }
  return $result;
}

/**
 * Menu callback; handle incoming requests for accepting an invite.
 *
 * @param $invite
 *   A (unvalidated) invite object.
 */
function invite_accept($invite) {
  global $user;

  $status = invite_validate($invite);

  if (!$user->uid && $status == INVITE_VALID) {
    $_SESSION[INVITE_SESSION] = $invite->reg_code;
    backdrop_goto(config_get('invite.settings', 'invite_registration_path'));
  }
  else {
    switch ($status) {
      case INVITE_WITHDRAWN:
        backdrop_set_message(t('This invitation has been withdrawn.'));
        break;

      case INVITE_USED:
        backdrop_set_message(t('This invitation has already been used.'), 'error');
        break;

      case INVITE_EXPIRED:
        backdrop_set_message(t('This invitation has expired.'));
        break;
    }
  }

  backdrop_goto();
}

/**
 * Menu callback; resend an expired invite.
 *
 * @param $invite
 *   An invitate object.
 */
function invite_resend($invite) {
  global $user;

  // Inviter must match current user and invitation must have expired.
  if ($invite->uid == $user->uid && $invite->expiry < REQUEST_TIME && $invite->joined == 0 && $invite->canceled == 0) {
    return backdrop_get_form('invite_form', 'page', $invite);
  }

  return MENU_ACCESS_DENIED;
}

/**
 * Theme function; display the invite overview table.
 *
 * @param $items
 *   An array of table rows.
 *
 * @ingroup themeable
 */
function theme_invite_user_overview($variables) {
  $output = '';
  $items = $variables['items'];

  if ($variables['page'] == 'pending') {
    $output .= '
    <div id="invite-reg-link-container" class="messages">
      <a href="" id="invite-reg-link-close">' . t('Hide') . '</a>
      <div id="invite-reg-title"></div>
      <div id="invite-reg-link"></div>
    </div>';
  }

  if (count($items) > 0) {
    $headers = array(t('E-mail'), t('Status'), t('Operations'));
    $output  .= theme('table', array('header' => $headers, 'rows' => $items, 'attributes' => array('id' => 'invite-user-overview')));
    $output .= theme('pager');
  }
  else {
    $output .= t('No invitations available.');
  }

  return $output;
}

/**
 * Menu callback; Retrieve a JSON object containing autocomplete suggestions for existing users.
 */
function invite_user_autocomplete($string = '') {
  $matches = array();
  if ($string) {
    $result = db_select('users')
    	->fields('users', array('name', 'mail'))
    	->condition(
    		db_or()
    		->condition('name', db_like($string) . '%', 'LIKE')
    		->condition('mail', db_like($string) . '%', 'LIKE')
    	  )
    	->range(0, 10)
      ->execute();
    foreach ($result as $account) {
      $matches[$account->name] = check_plain($account->name . ' (' . $account->mail . ')');
    }
  }

  backdrop_json_output($matches);
}
