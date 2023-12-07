#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"text_test.h"
#include "disp_setup.h"
#include <Fonts/DSEG7_Classic_Mini_Bold_20.h>


void text_test() 
{

  // Display Setup
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(50); //0-255
  dma_display->clearScreen();
  dma_display->fillScreen(myBLACK);

  
  // fix the screen with time
  dma_display->setTextSize(1);     // size 1 == 8 pixels high
  dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  dma_display->setFont(&DSEG7_Classic_Mini_Bold_20);
  dma_display->setTextColor(dma_display->color444(15,15,15));
  
  dma_display->setCursor(-1,26);
  dma_display->println("223456");
  //dma_display->println("TEST TEXT");
  //dma_display->println("test test");
  
}