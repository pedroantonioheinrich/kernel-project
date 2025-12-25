#include "video.h"
#include "io.h"

void kprint(const char *str, uint32_t linha, uint32_t coluna, uint8_t cor) {
    // Agora o cálculo leva em conta a coluna (coluna * 2 bytes por caractere)
    char *vidptr = (char*)0xb8000 + (linha * 80 * 2) + (coluna * 2);
    uint32_t i = 0;
    while (str[i] != '\0') {
        vidptr[i*2] = str[i];
        vidptr[i*2+1] = cor;
        i++;
    }
}

void kclear_screen() {
    char *vidptr = (char*)0xb8000;
    uint32_t j = 0;
    while (j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07;
        j = j + 2;
    }
}

void update_cursor(int x, int y) {
    // Calcula a posição linear (o hardware vê a tela como um array de 2000 posições)
    uint16_t pos = y * 80 + x;

    // Envia o byte baixo da posição (bits 0-7)
    outb(0x3D4, 0x0F);             // Seleciona o registrador 15 (Cursor Location Low)
    outb(0x3D5, (uint8_t) (pos & 0xFF));

    // Envia o byte alto da posição (bits 8-15)
    outb(0x3D4, 0x0E);             // Seleciona o registrador 14 (Cursor Location High)
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

