#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "types.h"

void draw_pixel(int x, int y, uint32_t color);
void draw_rect(int x, int y, int w, int h, uint32_t color);
void clear_screen_gfx(uint32_t color);

#endif