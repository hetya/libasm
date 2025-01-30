global ft_strcmp
section .text

ft_strcmp:                      ; rdi: str1; rsi: str2
    xor rcx, rcx                ; set rcx to 0
    push rbx                    ; save rbx  (callee saved register)


.loop:
    xor rax, rax                ; empty regs
    xor rbx, rbx
    mov al, [rdi + rcx]         ; store the value of str1 in al
    mov bl, [rsi + rcx]         ; store the value of str2 in bl
    sub rax, rbx
    jnz .done                   ; end the loop if the result is not 0
    cmp byte [rdi + rcx], 0     ; check if the it is the end of str2
    je .done
    cmp byte [rsi + rcx], 0     ; check if it is the end of str1
    je .done
    inc rcx                     ; increment index
    jmp .loop

.done:
    pop rbx                     ; restore rbx
    ret

