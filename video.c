#include "video.h"

void kprint(const char *str, uint32_t linha, uint8_t cor) {
    // O endereço base da memória de vídeo VGA
    char *vidptr = (char*)0xb8000 + (linha * 80 * 2);
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