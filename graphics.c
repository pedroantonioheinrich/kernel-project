#include "graphics.h"

/**
 * Endereço do Frame Buffer Linear (LFB).
 * Com a flag -vga std no QEMU, o endereço padrão é 0xFD000000.
 * Se a tela continuar preta, o valor alternativo é 0xE0000000.
 */
uint32_t *vga_buffer = (uint32_t*)0xFD000000; 

void draw_pixel(int x, int y, uint32_t color) {
    // Verificação de segurança para não escrever fora da memória de vídeo
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
    // Preenche todos os pixels da tela (800x600)
    for (int i = 0; i < (800 * 600); i++) {
        vga_buffer[i] = color;
    }
}