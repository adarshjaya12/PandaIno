#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_custom_12htype.h"
#include <ESP32Time.h>
#include "disp_setup.h"
#include "global.h"
//#include <Fonts/DeliriumNcv_Vm5e6pt7b.h>

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
  //dma_display->setFont(&DeliriumNcv_Vm5e6pt7b);
  dma_display->setTextColor(dma_display->color444(15,15,15));
  String hr;
  String min;
  String time;
  int tm_hour;
  int tm_min;
  while(1)
  {
    tm_hour= rtc.getTime("%H").toInt();
    tm_min= rtc.getTime("%M").toInt();
    /*
    if(IS_DAY==0)
    {

    }
    */
    if(tm_min<10)
    {
      min="0"+String(tm_min);
    }
    else
    {
      min=String(tm_min);
    }
    if(tm_hour<10)
    {
      hr="0"+String(tm_hour);
    }
    else if(tm_hour>=10 && tm_hour<=12)
    { 
      hr=String(tm_hour);
    }
    else if(tm_hour>12 && tm_hour<22)
    {
      hr="0"+String(tm_hour-12);
    }
    else if(tm_hour>=22 && tm_hour<24)
    {
      hr=String(tm_hour-12);
    }
    if(int(tm_hour)>=12)
    {
      time=String(hr)+" "+String(min)+" PM";
    }
    if(tm_hour<12)
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