#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_hex_type.h"
#include <ESP32Time.h>
#include "disp_setup.h"
//#include <Fonts/bitocra7.h>

extern ESP32Time rtc;

void clock_hex_type_setup() {

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

  dma_display->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display->setTextColor(dma_display->color565(15, 82, 186));

  while(1)
  {
    String time= rtc.getTime("%H:%M:%S");
    dma_display->setCursor(8, 12);
    dma_display ->fillScreenRGB888(139,128,0);
    dma_display->println(time);
    delay(1000);
    dma_display->clearScreen();
  }
  
}

void clock_hex_type_loop() {
  clock_hex_type_setup();
}