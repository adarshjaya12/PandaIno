
#include "nimBLE.h"
#include "clock_progress_type.h"
#include "clock_hex_type.h"
#include "clock_date_time_type.h"
#include "clock_custom_12htype.h"
#include "clock_custom_24htype.h"
#include "clock_fuzzy_logic_type.h"
#include "get_weather.h"
#include "get_news.h"
#include "startup.h"

#include "text_test.h"



void setup() 
{
  bool status;
  // put your setup code here, to run once:
  status=startup();
  if (status==false)
  {
    Serial.println("exiting the program");
  }
  if (status==true)
  {
    Serial.println("###################################################\nWIFI connected \nIP data obtained \nOffset data obtained\nRTC setup\nWeather data obtained\n###################################################");
    //nimBLE_loop();  
  }
  clock_fuzzy_logic_type_loop();
  //clock_progress_type_loop();
  //clock_hex_type_loop();
  //clock_dt_type_loop();
  //clock_custom_24htype_loop();
  //clock_custom_12htype_loop();
  //get_weatherinfo();
  //text_test();
  //get_news();
}

void loop() {
  // put your main code here, to run repeatedly:
}
