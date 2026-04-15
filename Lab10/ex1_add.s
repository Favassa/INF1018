.text
.globl add
add:
    pushq %rbp
    movq %rsp, %rbp
    
    movl $0, %eax
    
loop_add:
    testq %rdi, %rdi
    je end_add
    
    addl (%rdi), %eax
    movq 8(%rdi), %rdi
    jmp loop_add

end_add:
    leave
    ret