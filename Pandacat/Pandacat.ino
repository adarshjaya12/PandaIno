#include "wifi.h"
#include "get_ip.h"
#include "rtc_esp32.h"
#include "nimBLE.h"
#include "clock_progress_type.h"
#include "clock_hex_type.h"
#include "clock_date_time_type.h"
#include "clock_custom_12htype.h"
#include "clock_custom_24htype.h"
#include "get_weather.h"

#include <WiFi.h>

void setup() {
  // put your setup code here, to run once:
  wifisetup();
  while(1)
  {
    Serial.println("Waiting for WIFI Connection");
    delay(1000);
    if(WiFi.status()==WL_CONNECTED)
    {
      break;
    }
  }
  Serial.println("WIFI is connected");
  get_ip();
  get_offset();
  get_rtc_time();
  //nimBLE_loop();
  //clock_progress_type_loop();
  //clock_hex_type_loop();
  //clock_dt_type_loop();
  //clock_custom_24htype_loop();
  //clock_custom_12htype_loop();
  get_weatherinfo();
}

void loop() {
  // put your main code here, to run repeatedly:
}
