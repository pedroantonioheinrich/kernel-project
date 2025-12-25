all:
	# Compila o Assembly
	nasm -f elf32 boot.asm -o boot.o
	# Compila o C (sem bibliotecas padrão, pois o kernel é a base)
	gcc -m32 -c kernel.c -o kernel.o -ffreestanding -fno-stack-protector
	# Junta tudo no arquivo 'kernel'
	ld -m elf_i386 -T link.ld -o kernel boot.o kernel.o

run:
	qemu-system-i386 -kernel kernel