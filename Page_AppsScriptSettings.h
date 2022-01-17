#ifndef PAGE_APPSSCRIPTSETTINGS_H_
#define PAGE_APPSSCRIPTSETTINGS_H_

const char PAGE_AppsScriptSettings[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/"  class="btn btn--s btn--grey">&#9664;</a>&nbsp;&nbsp;<strong>Apps Script Settings</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" >
<tr><td align="right">Apps Script Deployment IDs</td><td></td></tr>
<tr><td align="right">Holidays:</td><td><input type="text" id="hscriptid" name="hscriptid" value=""></td></tr>
<tr><td align="right">Anniversaries:</td><td><input type="text" id="ascriptid" name="ascriptid" value=""></td></tr>
<tr><td align="right">To-dos:</td><td><input type="text" id="escriptid" name="escriptid" value=""></td></tr>
<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--grey" value="Save"></td></tr>
</table>
</form>
<script>
  

window.onload = function ()
{
  load("style.css","css", function() 
  {
    load("microajax.js","js", function() 
    {
        setValues("/admin/appsscript");
    });
  });
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";


void send_Apps_Script_Settings_html()
{
  if (server.args() > 0 )  // Save Settings
  {
    for ( uint8_t i = 0; i < server.args(); i++ ) {
      if (server.argName(i) == "hscriptid") config.HolidaysScriptID =  server.arg(i);
      if (server.argName(i) == "ascriptid") config.AnniversariesScriptID =  server.arg(i);
      if (server.argName(i) == "escriptid") config.TodosScriptID =  server.arg(i);
    }
    WriteConfig();
  }
  server.send_P ( 200, "text/html", PAGE_AppsScriptSettings );
  Serial.println(__FUNCTION__);

}


void send_Apps_Script_Settings_values_html()
{
  String values ="";
  values += "hscriptid|" +  (String) config.HolidaysScriptID + "|input\n";
  values += "ascriptid|" +  (String) config.AnniversariesScriptID + "|input\n";
  values += "escriptid|" +  (String) config.TodosScriptID + "|input\n";
  server.send ( 200, "text/plain", values);
  Serial.println(__FUNCTION__);
  AdminTimeOutCounter=0;
}





#endif
