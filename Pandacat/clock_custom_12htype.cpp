#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_custom_12htype.h"
#include <ESP32Time.h>
#include "disp_setup.h"


extern ESP32Time rtc;

void clock_custom_12htype_setup() {

  // Display Setup
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(50); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);

  
  // fix the screen with time
  dma_display->setTextSize(1);     // size 1 == 8 pixels high
  dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  dma_display->setTextColor(dma_display->color444(15,15,15));
  String hr;
  String min;
  while(1)
  {
    struct tm timeinfo = rtc.getTimeStruct();
    String time;
    if(timeinfo.tm_min<10)
    {
      min="0"+String(timeinfo.tm_min);
    }
    else
    {
      min=String(timeinfo.tm_min);
    }
    if(timeinfo.tm_hour<10)
    {
      hr="0"+String(timeinfo.tm_hour);
    }
    else if(timeinfo.tm_hour>10 && timeinfo.tm_hour<=12)
    {
      hr=String(timeinfo.tm_hour);
    }
    else if(timeinfo.tm_hour>12 && timeinfo.tm_hour<22)
    {
      hr="0"+String(timeinfo.tm_hour-12);
    }
    else if(timeinfo.tm_hour>=22 && timeinfo.tm_hour<24)
    {
      hr=String(timeinfo.tm_hour-12);
    }
    if(int(timeinfo.tm_hour)>=12)
    {
      time=String(hr)+" "+String(min)+" PM";
    }
    if(timeinfo.tm_hour<12)
    {
      time=String(hr)+" "+String(min)+" AM";
    }
    dma_display->setCursor(8, 13);
    dma_display->println(time);
    delay(1000);
    dma_display->clearScreen();

  }
  
}


void clock_custom_12htype_loop() 
{
  clock_custom_12htype_setup();
}