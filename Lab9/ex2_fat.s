.text
.globl fat
fat:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    subq $8, %rsp
    
    movl %edi, %ebx
    cmpl $0, %ebx
    jne recursive_case
    
    movl $1, %eax
    jmp end_fat

recursive_case:
    movl %ebx, %edi
    subl $1, %edi
    call fat
    imull %ebx, %eax

end_fat:
    addq $8, %rsp
    popq %rbx
    leave
    ret