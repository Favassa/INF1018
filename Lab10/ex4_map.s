.text
.globl map2
map2:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    pushq %r12
    pushq %r13
    pushq %r14
    
    movq %rdi, %rbx
    movq %rsi, %r12
    movl %edx, %r13d
    movl $0, %r14d

loop_map2:
    cmpl %r13d, %r14d
    jge end_map2

    movslq %r14d, %rax
    movl (%rbx, %rax, 4), %edi
    call f

    movslq %r14d, %rcx
    movl %eax, (%r12, %rcx, 4)

    incl %r14d
    jmp loop_map2

end_map2:
    popq %r14
    popq %r13
    popq %r12
    popq %rbx
    leave
    ret