global ft_strcmp
section .text

ft_strcmp:  ; rsi: s1; rdi: s2
    xor rcx, rcx        ; set rcx to 0

.loop:
    mov al, [rsi + rcx] ; store the value of s1 in al
    sub al, [rdi +rcx]  ; substract the value of s2 from al and store the result in al
    jnz .done
    inc rcx
    jmp .loop

.done:
    movzx rax, al        ; mov the diference to rax and fill the rest with 0

