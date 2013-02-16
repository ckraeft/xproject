$(document).ready(function() {
    $('table .edittask').click(function() {
	$('#taskeditform').load(this.href + ' #xtasks-form');
	return false;
	});
	$('table .deletetask').click(function() {
	$('#taskeditform').load(this.href + ' #xtasks-confirm-form');
	return false;
	});
	$('table .worklog').click(function() {
	$('#'+this.title).load(this.href + ' #workloglistpage');
	return false;
	});
});
