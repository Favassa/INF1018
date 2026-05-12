.text
.globl bemboba
bemboba:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    
    movl $0, %ecx
    leaq -16(%rbp), %r8

loop_bemboba:
    cmpl $4, %ecx
    jge end_loop

    movl %edi, (%r8)
    addq $4, %r8
    
    incl %ecx
    jmp loop_bemboba

end_loop:
    leaq -16(%rbp), %rdi
    movl $4, %esi
    call addl

    leave
    ret