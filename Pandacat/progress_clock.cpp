#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"progress_clock.h"
#include <ESP32Time.h>
#include<math.h>

#define R1_PIN 11
#define G1_PIN 12
#define B1_PIN 13
#define R2_PIN 14
#define G2_PIN 15
#define B2_PIN 16
#define A_PIN 18
#define B_PIN 33
#define C_PIN 34
#define D_PIN 35
#define E_PIN 17 // required for 1/32 scan panels, like 64x64px. Any available pin would do, i.e. IO32
#define LAT_PIN 36
#define OE_PIN 38
#define CLK_PIN 37


HUB75_I2S_CFG::i2s_pins _pins_progress={R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
HUB75_I2S_CFG mxconfig_progress(
	64, // Module width
	64, // Module height
	1, // chain length
	_pins_progress // pin mapping
);


//MatrixPanel_I2S_DMA dma_display;
MatrixPanel_I2S_DMA *dma_display_progress = nullptr;


//Setting up the color values
uint16_t myBLACK1 = dma_display_progress->color565(0,0,0);

extern ESP32Time rtc;


void fill_progress()
{
  struct tm timeinfo = rtc.getTimeStruct();
  int total_sec=timeinfo.tm_hour*3600+timeinfo.tm_min*60+timeinfo.tm_sec;
  int x=(64-round(total_sec/1350));
  dma_display_progress->fillRect(-x, 0, 64, 32, dma_display_progress->color565(255, 0, 0));
}


void progress_clock_setup() {

  // Display Setup
  dma_display_progress = new MatrixPanel_I2S_DMA(mxconfig_progress);
  
  dma_display_progress->begin();
  dma_display_progress->setBrightness8(10); //0-255
  dma_display_progress->clearScreen();
  dma_display_progress->fillScreen(myBLACK1);

  // fix the screen with time
  dma_display_progress->setTextSize(1);     // size 1 == 8 pixels high
  dma_display_progress->setTextWrap(false); // Don't wrap at end of line - will do ourselves  

  dma_display_progress->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display_progress->setTextColor(dma_display_progress->color444(15,15,15));

  while(1)
  {
    String time= rtc.getTime("%H:%M:%S");
    dma_display_progress->setCursor(8, 12);
    fill_progress();
    dma_display_progress->println(time);
    delay(100);
    dma_display_progress->clearScreen();
  }
  
}

void progress_clock_loop() {
  Serial.println("Inside Disp loop");
  progress_clock_setup();
}