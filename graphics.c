#include "graphics.h"

// Endereço do Frame Buffer no QEMU
// uint32_t *vga_buffer = (uint32_t*)0xFD000000; 

// Se 0xFD000000 não funcionar perfeitamente, tente 0xE0000000
// uint32_t *vga_buffer = (uint32_t*)0xE0000000;

// Tente este endereço se o anterior resultou em tela preta
uint32_t *vga_buffer = (uint32_t*)0xFD000000;

void draw_pixel(int x, int y, uint32_t color) {
    if (x >= 0 && x < 800 && y >= 0 && y < 600) {
        vga_buffer[y * 800 + x] = color;
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
    // 800 * 600 pixels
    for (int i = 0; i < 480000; i++) {
        vga_buffer[i] = color;
    }
}