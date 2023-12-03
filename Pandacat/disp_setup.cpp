#include "disp_setup.h"
#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>

//defining the variables
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

#define TEXT_SIZE 1
#define PANEL_WIDTH 64
#define PANEL_HEIGHT 32
#define PER_TEXT_SIZE 5

HUB75_I2S_CFG::i2s_pins _pins={R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
HUB75_I2S_CFG mxconfig(
	64, // Module width
	64, // Module height
	1, // chain length
	_pins // pin mapping
);


//MatrixPanel_I2S_DMA dma_display
MatrixPanel_I2S_DMA *dma_display = nullptr;

//Setting up the color values
uint16_t myBLACK = dma_display->color565(0,0,0);
uint16_t myHEXYELLOW = dma_display->color565(139, 128, 0);

