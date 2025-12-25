OUTPUT_FORMAT(binary)

SECTIONS
{
    /* BIOS carrega o primeiro setor aqui */
    . = 0x7c00;
    .boot : {
        boot.o(.text)
    }

    /* O kernel começa na memória em 0x1000 */
    /* Mas no arquivo .bin, ele começa no offset 512 (0x7e00) */
    . = 0x1000;
    .text : AT(0x7e00) { 
        *(.text) 
        *(.rodata*) /* Adicionado asterisco para capturar todas as variações de rodata */
    }

    /* Garantimos que data e bss sigam a localização do código no arquivo */
    .data : { 
        *(.data) 
    }

    .bss : { 
        *(COMMON)   /* Essencial para variáveis globais não inicializadas */
        *(.bss) 
    }
}