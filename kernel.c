#include "graphics.h"
#include "keyboard.h"
#include "keymap.h"

#define COLOR_BG      0x1A1A1A 
#define COLOR_WINDOW  0x2D2D2D 
#define COLOR_ACCENT  0x007ACC 
#define COLOR_TEXT    0xFFFFFF 

uint32_t cursor_x = 70;
uint32_t cursor_y = 80;

// Fonte Bitmap 8x8 expandida para teste
unsigned char font_minimal[128][8] = {
    ['A'] = {0x18, 0x3C, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00},
    ['B'] = {0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x00},
    ['C'] = {0x3C, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3C, 0x00},
    ['>'] = {0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x00}
};

void put_char(char c, int x, int y, uint32_t color) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (font_minimal[(int)c][i] & (1 << (7 - j))) {
                draw_pixel(x + j, y + i, color);
            }
        }
    }
}

void draw_shell_ui() {
    clear_screen_gfx(COLOR_BG);
    
    // Barra de Tarefas
    draw_rect(0, 560, 800, 40, 0x111111); 
    draw_rect(10, 565, 30, 30, COLOR_ACCENT); 
    
    // Janela do Terminal
    draw_rect(50, 50, 700, 450, COLOR_WINDOW); 
    draw_rect(50, 50, 700, 25, 0x3E3E3E);     
    
    put_char('>', 60, 80, COLOR_ACCENT);
}

// kernel.c - Teste de Estabilidade Multiboot
void kmain(void) {
    const char *str = "SUCESSO! O MODO MULTIBOOT ESTA FUNCIONANDO.";
    char *video_memory = (char *) 0xb8000; // Endereço de texto estável

    // Limpa a tela com fundo azul e texto branco
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        video_memory[i] = ' ';
        video_memory[i+1] = 0x1F; 
    }

    // Escreve a mensagem
    for (int i = 0; str[i] != '\0'; i++) {
        video_memory[i * 2] = str[i];
        video_memory[i * 2 + 1] = 0x1F; 
    }

    // Mantém o processador vivo
    while(1);
}