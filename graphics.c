#include "graphics.h"

static uint32_t *vga_buffer = (uint32_t*)0xFD000000; 
static uint32_t vga_pitch = 3200; 

void set_vga_buffer(uint32_t *new_buffer) {
    if (new_buffer != 0) vga_buffer = new_buffer;
}

void set_vga_pitch(uint32_t pitch) {
    if (pitch >= 3200) vga_pitch = pitch; // Garante um pitch mínimo razoável
}

void draw_pixel(int x, int y, uint32_t color) {
    if (x >= 0 && x < 800 && y >= 0 && y < 600) {
        // Cálculo de offset usando uintptr_t para máxima precisão de 32 bits
        uint32_t pixels_per_line = vga_pitch / 4;
        vga_buffer[y * pixels_per_line + x] = color;
    }
}

void draw_rect(int x, int y, int w, int h, uint32_t color) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            draw_pixel(x + j, y + i, color);
        }
    }
}

void clear_screen_gfx(uint32_t color) {
    for (int y = 0; y < 600; y++) {
        for (int x = 0; x < 800; x++) {
            draw_pixel(x, y, color);
        }
    }
}