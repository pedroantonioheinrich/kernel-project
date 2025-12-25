#include "keyboard.h"
#include "io.h"

uint8_t keyboard_read_scancode() {
    // Verifica se o bit 0 da porta de status está ativo (há dado pronto)
    if (inb(KEYBOARD_STATUS_PORT) & 0x01) {
        return inb(KEYBOARD_DATA_PORT);
    }
    return 0;
}