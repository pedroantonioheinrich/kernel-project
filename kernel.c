#include "graphics.h"
#include "keyboard.h"
#include "keymap.h"

// Cores Modernas
#define COLOR_BG      0x1A1A1A 
#define COLOR_WINDOW  0x2D2D2D 
#define COLOR_ACCENT  0x007ACC 
#define COLOR_TEXT    0xFFFFFF 

// Variáveis de controle de tela
uint32_t cursor_x = 70;
uint32_t cursor_y = 80;
uint8_t ultimo_scancode = 0;

// Fonte Bitmap 8x8 (Mantenha ou complete esta tabela)
unsigned char font_minimal[128][8] = {
    ['A'] = {0x18, 0x3C, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00},
    ['B'] = {0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x00},
    ['>'] = {0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x00}
};

// Protótipos para que kmain possa chamá-las mesmo estando no topo
void put_char(char c, int x, int y, uint32_t color);
void draw_shell_ui();

// Ponto de entrada chamado pelo boot.asm
void kmain(void) {
    // Lista de endereços comuns de vídeo no QEMU
    uint32_t enderecos[] = {0xFD000000, 0xE0000000, 0xF0000000, 0xC0000000};
    
    for(int a = 0; a < 4; a++) {
        uint32_t *teste_buffer = (uint32_t*)enderecos[a];
        // Pinta os primeiros 1000 pixels de cada endereço com cores diferentes
        for(int i = 0; i < 10000; i++) {
            teste_buffer[i] = 0x00FF00; // Verde para indicar sucesso
        }
    }

    // Se um desses endereços estiver correto, você verá faixas verdes no topo da tela
    draw_shell_ui();

    while(1) {
        uint8_t scancode = keyboard_read_scancode();

        // Lógica para evitar repetição infinita da tecla e processar apenas o "press"
        if (scancode != 0 && scancode != ultimo_scancode) {
            ultimo_scancode = scancode;

            if (scancode == 0x1C) { // Tecla ENTER
                cursor_y += 12;
                cursor_x = 70;
                
                // Proteção contra fim da janela (Scroll simples)
                if (cursor_y > 480) {
                    draw_shell_ui(); // Limpa a janela se chegar ao fim
                    cursor_y = 80;
                }
                put_char('>', 60, cursor_y, COLOR_ACCENT);
            } 
            else if (scancode < 0x80) { // Teclas normais (sem bit de release)
                char letra = ascii_map[scancode]; // Certifique-se que o nome no keymap.h é ascii_map
                if (letra != 0) {
                    put_char(letra, cursor_x, cursor_y, COLOR_TEXT);
                    cursor_x += 8;
                    
                    // Proteção de borda direita
                    if (cursor_x > 730) {
                        cursor_x = 70;
                        cursor_y += 12;
                    }
                }
            }
        } else if (scancode == 0) {
            ultimo_scancode = 0;
        }
    }
}

void put_char(char c, int x, int y, uint32_t color) {
    // Evita tentar desenhar caracteres que não definimos na font_minimal
    if (c > 127 || font_minimal[(int)c][0] == 0 && c != ' ') return;

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
    
    // Janela Principal
    draw_rect(50, 50, 700, 450, COLOR_WINDOW); 
    draw_rect(50, 50, 700, 25, 0x3E3E3E);     // Título
    
    put_char('>', 60, 80, COLOR_ACCENT);
}