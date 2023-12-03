#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_custom_24htype.h"
#include <ESP32Time.h>
#include "disp_setup.h"


extern ESP32Time rtc;

void clock_custom_24htype_setup() {

  // Display Setup
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(50); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);

  // fix the screen with time
  dma_display->setTextSize(1);     // size 1 == 8 pixels high
  dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  //dma_display->setFont(&Courier9x13);

  dma_display->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display->setTextColor(dma_display->color444(15,15,15));

  while(1)
  {
    String time= rtc.getTime("%H:%M:%S");
    dma_display->setCursor(8, 12);
    dma_display->println(time);
    delay(1000);
    dma_display->clearScreen();
  }
  
}

void clock_custom_24htype_loop() {
  clock_custom_24htype_setup();
}