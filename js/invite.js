/**
 * @file
 * Invite module javascripts.
 */
(function ($) {

Backdrop.behaviors.invite_user = {
  attach: function (context) {
    $('.invite-reg-link').click(function(e) {
      $('#invite-reg-link-container #invite-reg-title').html($(this).attr('title') + ':');
      $('#invite-reg-link-container #invite-reg-link').html($(this).attr('href'));
      $('#invite-reg-link-container').fadeIn();
      e.preventDefault();
    });

    $('#invite-reg-link-close').click(function(e) {
      $('#invite-reg-link-container').fadeOut();
      e.preventDefault();
    });

  }
};

})(jQuery);
