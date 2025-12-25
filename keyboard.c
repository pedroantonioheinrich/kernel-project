#include "keyboard.h"
#include "io.h"

uint8_t keyboard_read_scancode() {
    // Verifica se há dados no buffer do controlador (bit 0 da porta 0x64)
    if (inb(KEYBOARD_STATUS_PORT) & 0x01) {
        return inb(KEYBOARD_DATA_PORT); // Retorna o scancode bruto
    }
    return 0;
}
