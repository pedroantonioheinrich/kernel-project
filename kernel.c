#include "video.h"

void kmain(void) {
    const char *str = "Meu Primeiro Kernel!";
    char *vidptr = (char*)0xb8000;     // Memória de vídeo colorida
    unsigned int i = 0;
    unsigned int j = 0;

    // Limpa a tela
    while(j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07; // Cor cinza
        j = j + 2;
    }

    // Escreve a mensagem
    j = 0;
    while(str[i] != '\0') {
        vidptr[j] = str[i];
        vidptr[j+1] = 0x07; // Cor da letra
        i++;
        j = j + 2;
    }
    return;
}

void kprint(const char *str, unsigned int linha, unsigned char cor) {
    char *vidptr = (char*)0xb8000 + (linha * 80 * 2);
    unsigned int i = 0;
    while (str[i] != '\0') {
        vidptr[i*2] = str[i];     // Caractere
        vidptr[i*2+1] = cor;      // Agora usamos o argumento 'cor' aqui!
        i++;
    }
}


void kmain(void) {
    kclear_screen();
    kprint("Sistema Iniciado com Sucesso!", 0, COLOR_GREEN);
    kprint("Modulo de Video: OK", 1, COLOR_WHITE);
}