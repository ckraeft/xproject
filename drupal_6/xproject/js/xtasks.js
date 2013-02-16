$(document).ready(function() {
    $('table .edittask').click(function() {
		if($('#'+this.title).is(':empty')) {
			$('#'+this.title).load(this.href + ' #xtasks-form');
		} else {
			$('#'+this.title).html('');
		}
		return false;
	});
	$('table .deletetask').click(function() {
		if($('#'+this.title).is(':empty')) {
			$('#'+this.title).load(this.href + ' #xtasks-confirm-form');
		} else {
			$('#'+this.title).html('');
		}
		return false;
	});
	$('table .worklog').click(function() {
		if($('#'+this.title).is(':empty')) {
			$('#'+this.title).load(this.href + ' #workloglistpage');
		} else {
			$('#'+this.title).html('');
		}
		return false;
	});
});
