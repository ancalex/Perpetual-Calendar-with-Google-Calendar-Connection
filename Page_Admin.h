#ifndef PAGE_ADMIN_H
#define PAGE_ADMIN_H

//<a href="color.html"   style="width:250px"  class="btn btn--m btn--grey" >Colour settings</a><br>
//
//  HTML PAGE
//

const char PAGE_AdminMainPage[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<body>
<strong>Perpetual Calendar</strong>
<hr>
<a href="config.html" style="width:250px" class="btn btn--m btn--grey" >Network Configuration</a><br>
<a href="info.html" style="width:250px"  class="btn btn--m btn--grey" >Network Information</a><br>
<a href="ntp.html" style="width:250px"  class="btn btn--m btn--grey" >NTP Settings</a><br>
<a href="appsscript.html" style="width:250px"  class="btn btn--m btn--grey" >Apps Script Settings</a><br>
<a href="time.html" style="width:250px"  class="btn btn--m btn--grey" >Manual time setting</a><br>
</body>
<script>
window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				// Do something after load...
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}

</script>

)=====";

#endif

