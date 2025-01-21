global ft_strdup
section .text
extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:      ; rdi: str

    push rbp
    mov rbp, rsp

    push rdi

    call ft_strlen  ; call strlen with the same param
    ; mov rdi, 40
    inc rax     ; add 1 to result for the null terminator
    mov rdi, rax
    call malloc wrt ..plt ; todo: check if malloc failed
    test rax,rax
    jz .done

    pop rsi
    ; mov rsi, rdx    ; mov param1 in rsi
    mov rdi, rax    ; mov the destination in rdi
    call ft_strcpy
    
.done:
    pop rbp
    ret