#include "video.h"
#include "tests.h"
#include "keyboard.h"

void kmain(void) {
    kclear_screen();
    
    kprint("Sistema Iniciado com Sucesso!", 0, COLOR_GREEN);
    kprint("Modulo de Video: OK", 1, COLOR_WHITE);

    // Importante para o kernel não "escapar" da memória
    while(1) {
        __asm__("hlt"); // Comando opcional para economizar CPU
    }

    while(1) {
    uint8_t code = keyboard_read_scancode();
    if (code > 0) {
        kprint("Tecla detectada!", 5, COLOR_RED);
    }
}
}