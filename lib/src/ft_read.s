global ft_read
section .text
extern __errno_location

ft_read:
    mov rax, 0x00       ; syscall number for read, args are already in the right registers
    syscall
    test rax, rax
    js .error                       ; jump to the error label if the sign flag is set

    ret

.error:
    neg rax
    mov rdi, rax
    call __errno_location wrt ..plt
    mov [rax], rdi
    mov rax, -1
    
    ret

