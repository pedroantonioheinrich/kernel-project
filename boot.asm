; boot.asm - Versão Multiboot
section .multiboot
align 4
    dd 0x1BADB002              ; Magic number (Multiboot 1)
    dd 0x00                    ; Flags (0 para início simples)
    dd -(0x1BADB002 + 0x00)    ; Checksum

section .text
global _start
extern kmain

_start:
    cli                         ; Bloqueia interrupções externas
    mov esp, stack_space        ; Define o topo da pilha
    call kmain                  ; Salta para o teu C
    
    ; Caso o kernel retorne, entra em loop infinito
.halt:
    hlt
    jmp .halt

section .bss
resb 8192                       ; Reserva 8KB para a pilha (stack)
stack_space: