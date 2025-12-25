#include "video.h"

void kprint(const char *str, unsigned int line, unsigned char color) {
    char *vidptr = (char*)0xb8000 + (line * 80 * 2);
    unsigned int i = 0;
    while (str[i] != '\0') {
        vidptr[i*2] = str[i];
        vidptr[i*2+1] = color;
        i++;
    }
}

void kclear_screen() {
    char *vidptr = (char*)0xb8000;
    unsigned int j = 0;
    while (j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07;
        j = j + 2;
    }
}