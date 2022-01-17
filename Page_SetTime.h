#ifndef PAGE_SETTIME_H
#define PAGE_SETTIME_H

const char PAGE_SetTime[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/"  class="btn btn--s btn--grey">&#9664;</a>&nbsp;&nbsp;<strong>Manual time setting</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" >
<tr><td align="right">Year:</td><td><input type="text" id="set_year" name="set_year" size="5" maxlength="4" value=""></td></tr>
<tr><td align="right">Month:</td><td><input type="text" id="set_month" name="set_month" size="3" maxlength="2" value=""></td></tr>
<tr><td align="right">Day:</td><td><input type="text" id="set_day" name="set_day" size="3" maxlength="2" value=""></td></tr>
<tr><td align="right">Hour:</td><td><input type="text" id="set_hour" name="set_hour" size="3" maxlength="2" value=""></td></tr>
<tr><td align="right">Minute:</td><td><input type="text" id="set_minute" name="set_minute" size="3" maxlength="2" value=""></td></tr>
<tr><td align="right">Second:</td><td><input type="text" id="set_second" name="set_second" size="3" maxlength="2" value=""></td></tr>
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
        setValues("/admin/timevalues");
    });
  });
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";

void send_Time_Set_html()
{
  if (server.args() > 0 )  // Save Settings
  {
    for ( uint8_t i = 0; i < server.args(); i++ ) {
      if (server.argName(i) == "set_year") DateTime.year = server.arg(i).toInt();
      if (server.argName(i) == "set_month") DateTime.month = server.arg(i).toInt();
      if (server.argName(i) == "set_day") DateTime.day = server.arg(i).toInt();
      if (server.argName(i) == "set_hour") DateTime.hour = server.arg(i).toInt();
      if (server.argName(i) == "set_minute") DateTime.minute = server.arg(i).toInt();
      if (server.argName(i) == "set_second") DateTime.second = server.arg(i).toInt();
    }
    manual_time_set = true;
    UnixTimestamp = ConvertDate(DateTime.year, DateTime.month, DateTime.day, DateTime.hour, DateTime.minute, DateTime.second);
    ISRsecondTick();
  }
  server.send_P ( 200, "text/html", PAGE_SetTime );
  Serial.println(__FUNCTION__);

}

void send_Time_Set_values_html()
{

  String values ="";
  values += "set_year|" + (String) DateTime.year + "|input\n";
  values += "set_month|" + (String) DateTime.month + "|input\n";
  values += "set_day|" + (String) DateTime.day + "|input\n";
  values += "set_hour|" + (String) DateTime.hour + "|input\n";
  values += "set_minute|" +  (String) DateTime.minute + "|input\n";
  values += "set_second|" +  (String) DateTime.second + "|input\n";
  server.send ( 200, "text/plain", values);
  Serial.println(__FUNCTION__);
  AdminTimeOutCounter=0;
}

#endif
