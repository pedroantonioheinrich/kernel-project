#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

// Funções de configuração
void set_vga_buffer(uint32_t *new_buffer);
void set_vga_pitch(uint32_t pitch);

// Funções de desenho
void draw_pixel(int x, int y, uint32_t color);
void draw_rect(int x, int y, int w, int h, uint32_t color);
void clear_screen_gfx(uint32_t color);

#endif