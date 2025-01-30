global ft_read
section .text
extern __errno_location

ft_read:                            ; rdi: fd, rsi: buf, rdx: len
    mov rax, 0x00                   ; syscall number for read
    ; Moving parameters to the right registers is not needed since there are already in the right registers
    ; mov rdi, rdi
    ; mov rsi, rsi
    ; mov rdx, rdx
    syscall
    ; Same here we don't need to move the return value to rax since the syscall already does it

    ; error handling
    test rax, rax
    js .error                       ; jump to the error label if the sign flag is set

    ret

.error:
    neg rax                         ; make the error value absolute
    mov rdx, rax                    ; copy the syscall error value in rdx
    call __errno_location wrt ..plt ; get the errno With respect to (WRT) Procedure Linkage Table(PLT) dynamic linker to resolve the address.
    mov [rax], rdx                  ; put the copy of the syscall return at the address of errno
    mov rax, -1                     ; set the return value to -1

    ret

