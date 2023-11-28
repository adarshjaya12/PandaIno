#include<Arduino.h>
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include"clock_hex_type.h"
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


HUB75_I2S_CFG::i2s_pins _pins_hex={R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
HUB75_I2S_CFG mxconfig_hex(
	64, // Module width
	64, // Module height
	1, // chain length
	_pins_hex // pin mapping
);


//MatrixPanel_I2S_DMA dma_display_hex;
MatrixPanel_I2S_DMA *dma_display_hex = nullptr;

//Setting up the color values
uint16_t myYELLOW = dma_display_hex->color565(24, 49, 9);
uint16_t myBLACK = dma_display_hex->color565(0,0,0);


extern ESP32Time rtc;

void clock_hex_type_setup() {

  // Display Setup
  dma_display_hex = new MatrixPanel_I2S_DMA(mxconfig_hex);
  dma_display_hex->begin();
  dma_display_hex->setBrightness8(50); //0-255
  dma_display_hex->clearScreen();
  dma_display_hex->fillScreen(myBLACK);

  // fix the screen with time
  dma_display_hex->setTextSize(1);     // size 1 == 8 pixels high
  dma_display_hex->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  //dma_display_hex->setFont(&Courier9x13);

  dma_display_hex->setCursor(8, 12);    // start at top left, with 8 pixel of spacing
  dma_display_hex->setTextColor(dma_display_hex->color444(15,15,15));

  while(1)
  {
    String time= rtc.getTime("%H:%M:%S");
    dma_display_hex->setCursor(8, 12);
    dma_display_hex ->fillScreen(myYELLOW);
    dma_display_hex->println(time);
    delay(1000);
    dma_display_hex->clearScreen();
  }
  
}

void clock_hex_type_loop() {
  Serial.println("Inside Disp loop");
  clock_hex_type_setup();
}