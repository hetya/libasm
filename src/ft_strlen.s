global ft_strlen
section .text

ft_strlen:      ; rdi: str
    xor rcx, rcx        ; set rcx to 0

.loop:
    cmp byte [rdi], 0   ; set the Zero flag if the value is zero
    jz .done            ; jump to the end if the value is zero
    inc rdi             ; increment rdi
    inc rcx             ; increment rcx
    jmp .loop           ; jmp to the start of the loop

.done:
    mov rax, rcx        ; put the counter in rax (return value)
    ret
