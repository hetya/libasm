global ft_write
section .text

ft_write:
    push rbp ; Save the old base pointer(rbp) onto the stack
    mov rbp, rsp; Set the base pointer to the current stack pointer

    mov rax, 0x01    ; read syscall
    ; Moving parameters to the right registers is not needed since there are already in the right registers
    ; mov rdi, rdi
    ; mov rsi, rsi
    ; mov rdx, rdx
    syscall ; Make the system call
    ; Same here we don't need to move the return value to rax since the syscall already does it

    pop rbp ; Restore the old base pointer (rbp) from the stack

    ret
