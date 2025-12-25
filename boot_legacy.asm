[bits 16]
section .text
global _start

_start:
    mov [BOOT_DRIVE], dl 

    ; --- Configuração VESA 800x600x32bit com LFB ---
    mov ax, 0x4F02
    ; 0x4115 = 0x115 (modo) + 0x4000 (Ativa o Linear Frame Buffer)
    mov bx, 0x4115 
    int 0x10

    ; --- Carregamento do Kernel ---
    mov ax, 0x0000
    mov es, ax
    mov bx, 0x1000
    mov ah, 0x02
    mov al, 80         ; Carrega 80 setores (40KB)
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02
    int 0x13

    ; --- Transição para Modo Protegido ---
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp 0x08:init_pm    

[bits 32]
init_pm:
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    
    mov ebp, 0x90000
    mov esp, ebp
    
    call 0x1000         ; Pula para o Kernel C
    jmp $

; --- Tabela de Descritores Globais (GDT) ---
gdt_start:
    dd 0x0, 0x0
gdt_code:
    dw 0xffff, 0x0
    db 0x0, 0x9a, 0xcf, 0x0
gdt_data:
    dw 0xffff, 0x0
    db 0x0, 0x92, 0xcf, 0x0
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1
    dd gdt_start

BOOT_DRIVE: db 0

times 510-($-$$) db 0
dw 0xaa55