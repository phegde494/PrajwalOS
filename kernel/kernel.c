#include "../hardware_interrupts/idt.h"
#include "../hardware_interrupts/isr.h"
#include "../device_drivers/screen.h"
#include "../device_drivers/keyboard.h"

#include "utilities.h"
#include "mem.h"


void start_kernel() {
    clear_screen();
    isr_install();
    asm volatile("sti");
    init_keyboard();

    print_string("Welcome to PrajwalOS\n");
    print_string("> ");
}

void execute_command(char *input) {
    if (compare_string(input, "exit") == 0) {
        print_string("Shutting down the OS.\n");
        asm volatile("hlt");
    }
    else if(compare_string(input, "clear") == 0) {
        clear_screen();
        print_string("> ");
    }
    else if (starts_with_key(input, "echo") != -1) {
        print_string((char*)&input[5]);
        print_nl();
        print_string("> ");
    }
    else if (compare_string(input, "ls") == 0) {
        print_string("No directories present\n");
        print_string("> ");
    }
    else if (starts_with_key(input, "cd") != -1) {
        print_string("Directory not found\n");
        print_string("> ");
    }
    else {
        print_string("command not recognized\n");
        print_string("> ");
    }
}
