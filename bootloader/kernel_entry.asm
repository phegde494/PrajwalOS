global _start;
[bits 32]

_start:
    [extern start_kernel] ; Define calling point
    call start_kernel ; Calls start_kernel function from kernel.c
    jmp $
