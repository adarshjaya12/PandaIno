#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include "disp_setup.h"
#include <WiFi.h>
#include "wifi.h"
#include "get_ip.h"
#include "rtc_esp32.h"
#include "get_weather.h"

// In start up you will be doing the following
// display a logo
// connecting the BLE
// connecting the wifi
// getting the IP info, offset data
// setting up the RTC
// getting the weather data


void display_logo()
{
  dma_display->begin();
  dma_display->setBrightness8(50); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);

  // fix the screen with time
  dma_display->setTextSize(1);     // size 1 == 8 pixels high
  dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  //dma_display->setFont(&Courier9x13);

  dma_display->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display->setTextColor(dma_display->color565(102,51,153));
  dma_display->println("PIXBYTE");
}

void display_wifi_connected_logo()
{
  dma_display->begin();
  dma_display->setBrightness8(50); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);

  // fix the screen with time
  dma_display->setTextSize(1);     // size 1 == 8 pixels high
  dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  //dma_display->setFont(&Courier9x13);

  dma_display->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display->setTextColor(dma_display->color565(80, 200, 120));
  dma_display->println("WIFI");
}


void display_wifi_not_connected_logo()
{
  dma_display->begin();
  dma_display->setBrightness8(50); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);

  // fix the screen with time
  dma_display->setTextSize(1);     // size 1 == 8 pixels high
  dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  //dma_display->setFont(&Courier9x13);

  dma_display->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display->setTextColor(dma_display->color565(210, 43, 43));
  dma_display->println("WIFI");
}

bool startup() 
{
  bool get_ip_status=false, get_offset_status=false, get_weather_status=false, get_rtc_status=false, wifi_status=false;
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);

  // display logo
  //display_logo();
  
  // setting up the wifi
  wifi_status=wifisetup();
  Serial.println("hi");
  if(wifi_status==false)
  {
    Serial.println("Couldnt connect to internet");
    return false;
  }
  /*
  while(1)
  {
    Serial.println("*");
    if(WiFi.status()==WL_CONNECTED)
    {
      Serial.println("Wifi connected in Startup");
      break;
    }
  }
  */
  while(1)
  {
    display_wifi_not_connected_logo();
    delay(1000);
    if(WiFi.status()==WL_CONNECTED)
    {
    display_wifi_connected_logo();
    // getting the ip address and assigining to the global variable
    get_ip_status=get_ip();
    // getting the raw and dt offset to set the rtc time
    get_offset_status=get_offset();
    // setting up the rtc timer
    get_rtc_status=get_rtc_time();
    // getting the weather info
    get_weather_status=get_weatherinfo();
    // holding for 5 second
    delay(5000);
    break;
    }
    Serial.println("Wifi not connected");
  }
  if(WiFi.status()==WL_CONNECTED && get_ip_status && get_offset_status && get_rtc_status && get_weather_status )
  {
    // all the functions executed well
    Serial.println("All startup functions exectued");
    return true;
  }
  else
  {
    return false;
  }
}
