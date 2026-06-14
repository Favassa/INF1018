.text
.globl pack
pack:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    pushq %rbx
    
    movq %rdi, %rbx
    pxor %xmm0, %xmm0
    movsd %xmm0, -8(%rbp)
    
loop_pack:
    testq %rbx, %rbx
    je end_pack
    
    movsd 8(%rbx), %xmm0
    movl (%rbx), %edi
    call foo
    
    movsd -8(%rbp), %xmm1
    addsd %xmm0, %xmm1
    movsd %xmm1, -8(%rbp)
    
    movq 16(%rbx), %rbx
    jmp loop_pack
    
end_pack:
    movsd -8(%rbp), %xmm0
    popq %rbx
    leave
    ret