$(document).ready(function() { 
/* Drupal.behaviors.xproject = function (context) { // use if document.ready() fails because Drupal hijacks it */

    $('#xtasks-bulkupdate-form').append('&nbsp;(<a href="javascript:void()" id="xtasks_checkall">Check All</a>&nbsp;|&nbsp;<a href="javascript:void()" id="xtasks_uncheckall">Uncheck All</a>)');

    $('#xtasks-bulkupdate-form #xtasks_checkall').click(function() {
        $('table.xtask_list input[type=checkbox]').attr('checked', 'checked')
    });
    $('#xtasks-bulkupdate-form #xtasks_uncheckall').click(function() {
        $('table.xtask_list input[type=checkbox]').removeAttr('checked')
    });
    
    $('#xcontact_merge_footer input.xcontact_default_select').click(function() {
        $('#xcontact-merge input[value='+$(this).val()+']').attr('checked', true);
    });
    
    $('table.xtask_list .edittask').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-form');
        Drupal.behaviors.collapse($('#'+this.title));
		return false;
	});
    
	$('table.xtask_list .deletetask').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-confirm-form');
		return false;
	});
    
	$('table.xtask_list .tasklink').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #taskDetailsPage');
		return false;
	});
    
	$('table.xtask_list .newtask').click(function() {
        $('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xtasks-form');
		return false;
	});
    
	$('table.xtask_list .worklog').click(function() {
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

    $('table.xtask_list .editteam').click(function() {
        $('#team_form').html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xteam-form');
		return false;
	});
    
	$('table.xtask_list .removeteam').click(function() {
        $('#team_form').html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xteam-confirm-form');
		return false;
	});
      
	$('.xworklog_delete').click(function() {
		$('#'+$(this).attr('rel')).html('<strong>Loading form, please wait...</strong>').load(this.href + ' #xworklog-confirm-form');
		return false;
	});
    
    $('form#task_filter input').click(function() {
        $('form#task_filter input#btnFilter').trigger('click');
    });
    
          
    var subtask_settings;
    $('table.xtask_list .btn_task_expand').click(function() {
        var target_class = $(this).attr('rel');
        var current_subtasks_hidden = $('.'+target_class).css('display');
        if(current_subtasks_hidden == 'none') {
            $('tr.'+target_class).show();
        } else {
            $('tr.'+target_class).hide();
        }
    });
    
    $('.ajax-form-cancel').click(function() {
        return false;
    });
    
    // reload handlers for ajax inserted page/form content
    $(document).ajaxStop(function() {
//        Drupal.behaviors.collapse();
        Drupal.attachBehaviors($('html'));
/*
        $('#taskDetailsPage').each(function(index) {
            $(this).append('<input class="ajax-form-cancel" type="button" value="Close" />');
        });
*/
        $('.ajax-form-cancel').click(function() {
            $(this).parents('.worklogformcatcher').empty();
            $(this).parents('#taskform').empty();
            return false;
        });
    
        $('input#edit-hours-planned').each(function() {
            var hours_planned = $(this).val();
            $(this).data('value', hours_planned);
        });
    
        $('input#edit-hours-planned').change(function() {
            // cache previous/orig value
            var prev_hours_planned = $(this).data('value');
            var hours_planned = $(this).val();
            $(this).data('value', hours_planned);
            
            var hours_remaining = $(this).parents('form').find('input#edit-hours-remaining').val();
            
            if(prev_hours_planned == false) prev_hours_planned = 0;
            if(hours_remaining == false) hours_remaining = 0;
            
            hours_remaining = parseFloat(hours_remaining) - parseFloat(prev_hours_planned) + parseFloat(hours_planned);

            $('.xtask_form_notice').remove();
            $(this).parents('form').find('#edit-hours-remaining-wrapper').append('<span class="xtask_form_notice">auto-updated</span>');
        
            $(this).parents('form').find('input#edit-hours-remaining').val(hours_remaining);
        });
    
        $('input#edit-hours').change(function() {
            var hours_remaining = $(this).parents('form').find('input#edit-hours-remaining').val();
            if(hours_remaining == false) hours_remaining = 0;
            var hours_spent = $(this).val();
            if(hours_remaining == 0) {
                $(this).parents('form').find('#edit-hours-remaining-wrapper').append('<span class="xtask_form_notice">auto-updated</span>');
            }
            if(parseFloat(hours_spent) >= parseFloat(hours_remaining)) {
                hours_remaining = 0;
            } else {
                hours_remaining = hours_remaining - hours_spent;
            }
            $(this).parents('form').find('input#edit-hours-remaining').val(hours_remaining);
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



