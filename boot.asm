; boot.asm - Configurado para Multiboot + VESA Graphics
section .multiboot
align 4
    dd 0x1BADB002              ; Magic number do Multiboot
    dd 0x00000005              ; Flags: Memória (bit 0) + Vídeo (bit 2)
    dd -(0x1BADB002 + 0x00000005) ; Checksum

    ; Campos obrigatórios quando o bit 2 das flags está ativo
    dd 0, 0, 0, 0, 0
    dd 0                       ; 0 = Modo Linear (Gráfico)
    dd 800                     ; Largura
    dd 600                     ; Altura
    dd 32                      ; Bits por pixel

section .text
global _start
extern kmain

_start:
    cli                        ; Desabilita interrupções
    mov esp, stack_space       ; Define a pilha
    push ebx                   ; Endereço da estrutura Multiboot Info
    push eax                   ; Magic Number
    call kmain                 ; Salta para o C
    
    hlt                        ; Para a CPU caso o kernel retorne
    jmp $

section .bss
resb 16384                     ; 16KB de pilha
stack_space: