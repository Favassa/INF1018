.text
.globl boo
boo:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    pushq %r12
    pushq %r13
    
    movq %rdi, %rbx
    movl %esi, %r12d
    movl %edx, %r13d

loop_boo:
    movl %r12d, %eax
    decl %r12d
    testl %eax, %eax
    je end_boo

    movl (%rbx), %edi
    movl %r13d, %esi
    call f

    movl %eax, 4(%rbx)
    addq $8, %rbx
    jmp loop_boo

end_boo:
    popq %r13
    popq %r12
    popq %rbx
    leave
    ret