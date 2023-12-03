#include<ESP32-HUB75-MatrixPanel-I2S-DMA.h>

// Declare the variables as extern in the header file

extern HUB75_I2S_CFG::i2s_pins _pins;

extern HUB75_I2S_CFG mxconfig;

//MatrixPanel_I2S_DMA dma_display
extern MatrixPanel_I2S_DMA* dma_display;

//Setting up the color values
extern uint16_t myBLACK;
extern uint16_t myHEXYELLOW;