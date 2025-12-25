CC = gcc
AS = nasm
LD = ld

# Flags para garantir compatibilidade 32-bits e Multiboot
CFLAGS = -m32 -ffreestanding -fno-stack-protector -fno-pie -O0
LDFLAGS = -m elf_i386 -T link.ld

# Adicionados graphics.o e keyboard.o para resolver os erros de 'undefined reference'
OBJ = boot.o kernel.o graphics.o keyboard.o

all: kernel.bin

kernel.bin: $(OBJ)
	$(LD) $(LDFLAGS) -o kernel.bin $(OBJ)

boot.o: boot.asm
	$(AS) -f elf32 boot.asm -o boot.o

# Regra para compilar todos os arquivos .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	qemu-system-i386 -kernel kernel.bin

clean:
	rm -f *.o kernel.bin