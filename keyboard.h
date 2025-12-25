#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "types.h"

// Porta de dados do teclado
#define KEYBOARD_DATA_PORT 0x60
// Porta de status do teclado
#define KEYBOARD_STATUS_PORT 0x64

// Função para ler o código da tecla (scan code)
uint8_t keyboard_read_scancode();

#endif