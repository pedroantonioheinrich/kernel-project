[bits 16]
section .text
global _start

_start:
    ; Armazena o drive de boot enviado pela BIOS em DL
    mov [BOOT_DRIVE], dl 

    ; --- Obter informações do modo VBE ---
    ; Isso ajuda a garantir que o Linear Frame Buffer (LFB) seja ativado corretamente
    mov ax, 0x4F01      ; Get VBE mode information
    mov cx, 0x4115      ; Modo 800x600, 32-bit
    mov di, 0x7000      ; Endereço temporário para armazenar info
    int 0x10

    ; Ativa Modo Gráfico VESA (800x600, 32-bit)
    mov ax, 0x4F02
    mov bx, 0x4115 
    int 0x10

    ; Carrega o Kernel para o endereço 0x1000
    mov ax, 0x0000
    mov es, ax
    mov bx, 0x1000
    mov ah, 0x02
    
    ; Carregamos 80 setores (aprox. 40KB) para garantir que todo 
    ; o código gráfico e as fontes do kernel sejam carregados na RAM.
    mov al, 80         
    
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02    ; Começa a ler no segundo setor (logo após o boot)
    int 0x13

    ; Entra em Modo Protegido de 32 bits
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp 0x08:init_pm    

[bits 32]
init_pm:
    ; Configura os seletores de segmento para o modo protegido
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    
    ; Define a pilha (stack) em um local seguro
    mov ebp, 0x90000
    mov esp, ebp
    
    ; Salta para o código C do Kernel que o Linker posicionou em 0x1000
    call 0x1000         
    jmp $

; Estrutura da GDT (Global Descriptor Table)
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

; Assinatura de Boot: Preenche até 510 bytes e adiciona 0xAA55
times 510-($-$$) db 0
dw 0xaa55