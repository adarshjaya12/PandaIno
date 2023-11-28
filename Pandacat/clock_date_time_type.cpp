#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_date_time_type.h"
#include <ESP32Time.h>
//#include <Fonts/Courier9x13.h>

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


HUB75_I2S_CFG::i2s_pins _pins_dt={R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
HUB75_I2S_CFG mxconfig_dt(
	64, // Module width
	64, // Module height
	1, // chain length
	_pins_dt // pin mapping
);


//MatrixPanel_I2S_DMA dma_display_dt;
MatrixPanel_I2S_DMA *dma_display_dt = nullptr;

//Setting up the color values
uint16_t myWHITE = dma_display_dt->color565(255, 255, 255);
uint16_t myBLACK = dma_display_dt->color565(0,0,0);


extern ESP32Time rtc;

void disp_setup() {

  // Display Setup
  dma_display_dt = new MatrixPanel_I2S_DMA(mxconfig_dt);
  dma_display_dt->begin();
  dma_display_dt->setBrightness8(50); //0-255
  dma_display_dt->clearScreen();
  dma_display_dt->fillScreen(myBLACK);

  // fix the screen with time
  dma_display_dt->setTextSize(1);     // size 1 == 8 pixels high
  dma_display_dt->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  //dma_display_dt->setFont(&Courier9x13);

  dma_display_dt->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display_dt->setTextColor(dma_display_dt->color444(15,15,15));

  while(1)
  {
    struct tm timeinfo = rtc.getTimeStruct();

    dma_display_dt->setCursor(8, 12);
    dma_display_dt->println(timeinfo.tm_hour,timeinfo.tm_min,timeinfo.tm_sec);
    delay(1000);
    dma_display_dt->clearScreen();
  }
  
}

void disp_loop() {
  Serial.println("Inside Disp loop");
  disp_setup();
}