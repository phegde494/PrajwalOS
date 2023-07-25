#bin/bash

brew install qemu nasm
brew install i386-elf-binutils
brew install i386-elf-gcc
brew install i386-elf-gdb
export PATH="/usr/local/Cellar/x86_64-elf-binutils/<version>/bin/:/usr/local/Cellar/x86_64-elf-gcc/<version>/bin/:/usr/local/Cellar/i386-elf-gdb/<version>/bin:$PATH"
