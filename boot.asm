; Um bootloader simples que entra em modo 32-bit e chama o C
bits 32
section .text
        align 4
        dd 0x1BADB002              ; Magic number (Multiboot)
        dd 0x00                    ; Flags
        dd - (0x1BADB002 + 0x00)   ; Checksum

global start
extern kmain

start:
  cli                         ; Desliga interrupções
  call kmain                  ; Pula para a função principal em C
  hlt                         ; Para o processador