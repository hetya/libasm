;test
global ft_strlen
section .text

ft_strlen:
    ; try exit
    mov rax, 0x3c ; System call number for exit
    mov rdi, 5 ; Exit with code 5
    syscall ; Make the system call

section .data