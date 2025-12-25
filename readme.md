# Kernel-Project: OS Gráfico 32-bit (Multiboot)

Este é um projeto de Sistema Operacional minimalista desenvolvido em C e Assembly x86. O projeto evoluiu de um carregador de inicialização (bootloader) legado para o padrão **Multiboot**, permitindo acesso estável ao hardware e modos gráficos de alta resolução.

## 🚀 Status Atual
- **Arquitetura**: x86 32-bits (Protected Mode).
- **Boot**: Compatível com Multiboot 1 (QEMU/GRUB).
- **Vídeo**: Linear Framebuffer (LFB) configurado para 800x600 em 32 bits por pixel (bpp).
- **Input**: Driver de teclado básico com tratamento de scancodes.

## 📁 Estrutura de Arquivos
- `boot.asm`: Ponto de entrada que define o cabeçalho Multiboot e requisita o modo VBE.
- `kernel.c`: Lógica principal, gerenciamento da estrutura Multiboot e loop do sistema.
- `graphics.c/h`: Driver de vídeo que gerencia o desenho de pixels e formas geométricas.
- `multiboot.h`: Definição das estruturas de dados enviadas pelo bootloader.
- `keyboard.c/h`: Driver de entrada para capturar teclas do usuário.

## 🛠️ Como Compilar e Rodar
Certifique-se de ter o `nasm`, `gcc-multilib` e `qemu-system-i386` instalados.

```bash
make clean
make
make run