.text
.globl foo
foo:
    pushq %rbp
    movq %rsp, %rbp
    
    negl %edi
    cvtsi2sd %edi, %xmm1
    mulsd %xmm1, %xmm0
    
    leave
    ret