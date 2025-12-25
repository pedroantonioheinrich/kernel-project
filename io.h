#ifndef IO_H
#define IO_H

#include "types.h"

/**
 * Envia um byte para uma porta de hardware específica.
 * Usada para controlar o cursor VGA e outros dispositivos.
 */
static inline void outb(uint16_t port, uint8_t val) {
    __asm__ volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

/**
 * Lê um byte de uma porta de hardware específica.
 * Usada para ler os dados vindos do teclado (Porta 0x60).
 */
static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

#endif