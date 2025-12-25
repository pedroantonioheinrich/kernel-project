#ifndef VIDEO_H
#define VIDEO_H

#include "types.h"

// Definições de cores
#define COLOR_BLACK 0x00
#define COLOR_GREEN 0x0A
#define COLOR_RED   0x0C
#define COLOR_WHITE 0x0F

// Protótipos das funções de vídeo
void kprint(const char *str, uint32_t linha, uint32_t coluna, uint8_t cor);
void kclear_screen();

// Nova declaração para o cursor piscante
void update_cursor(int x, int y);

#endif