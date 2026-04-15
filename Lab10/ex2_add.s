.text
.globl add2
add2:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    subq $8, %rsp
    
    testq %rdi, %rdi
    jne not_null
    
    movl $0, %eax
    jmp end_add2

not_null:
    movl (%rdi), %ebx
    movq 8(%rdi), %rdi
    call add2
    addl %ebx, %eax

end_add2:
    addq $8, %rsp
    popq %rbx
    leave
    ret