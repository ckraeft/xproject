$(document).ready(function() { 
/* Drupal.behaviors.xproject = function (context) { // use if document.ready() fails because Drupal hijacks it */

    $('table .edittask').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-form');
        Drupal.behaviors.collapse($('#'+this.title));
		return false;
	});
    
	$('table .deletetask').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-confirm-form');
		return false;
	});
    
	$('table .tasklink').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #taskDetailsPage');
		return false;
	});
    
	$('table .newtask').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-form');
		return false;
	});
    
	$('table .worklog').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #workloglistpage');
        
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
      
	$('.xworklog_delete').click(function() {
		$('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xworklog-confirm-form');
		return false;
	});
    
          
    var subtask_settings;
    $('table .btn_task_expand').click(function() {
        var target_class = $(this).attr('rel');
        var current_subtasks_hidden = $('.'+target_class).css('display');
        if(current_subtasks_hidden == 'none') {
            $('tr.'+target_class).show();
        } else {
            $('tr.'+target_class).hide();
        }
    });
    
    // reload handlers for ajax inserted page/form content
    $(document).ajaxStop(function() {
//        Drupal.behaviors.collapse();
        Drupal.attachBehaviors($('html'));
        $('#taskDetailsPage').append('<input class="ajax-form-cancel" type="button" value="Close" />');
        $('.ajax-form-cancel').click(function() {
            $(this).parents('.worklogformcatcher').empty();
            return false;
        });
    
        $('input#edit-hours').change(function() {
            var hours_remaining = $('input#edit-hours-remaining').val();
            var hours_spent = $(this).val();
            if(hours_remaining == 0) {
                $('#edit-hours-remaining-wrapper').append('<span class="xtask_form_notice">auto-updated</span>');
            }
            if(parseFloat(hours_spent) >= parseFloat(hours_remaining)) {
                hours_remaining = 0;
            } else {
                hours_remaining = hours_remaining - hours_spent;
            }
            $('input#edit-hours-remaining').val(hours_remaining);
        });
        
    });
});

function confirmBulkSubmit()
{
    var agree=confirm("Are you sure you wish to perform this bulk action?");
    if (agree)
    	return true ;
    else
    	return false ;
}
/*
*/



