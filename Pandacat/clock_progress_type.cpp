#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_progress_type.h"
#include <ESP32Time.h>
#include<math.h>
#include "disp_setup.h"
//#include <Fonts/bitocra7.h>


extern ESP32Time rtc;


void clock_progress_type_setup() {

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
    String time= rtc.getTime("%H:%M:%S");
    dma_display->setCursor(8, 12);
    //filling the progress
    struct tm timeinfo = rtc.getTimeStruct();
    int total_sec=timeinfo.tm_hour*3600+timeinfo.tm_min*60+timeinfo.tm_sec;
    int x=(64-round(total_sec/1350));
    dma_display->fillRect(-x, 0, 64, 32, dma_display->color565(255, 0, 0));
    
    dma_display->println(time);
    delay(100);
    dma_display->clearScreen();
  }
  
}

void clock_progress_type_loop() {
  clock_progress_type_setup();
}