#include "tests.h"

void test_color_palette() {
    // Adicionado o argumento '0' para a coluna em todas as chamadas
    kprint("Teste de Cores:", 5, 0, COLOR_WHITE);
    kprint("VERDE (Sucesso)", 6, 0, COLOR_GREEN);
    kprint("VERMELHO (Erro)", 7, 0, COLOR_RED);
    kprint("BRANCO (Padrao)", 8, 0, COLOR_WHITE);
}

void test_screen_bounds() {
    // Testa se a escrita na última linha e coluna 0 funciona
    // VGA tem 25 linhas (0 a 24) e 80 colunas (0 a 79)
    kprint("Abaixo deve ser o fim da tela", 23, 0, COLOR_WHITE);
    kprint("Linha 24 - Limite Inferior", 24, 0, COLOR_RED);
}

void run_all_tests() {
    kclear_screen();
    // Adicionado 0 para a coluna no título do diagnóstico
    kprint("=== KERNEL DIAGNOSTIC MODE ===", 0, 0, COLOR_WHITE);
    test_color_palette();
    test_screen_bounds();
}