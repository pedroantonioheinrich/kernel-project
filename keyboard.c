#include "keyboard.h"
#include "io.h"

void keyboard_init() {
    // Limpa o buffer do teclado lendo qualquer dado residual
    while (inb(KEYBOARD_STATUS_PORT) & 0x01) {
        inb(KEYBOARD_DATA_PORT);
    }
}

uint8_t keyboard_read_scancode() {
    // Verifica se o bit 0 (Output Buffer Full) está ativo na porta 0x64
    if (inb(KEYBOARD_STATUS_PORT) & 0x01) {
        return inb(KEYBOARD_DATA_PORT); // Retorna o scancode bruto
    }
    return 0;
}