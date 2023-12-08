#include "WiFiType.h"
#include <Arduino.h>
#include <time.h>
#include <WiFi.h>
#include <ESP32Time.h>
#include "rtc_esp32.h"
#include "global.h"

ESP32Time rtc;
const char* ntp_server="pool.ntp.org";

void print_local_time()
{
  Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));
  delay(1000);
}

bool get_rtc_time()
{   
  bool rtc_status=false;
  while(1)
  {
    if(WiFi.status()==WL_CONNECTED)
    {
      break;
    }
  }
  if(WiFi.status()==WL_CONNECTED)
  {
    Serial.println("Setting up RTC");
    //Getting the time based on RAW Offset and DT Offset
    configTime(19800, 0, ntp_server);

    //print_local_time(); Printing RTC for testing purpose.
    Serial.println("get_rtc_status function executed");
    Serial.println("RTC timer set");
    return rtc_status=true;
  }
  else
  {
    Serial.println("WiFi is not connected");
    Serial.println("get_rtc_status function not executed");
    Serial.println("RTC timer cannot be set");
    return rtc_status=false;
  }
}