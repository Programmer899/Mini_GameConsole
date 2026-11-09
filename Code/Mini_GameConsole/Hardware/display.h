#pragma once

#include <stdint.h>

#define DISPLAY_WIDTH  128
#define DISPLAY_HEIGHT 160

// RGB565 colours
#define COLOR_BLACK  0x0000
#define COLOR_WHITE  0xFFFF
#define COLOR_RED    0xF800
#define COLOR_GREEN  0x07E0
#define COLOR_BLUE   0x001F

void Display_Init(void);
void Display_Clear(uint16_t color);
void Display_DrawPixel(int x, int y, uint16_t color);
void Display_FillRect(int x, int y, int w, int h, uint16_t color);
void Display_Render(void);