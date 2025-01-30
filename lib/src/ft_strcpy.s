global ft_strcpy
section .text

ft_strcpy:              ;rsi: str1; rdi: str2
    xor rcx, rcx        ; set rcx to 0

.loop:
    mov al, [rsi + rcx] ; store the value of str1 in al
    mov [rdi + rcx], al ; store the value of al in str2
    cmp al, 0           ; set the Zero flag if the value is zero
    je .done            ; jump to the end if the value is zero
    inc rcx
    jmp .loop           ; jmp to the start of the loop

.done:
    mov rax, rdi        ; move the address of str2 to rax
    ret