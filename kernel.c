#include "graphics.h"
#include "keyboard.h"
#include "keymap.h"
#include "multiboot.h"

#define COLOR_BG      0x1A1A1A 
#define COLOR_WINDOW  0x2D2D2D 

void draw_shell_ui() {
    clear_screen_gfx(COLOR_BG);
    draw_rect(50, 50, 700, 450, COLOR_WINDOW); 
}

void kmain(unsigned long magic, unsigned long addr) {
    if (magic == 0x2BADB002) {
        multiboot_info_t *mbi = (multiboot_info_t *) addr;
        if (mbi->flags & (1 << 12)) {
            set_vga_buffer((uint32_t *)(uintptr_t)mbi->framebuffer_addr);
            set_vga_pitch(mbi->framebuffer_pitch);
        }
    }
    
    draw_shell_ui(); 
    keyboard_init();

    while(1) {
        __asm__ __volatile__("hlt");
    }
}