#include "tests.h"

void test_color_palette() {
    kprint("Teste de Cores:", 5, COLOR_WHITE);
    kprint("VERDE (Sucesso)", 6, COLOR_GREEN);
    kprint("VERMELHO (Erro)", 7, COLOR_RED);
    kprint("BRANCO (Padrao)", 8, COLOR_WHITE);
}

void test_screen_bounds() {
    // Testa se a escrita na última linha e última coluna funciona
    // VGA tem 25 linhas (0 a 24)
    kprint("Abaixo deve ser o fim da tela", 23, COLOR_WHITE);
    kprint("Linha 24 - Limite Inferior", 24, COLOR_RED);
}

void run_all_tests() {
    kclear_screen();
    kprint("=== KERNEL DIAGNOSTIC MODE ===", 0, COLOR_WHITE);
    test_color_palette();
    test_screen_bounds();
}