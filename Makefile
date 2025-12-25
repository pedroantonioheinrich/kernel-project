# Compiladores e Ferramentas
CC = gcc
AS = nasm
LD = ld

# Flags de Compilação
# O link.ld já gerencia os endereços de memória
CFLAGS = -m32 -ffreestanding -fno-stack-protector -fno-pie -O0
LDFLAGS = -m elf_i386 -T link.ld

# Objetos necessários
OBJ = boot.o kernel.o graphics.o keyboard.o

# Alvo principal: a imagem final do disco
all: os-image.bin

# O Linker gera o binário final puro
os-image.bin: $(OBJ)
	$(LD) $(LDFLAGS) -o os-image.bin $(OBJ)

# Compilação do Bootloader
boot.o: boot.asm
	$(AS) -f elf32 boot.asm -o boot.o

# Regra genérica para arquivos C
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Execução no QEMU
# Adicionada a flag -vga std para garantir compatibilidade com o endereço de vídeo
run: all
	qemu-system-i386 -drive format=raw,file=os-image.bin -vga std

# Limpeza de arquivos temporários
clean:
	rm -f *.o os-image.bin