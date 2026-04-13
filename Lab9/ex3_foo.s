.text
.globl foo
foo:
    pushq %rbp
    movq %rsp, %rbp
    
    movl $0, %ecx
    movl $0, %edx

loop_foo:
    cmpl %esi, %ecx
    jge end_foo
    
    movslq %ecx, %r8
    leaq (%rdi, %r8, 4), %r9
    
    movl (%r9), %eax
    addl %eax, %edx
    
    cmpl $0, %eax
    jne continue_loop
    
    movl %edx, (%r9)
    movl $0, %edx

continue_loop:
    incl %ecx
    jmp loop_foo

end_foo:
    leave
    ret