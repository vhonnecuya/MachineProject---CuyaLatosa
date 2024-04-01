section .text
bits 64
default rel

global daxpy_asm

daxpy_asm:
    push rbp 
    mov rbp, rsp
    add rbp, 16
    mov r10, [rbp+32] ;retrieve 5th parameter (Z)

    sub rcx, 1 ;decrement n

    L1:
        cmp rcx, 0
        jl EndLoop

        movsd xmm2, [r8 + rcx*8] ;load X[i] into xmm2
        movsd xmm3, [r9 + rcx*8] ;load Y[i] into xmm3

        mulsd xmm2, xmm1 ;multiply X[i] by A
        addsd xmm2, xmm3 ;add Y[i] to the result

        movsd [r10 + rcx*8], xmm2 ;store the result in Z[i]

        dec rcx ;decrement the counter

        jmp L1 ;jump back to the start of the loop

EndLoop:
    pop rbp
    ret