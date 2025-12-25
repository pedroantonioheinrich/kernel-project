OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

SECTIONS
{
    /* O kernel será carregado no endereço 1MB de memória */
    . = 1M;

    .text :
    {
        /* Garante que o código de boot (Multiboot) fique no início */
        *(.text)
    }

    .rodata :
    {
        *(.rodata)
    }

    .data :
    {
        *(.data)
    }

    .bss :
    {
        *(.bss)
    }
}