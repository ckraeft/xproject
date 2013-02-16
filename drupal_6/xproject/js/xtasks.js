$(document).ready(function() { 
/* Drupal.behaviors.xproject = function (context) { // use if document.ready() fails because Drupal hijacks it */

    $('table .edittask').click(function() {
        $('#'+this.title).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-form');
        Drupal.behaviors.collapse($('#'+this.title));
		return false;
	});
    
	$('table .deletetask').click(function() {
        $('#'+this.title).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-confirm-form');
		return false;
	});
    
	$('table .newtask').click(function() {
        $('#'+this.title).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-form');
		return false;
	});
    
	$('table .worklog').click(function() {
        $('#'+this.title).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #workloglistpage');
		return false;
	});
    
	$('.newtasklink').click(function() {
		$('#taskform').html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-form');
		return false;
	});
    
	$('.newteamlink').click(function() {
		$('#team_form').html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xteam-form');
		return false;
	});

    $('table .editteam').click(function() {
        $('#team_form').html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xteam-form');
		return false;
	});
    
	$('table .removeteam').click(function() {
        $('#team_form').html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xteam-confirm-form');
		return false;
	});
    
    // reload handlers for ajax inserted page/form content
    $(document).ajaxStop(function() {
//        Drupal.behaviors.collapse();
        Drupal.attachBehaviors($('html'));
    });
});

/*
*/



