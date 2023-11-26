#include <Arduino.h>
#include "wifi.h"
#include "get_ip.h"
#include "rtc_esp32.h"
//#include "ble_adv.h"
#include "nimBLE.h"



void setup() {
  // put your setup code here, to run once:
  wifisetup();
  get_ip();
  get_offset();
  get_rtc_time();
  //ble_loop();
  nimBLE_loop();
}

void loop() {
  // put your main code here, to run repeatedly:
}
