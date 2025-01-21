global ft_strdup
section .text
extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:          ; rdi: str
    ; setup the stack frame
    push rbp        ; Save the old base pointer(rbp) onto the stack
    mov rbp, rsp    ; Set the base pointer to the current stack pointer

    push rdi        ; Save the first parameter on the stack
    call ft_strlen  ; call strlen with the same param
    inc rax         ; add 1 to result for the null terminator
    mov rdi, rax    ; move the result to rdi (param for malloc)
    call malloc wrt ..plt
    test rax,rax    ; check if malloc failed
    jz .done

    pop rsi         ; pop the first parameter from the stack
    mov rdi, rax    ; mov the destination in rdi
    call ft_strcpy
    
.done:
    pop rbp         ; Restore the old base pointer (rbp) from the stack
    ret