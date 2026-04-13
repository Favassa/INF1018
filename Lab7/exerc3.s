.data
Sf: .string "%d\n"

.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    subq $8, %rsp

    movl $1, %ebx

loop3_start:
    cmpl $10, %ebx
    jg loop3_end

    movl %ebx, %eax
    imull %eax, %eax

    movq $Sf, %rdi
    movl %eax, %esi
    movl $0, %eax
    call printf

    incl %ebx
    jmp loop3_start

loop3_end:
    movl $0, %eax
    addq $8, %rsp
    popq %rbx
    leave
    ret