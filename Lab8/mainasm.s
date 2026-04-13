.data
nums: .int 3, -5, 7, 8, -2
s1:   .string "%d\n"

.text
.globl main
main:
/* prologo */
 pushq %rbp
 movq %rsp, %rbp
 subq $16, %rsp
 movq %rbx, -8(%rbp)
 movq %r12, -16(%rbp)

/* coloque seu codigo aqui */
 movl $0, %ebx
 movq $nums, %r12

loop:
 cmpl $5, %ebx
 jge fim_loop

 movl (%r12), %edi
 movl $1, %esi
 call filtro

 movq $s1, %rdi
 movl %eax, %esi
 movl $0, %eax
 call printf

 addq $4, %r12
 incl %ebx
 jmp loop

fim_loop:
 movl $0, %eax

/* finalizacao */
 movq -8(%rbp), %rbx
 movq -16(%rbp), %r12
 leave
 ret