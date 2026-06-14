.text
.globl foo3
foo3:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp
    
    movq %rbx, -8(%rbp)
    movq %r12, -16(%rbp)
    movq %r13, -24(%rbp)

    movq %rdi, %r12
    movl %esi, %r13d

    pxor %xmm0, %xmm0
    movsd %xmm0, -32(%rbp)
    
    movl $0, %ebx

loop_foo3:
    cmpl %r13d, %ebx
    jge end_foo3

    movsd (%r12), %xmm0
    call sin

    movsd -32(%rbp), %xmm1
    addsd %xmm0, %xmm1
    movsd %xmm1, -32(%rbp)

    addq $8, %r12
    incl %ebx
    jmp loop_foo3

end_foo3:
    movsd -32(%rbp), %xmm0

    movq -8(%rbp), %rbx
    movq -16(%rbp), %r12
    movq -24(%rbp), %r13
    
    leave
    ret