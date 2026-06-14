.text
.globl pack1
pack1:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    pushq %rbx
    pushq %r12
    pushq %r13
    
    movq %rdi, %rbx
    movl %esi, %r12d
    movl $0, %r13d
    
    pxor %xmm0, %xmm0
    movsd %xmm0, -8(%rbp)
    
loop_pack1:
    cmpl %r12d, %r13d
    jge end_pack1
    
    movslq %r13d, %rax
    leaq (%rbx, %rax, 8), %rcx
    
    movss 4(%rcx), %xmm0
    cvtss2sd %xmm0, %xmm0
    movl (%rcx), %edi
    
    call foo
    
    movsd -8(%rbp), %xmm1
    addsd %xmm0, %xmm1
    movsd %xmm1, -8(%rbp)
    
    incl %r13d
    jmp loop_pack1
    
end_pack1:
    movsd -8(%rbp), %xmm0
    popq %r13
    popq %r12
    popq %rbx
    leave
    ret