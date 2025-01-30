global ft_write
section .text
extern __errno_location

ft_write:                           ; rdi: fd; rsi: str; rdx : len
    mov rax, 0x01                   ; write syscall, args are already in the right registers
    syscall                         ; Make the system call

    test rax, rax                   ; check if the syscall failed
    js .error                       ; jump to the error label if the sign flag is set

    ret
    
.error:
    neg rax
    mov rdx, rax
    call __errno_location wrt ..plt
    mov [rax], rdx
    mov rax, -1
    
    ret