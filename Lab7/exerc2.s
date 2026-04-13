.data
S2: .byte 65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0
fmt: .string "%c"
fmt_nl: .string "\n"

.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    subq $8, %rsp

    movq $S2, %rbx

loop_start:
    movb (%rbx), %al
    testb %al, %al
    je loop_end

    cmpb $123, %al
    je skip_print
    cmpb $125, %al
    je skip_print

    movsbl %al, %esi
    movq $fmt, %rdi
    movl $0, %eax
    call printf

skip_print:
    incq %rbx
    jmp loop_start

loop_end:
    movq $fmt_nl, %rdi
    movl $0, %eax
    call printf

    movl $0, %eax
    addq $8, %rsp
    popq %rbx
    leave
    ret