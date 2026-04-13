.data
nums: .long 65, -105, 111, 34
fmt4: .string "soma = %d\n"

.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    pushq %r12
    
    movl $0, %ebx
    movl $0, %r12d
    
loop4_start:
    cmpl $4, %ebx
    jge loop4_end
    
    movslq %ebx, %rcx
    imulq $4, %rcx
    movq $nums, %rdx
    addq %rcx, %rdx
    
    addl (%rdx), %r12d
    
    incl %ebx
    jmp loop4_start
    
loop4_end:
    movq $fmt4, %rdi
    movl %r12d, %esi
    movl $0, %eax
    call printf
    
    movl $0, %eax
    popq %r12
    popq %rbx
    leave
    ret