#include "wifi.h"
#include "get_ip.h"
#include "rtc_esp32.h"
#include "nimBLE.h"
#include "disp_time.h"
#include "progress_clock.h"
#include "clock_hex_type.h"
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
  //disp_loop();
  //progress_clock_loop();
  clock_hex_type_loop();
}

void loop() {
  // put your main code here, to run repeatedly:
}
