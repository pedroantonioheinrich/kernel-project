#include "types.h"
#ifndef VIDEO_H
#define VIDEO_H


// Definições de cores usando uint8_t
#define COLOR_BLACK 0x00
#define COLOR_GREEN 0x0A
#define COLOR_RED   0x0C
#define COLOR_WHITE 0x0F


void kprint(const char *str, uint32_t linha, uint8_t cor);
void kclear_screen();

#endif