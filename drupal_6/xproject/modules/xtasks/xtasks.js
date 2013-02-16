/*$(document).ready(function() {
	
 
    $('table .edittask').click(function() {
	
	$('#taskeditform').load(this.href)
	return false;
	});
});
$(document).ready(function() {

 
    $('table .edittask').click(function() {
        loadXMLDoc(this.href); 
		re
});
});

function loadXMLDoc(url)
{
alert(url);
var xmlhttp;
if (window.XMLHttpRequest)
  {// code for IE7+, Firefox, Chrome, Opera, Safari
  xmlhttp=new XMLHttpRequest();
  }
else
  {// code for IE6, IE5
  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
xmlhttp.onreadystatechange=function()
  {
  if (xmlhttp.readyState==4 && xmlhttp.status==200)
    {
    document.getElementById("taskeditform").innerHTML=xmlhttp.responseText;
    }
  }
xmlhttp.open("GET",url,true);
xmlhttp.send();
}*/