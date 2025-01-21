global ft_write
section .text
extern __errno_location

ft_write:                           ; rdi: fd; rsi: str; rdx : len
    mov rax, 0x01                   ; write syscall
    ; Moving parameters to the right registers is not needed since there are already in the right registers
    ; mov rdi, rdi
    ; mov rsi, rsi
    ; mov rdx, rdx
    syscall                         ; Make the system call
    ; Same here we don't need to move the return value to rax since the syscall already does it

    ; error handling
    test rax, rax
    js .error

    ret
    
.error:
    neg rax                         ; make the error value absolute
    mov rdi, rax                    ; copy the syscall error value in rdi
    call __errno_location wrt ..plt ; get the errno With respect to (WRT) Procedure Linkage Table(PLT) dynamic linker to resolve the address.
    mov [rax], rdi                  ; put the copy of the syscall return at the address of errno
    mov rax, -1                     ; set the return value to -1

    ret