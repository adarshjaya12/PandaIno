#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_fuzzy_logic_type.h"
#include <ESP32Time.h>
#include<math.h>
#include "disp_setup.h"
//#include <Fonts/bitocra7.h>


extern ESP32Time rtc;


void fuzzy_logic(int hour, int minute) 
{
  String fuzzy_time;
  int pos;
  String begin = "It's ";

  String f0 = "almost ";
  String f1 = "exactly ";
  String f2 = "around ";

  String b0 = "past ";
  String b1 = "to ";

  String hourList[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve"};
  

  String s1, s2, s3, s4;
  int base = 5;
  String val[] = {"Five", "Ten", "Quarter", "Twenty", "Twenty-Five", "Half"}; 

  int dmin = minute % base;  // To find whether to use 'almost', 'exactly', or 'around'
  if (minute > 30) 
  {
      pos = (60 - minute) / base;  // Position in the String 'val'
  } 
  else 
  {
      pos = minute / base;
  }

  if (dmin == 0) 
  {
      s1 = f1;     // It's exactly
      pos--;
  } 
  else if (dmin <= (base / 2)) 
  {
      s1 = f2;     // It's around
      if (minute < 30) 
      {
          pos--;
      }
  } 
  else 
  {
      s1 = f0;   // It's almost
      if (minute > 30) 
      {
          pos--;
      }
  }

  s2 = val[pos];
  if (minute <= (base / 2)) 
  {  // Case like "It's around/exactly Ten"
      s2 = s3 = "";
      s4 = hourList[hour - 12 -1];  // Adjusting for 0-indexing
  }
  else if (minute >= 60 - (base / 2)) 
  {  // Case like "It's almost Ten"
      s2 = s3 = "";
      s4 = hourList[hour-12];
  }
  else
  {
    if(minute>30)
    {
      s3=b1; //to
      s4=hourList[hour-12];
    } 
    else
    {
      s3=b0; //past
      s4=hourList[hour-12-1];
    }
  }
  fuzzy_time=String(begin)+String(s1)+String(s2)+String(s3)+String(s4);
  Serial.println(fuzzy_time);
}

void clock_fuzzy_logic_type_setup() 
{
  int tm_hour, tm_min;

  // Display Setup
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  
  dma_display->begin();
  dma_display->setBrightness8(10); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);

  // fix the screen with time
  dma_display->setTextSize(1);     // size 1 == 8 pixels high
  dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves  

  dma_display->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display->setTextColor(dma_display->color444(15,15,15));

  while(1)
  {
    Serial.println(rtc.getTime("%H:%M:%S"));
    tm_hour= rtc.getTime("%H").toInt();
    tm_min= rtc.getTime("%M").toInt();
    fuzzy_logic(tm_hour,tm_min);
    delay(1000);
  }
  
}

void clock_fuzzy_logic_type_loop() 
{
  clock_fuzzy_logic_type_setup();
}