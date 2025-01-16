extern __errno_location
; section .text
global ft_write

ft_write:           ; rdi: fd; rsi: str; rdx : len
    ; setup the stack frame (not mandatory in this case)
    push rbp        ; Save the old base pointer(rbp) onto the stack
    mov rbp, rsp    ; Set the base pointer to the current stack pointer

    mov rax, 0x01   ; read syscall
    ; Moving parameters to the right registers is not needed since there are already in the right registers
    ; mov rdi, rdi
    ; mov rsi, rsi
    ; mov rdx, rdx
    syscall         ; Make the system call
    ; Same here we don't need to move the return value to rax since the syscall already does it

    ; error handling
    test rax, rax
    js error

    pop rbp         ; Restore the old base pointer (rbp) from the stack

    ret
    
error:
    ; setup the stack frame (not mandatory in this case)
    push rbp
    mov rbp, rsp

    neg rax     ; make the error value absolute
    mov rdi, rax        ; copy the syscall error value in rdi
    call __errno_location       ; get the errno
    mov [rax], rdi      ; put the copy of the syscall return at the address of errno
    mov rax, -1     ; set the return value to -1

    pop rbp
    ret