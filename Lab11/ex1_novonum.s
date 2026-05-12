.data
fmt_print: .string "numero: "
fmt_scanf: .string "%d"

.text
.globl novonum
novonum:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movq $fmt_print, %rdi
    movl $0, %eax
    call printf

    movq $fmt_scanf, %rdi
    leaq -4(%rbp), %rsi
    movl $0, %eax
    call scanf

    movl -4(%rbp), %eax

    leave
    ret