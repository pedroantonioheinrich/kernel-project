all:
	nasm -f elf32 boot.asm -o boot.o
	gcc -m32 -c kernel.c -o kernel.o -ffreestanding -fno-stack-protector
	gcc -m32 -c video.c -o video.o -ffreestanding -fno-stack-protector
	gcc -m32 -c tests.c -o tests.o -ffreestanding -fno-stack-protector
	gcc -m32 -c keyboard.c -o keyboard.o -ffreestanding -fno-stack-protector
	ld -m elf_i386 -T link.ld -o kernel boot.o kernel.o video.o tests.o keyboard.o

run:
	qemu-system-i386 -kernel kernel

clean:
	rm -f *.o kernel