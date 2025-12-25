#ifndef VIDEO_H
#define VIDEO_H

// Definições de cores (VGA)
#define COLOR_BLACK 0x00
#define COLOR_GREEN 0x0A
#define COLOR_RED   0x0C
#define COLOR_WHITE 0x0F

// Protótipos das funções
void kprint(const char *str, unsigned int line, unsigned char color);
void kclear_screen();

#endif