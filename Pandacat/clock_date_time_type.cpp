#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_date_time_type.h"
#include <ESP32Time.h>
#include "disp_setup.h"
//#include <Fonts/bitocra7.h>


#define PER_TEXT_SIZE 5
#define PANEL_WIDTH 64

extern ESP32Time rtc;

void clock_dt_type_setup() {

  // Display Setup
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(50); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);

  
  // fix the screen with time
  dma_display->setTextSize(1);     // size 1 == 8 pixels high
  dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  //dma_display->setFont(&bitocra7);
  dma_display->setTextColor(dma_display->color444(15,15,15));

  String min;
  String hr;
  String date;
  while(1)
  {
    struct tm timeinfo = rtc.getTimeStruct();
    String time;
    String month;
    String day=rtc.getTime("%A");
    int textWidth = (day.length()*PER_TEXT_SIZE+ (day.length()-1));
    
    switch ((timeinfo.tm_mon+1)) 
    {
      case 1:
        month="JAN";
        break;
      case 2:
        month="FEB";
        break;
      case 3:
        month="MAR";
        break;
      case 4:
        month="APR";
        break;
      case 5:
        month="MAY";
        break;
      case 6:
        month="JUN";
        break;
      case 7:
        month="JUL";
        break;
      case 8:
        month="AUG";
        break;
      case 9:
        month="SEP";
        break;
      case 10:
        month="OCT";
        break;
      case 11:
        month="NOV";
        break;
      case 12:
        month="DEC";
        break;
      default:
        month="ERR";
        break;
    }
    // Calculate the position to center the text
    int x1 = (PANEL_WIDTH - textWidth) / 2;
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
    dma_display->setCursor(8, 2);
    dma_display->println(time);
    dma_display->setCursor(x1,12);
    dma_display->println(day);
    dma_display->setCursor(3,23);
    if(timeinfo.tm_mday<10)
    {
      date="0"+String(timeinfo.tm_mday);
    }
    else
    {
      date=String(timeinfo.tm_mday);
    }
    dma_display->println(date);
    dma_display->setCursor(17,23);
    dma_display->println(month);
    dma_display->setCursor(38,23);
    dma_display->println(rtc.getTime("%Y"));
    delay(1000);
    dma_display->clearScreen();

  }
  
}

void clock_dt_type_loop() {
  clock_dt_type_setup();
}