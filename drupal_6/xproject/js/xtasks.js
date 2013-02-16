$(document).ready(function() {

    $('table .edittask').click(function() {
		if($('#'+this.title).not(':empty')) {
			$('#'+this.title).html('');
        }
        $('#'+this.title).load(this.href + ' #xtasks-form');
		return false;
	});
    
	$('table .deletetask').click(function() {
		if($('#'+this.title).not(':empty')) {
			$('#'+this.title).html('');
        }
        $('#'+this.title).load(this.href + ' #xtasks-confirm-form');
		return false;
	});
    
	$('table .newtask').click(function() {
		if($('#'+this.title).not(':empty')) {
			$('#'+this.title).html('');
        }
        $('#'+this.title).load(this.href + ' #xtasks-form');
		return false;
	});
    
	$('table .worklog').click(function() {
		if($('#'+this.title).not(':empty')) {
			$('#'+this.title).html('');
        }
        $('#'+this.title).load(this.href + ' #workloglistpage');
		return false;
	});
    
	$('.newtasklink').click(function() {
		if($('#taskform').not(':empty')) {
			$('#taskform').html('');
        }
		$('#taskform').load(this.href + ' #xtasks-form');
		return false;
	});
    
	$('.newteamlink').click(function() {
		if($('#team_form').not(':empty')) {
			$('#team_form').html('');
        }
		$('#team_form').load(this.href + ' #xteam-form');
		return false;
	});

    $('table .editteam').click(function() {
		if($('#'+this.title).not(':empty')) {
			$('#'+this.title).html('');
        }
        $('#'+this.title).load(this.href + ' #xteam-form');
		return false;
	});
    
	$('table .removeteam').click(function() {
		if($('#'+this.title).not(':empty')) {
			$('#'+this.title).html('');
        }
        $('#'+this.title).load(this.href + ' #xteam-confirm-form');
		return false;
	});
});

/*
*/



