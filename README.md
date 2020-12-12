
Description
===========
Invite is an invitation system that lets you and your Backdrop site members invite more people to join the site. Invitations are important to encourage expansion of your network and to provide an exponential growth of community interest. This module provides an “Invite a Friend” feature that allows your users to send and track invitations.

Requirements
============
Token module https://github.com/backdrop-contrib/token

Installation
============

1. Add to and enable the module on your Backdrop website per one of two methods
described on https://backdropcms.org/user-guide/modules.

2. Give some roles permission to send invites on the Permissions page (admin/config/people/permissions). The following permissions can be controlled:

   Administer invitations - Allows users to access the administrative overview
     and settings pages, and to see other people's invitations.

   Send mass invitations - Allows users to send an invitation to multiple
     recipients (this was formerly a setting known as "limit per turn").

   Track invitations - Gives users access to the user overview pages and
     associated actions (withdraw etc). Useful to hide overviews from anonymous
     users.

   Withdraw own invitations - Allows users to withdraw invitations. If an
     invitation has been withdrawn, it cannot be used to join the site
     and it does not count against the sender's invitation limit.

   Withdraw own accepted invitations - This will allow your users to delete
     accepted invitations. Disable it to prevent users from deleting
     their account to be re-invited. With the help of the Cancel User Accounts
     module it is possible to terminate user accounts by withdrawing an
     invitation.

3. Invite adds a new registration mode called 'Invitees only' to the Account
   settings page (admin/config/people/settings), which allows you to maintain a
   semi-private site.

4. Configure the module at Configuration > Invite
   (admin/config/people/invite). For an explanation of the configuration
   settings see below.


Configuration
============

General settings
----------------

* Default target role
  Allows you to specify the role invited users will be added to when they
  register, regardless of who invited them.

* Invitation expiry
  Specify how long sent invitations are valid (in days). After an invitation
  expires the registration link becomes invalid.

* Path to registration page
  Specifies where the users will be redirected when they click the invitation
  link.

Role settings (separate sections for each role)
------------------------------

* Target role
  Allows you to specify an additional role invited users will be added to if
  their inviter has a specific role.

* Invitation limit
  Allows you to limit the total number of invitations each role can send.

E-mail settings
---------------

* Subject
  The default subject of the invitation e-mail.

* Editable subject
  Whether the user should be able to customize the subject.

* Mail template
  The e-mail body.

* From/Reply-To e-mail address
  Choose whether to send the e-mail on behalf of the user or in the name of the
  site.

* Manually override From/Reply-To e-mail address (Advanced settings)
  Allows to override the sender and reply-to addresses used in all e-mails.
  Make sure the domain matches that of your SMTP server, or your e-mails will
  likely be marked as spam.

Invite page customization
-----------------

* Invite page title
  Allows you to change the title of the invite page and link.

Usage
============

Sent invitations show up in one of three states: accepted, pending, expired, or
deleted.

* Accepted: Shows that the person you have invited has accepted the invitation
  to join the site.
* Pending: The invitation has been sent, but the invitee has since not accepted
  the invitation.
* Expired: The invitation has not been used to register within the expiration
  period.
* Deleted: The user account has been blocked.

At any time, pending or expired invitations may be withdrawn. Accepted
invitations may only be withdrawn if the configuration allows you to.


Invite API
============
See invite.api.php.

Credits
============
Initially created and maintained for Drupal by David Hill (tatonca) and Stefan M.
Kudwien (https://github.com/smk).

Ported to Backdrop by Alan Mels (https://github.com/alanmels) of AltaGrade.com -
a Backdrop specific web, cloud and dedicated hosting provider.
