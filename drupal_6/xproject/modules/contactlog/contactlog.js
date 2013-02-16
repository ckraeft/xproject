
Drupal.behaviors.contactlog = function (context) {
  var parts = new Array("name", "homepage", "mail");
  var cookie = '';
  for (i=0;i<3;i++) {
    cookie = Drupal.contactlog.getCookie('contactlog_info_' + parts[i]);
    if (cookie != '') {
      $("#contactlog-form input[name=" + parts[i] + "]:not(.contactlog-log-processed)", context)
        .val(cookie)
        .addClass('contactlog-log-processed');
    }
  }
};

Drupal.contactlog = {};

Drupal.contactlog.getCookie = function(name) {
  var search = name + '=';
  var returnValue = '';

  if (document.cookie.length > 0) {
    offset = document.cookie.indexOf(search);
    if (offset != -1) {
      offset += search.length;
      var end = document.cookie.indexOf(';', offset);
      if (end == -1) {
        end = document.cookie.length;
      }
      returnValue = decodeURIComponent(document.cookie.substring(offset, end).replace(/\+/g, '%20'));
    }
  }

  return returnValue;
};
