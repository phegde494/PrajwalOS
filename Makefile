# for personal reference:
# $@ = target file
# $< = first dependency
# $^ = all dependencies

# detect all .o files based on their .c source
C_SOURCES = $(wildcard kernel/*.c device_drivers/*.c hardware_interrupts/*.c)
HEADERS = $(wildcard kernel/*.h  device_drivers/*.h hardware_interrupts/*.h)
OBJ_FILES = ${C_SOURCES:.c=.o hardware_interrupts/interrupt.o}


all: run

# Build dependencies
kernel.bin: bootloader/kernel_entry.o ${OBJ_FILES}
	x86_64-elf-ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

os-image.bin: bootloader/master_boot_record.bin kernel.bin
	cat $^ > $@

run: os-image.bin
	qemu-system-i386 -fda $<

echo: os-image.bin
	xxd $<

# Support for debug option with make run
kernel.elf: bootloader/kernel_entry.o ${OBJ_FILES}
	x86_64-elf-ld -m elf_i386 -o $@ -Ttext 0x1000 $^

debug: os-image.bin kernel.elf
	qemu-system-i386 -s -S -fda os-image.bin -d guest_errors,int &
	i386-elf-gdb -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"

%.o: %.c ${HEADERS}
	x86_64-elf-gcc -g -m32 -ffreestanding -c $< -o $@ # -g for debugging

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

%.dis: %.bin
	ndisasm -b 32 $< > $@

clean:
	$(RM) *.bin *.o *.dis *.elf
	$(RM) kernel/*.o
	$(RM) bootloader/*.o bootloader/*.bin
	$(RM) device_drivers/*.o
	$(RM) hardware_interrupts/*.o
