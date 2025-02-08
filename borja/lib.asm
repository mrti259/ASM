extern fprintf

%define ej1_n 16
%define ej7_n 10

section .data

ej1_v: dd 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
ej2_null: db "NULL", 0

section .text

global ej1
ej1:
    mov eax, 0 ; sum
    mov rcx, 0 ; i
    
    .loop:
    cmp rcx, ej1_n
    jnl .ret
    add eax, dword [ej1_v + 4 * rcx]
    inc rcx
    jmp .loop

    .ret:
    ret

global strLen
strLen:
    mov rax, 0
    cmp rdi, 0
    jz .ret

    .loop:
    cmp byte [rdi + rax], 0
    jz .ret
    inc rax
    jmp .loop
    
    .ret:
    ret

global strCmp
strCmp:
    cmp rdi, rsi
    jz .ret_e
    cmp rdi, 0
    jz .ret_l
    cmp rsi, 0
    jz .ret_g
    mov rcx, 0

    .loop:
    mov r8b, byte [rdi + rcx]
    mov r9b, byte [rsi + rcx]
    cmp r8b, r9b
    jl .ret_l ; a[i] < b[i]
    jg .ret_g ; a[i] > b[i]
    add r8b, r9b ; a[i] + b[i] = 2 * a[i]
    cmp r8b, 0
    jz .ret_e
    inc rcx
    jmp .loop

    .ret_e:
    mov eax, 0
    ret

    .ret_l:
    mov eax, 1
    ret

    .ret_g:
    mov eax, -1
    ret

global strPrint
strPrint:
    ; armo stackframe
    push rbp
    mov rbp, rsp
    ; queda alienado

    cmp rsi, 0
    jz .ret
    cmp rdi, 0
    jz .null
    cmp byte [rdi], 0
    jz .null

    .print:
    mov rdx, rdi ; tmp
    mov rdi, rsi
    mov rsi, rdx
    call fprintf
    jmp .ret

    .null:
    mov rdi, ej2_null
    jmp .print

    ; desarmo stackframe
    .ret:
    pop rbp
    ret

global countChars
countChars:
    mov eax, 0
    mov rcx, 0
    cmp rdi, 0
    jz .ret
    
    .loop:
    cmp byte [rdi + rcx], 0
    jz .ret
    cmp byte [rdi + rcx], sil
    jnz .next
    inc eax

    .next:
    inc rcx
    jmp .loop

    .ret:
    ret

global intercambiar
intercambiar:
    call strLen
    mov rsi, rax ; top
    shr rsi, 1
    mov rcx, 0 ; i

    .loop:
    cmp rcx, rsi
    jnl .ret
    dec rax
    mov r8b, byte [rdi + rax] ; tmp1 = str[len]
    mov r9b, byte [rdi + rcx] ; tmp2 = str[i]
    mov  byte [rdi + rax], r9b
    mov  byte [rdi + rcx], r8b
    inc rcx
    jmp .loop

    .ret:
    ret

global diagonal
diagonal:
    mov rcx, 0 ; i
    .loop:
    cmp cx, si
    jz .ret
    movsx r8, si ; x = n
    inc r8 ; x += 1
    imul r8, rcx ; x *= i
    mov r9w, word [rdi + 2 * r8] ; matriz[x]
    mov word [rdx + 2 * rcx], r9w ; vector[i] = matrix[x]
    inc rcx
    jmp .loop
    .ret:
    ret

global gris
gris:
    movsx rsi, si
    mov rcx, 0
    
    .loop:
    cmp rcx, rsi
    jnl .ret
    lea r8, [rdi + 4 * rcx]
    mov r9b, byte [r8 + 0]
    shl r9b, 1
    add r9b, byte [r8 + 1]
    add r9b, byte [r8 + 2]
    shr r9b, 2
    mov byte [rdx + rcx], r9b
    inc rcx
    jmp .loop

    .ret:
    ret

global primerMaximo
; rdi -> matriz
; rsi -> f
; rdx -> c
primerMaximo:
    mov rax, 0 ; max
    mov rcx, 0 ; i
    
    .loop1:
    cmp rcx, ej7_n
    jnl .end_loop1
    mov rbx, 0 ; j

    .loop2:
    cmp rbx, ej7_n
    jnl .end_loop2
    lea r9, [rdi + 4 * rbx] ; num = &(matriz[i][j])
    cmp rax, 0
    jz .max    
    mov r10d, dword [rax] ; *max
    cmp dword [r9], r10d
    jle .next2

    .max:
    mov rax, r9
    mov dword [rsi], ecx
    mov dword [rdx], ebx

    .next2:
    inc rbx
    jmp .loop2
     
    .end_loop2:
    inc rcx
    mov rbx, ej7_n
    shl rbx, 2
    add rdi, rbx
    jmp .loop1

    .end_loop1:
    ret
