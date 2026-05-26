#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>

#define PAGE_START(P) ((intptr_t)(P)&~(pagesize-1))
#define PAGE_END(P) (((intptr_t)(P)+pagesize-1)&~(pagesize-1))

/*
 * The execpage() function shall change the specified memory pages
 * permissions into executable.
 *
 * void *ptr = pointer to start of memory buff
 * size_t len = memory buff size in bytes
 *
 * The function returns 0 if successful and -1 if any error is encountered.
 * errno may be used to diagnose the error.
 */
int execpage(void *ptr, size_t len) {
    int ret;

    const long pagesize = sysconf(_SC_PAGE_SIZE);
    if (pagesize == -1)
        return -1;

    ret = mprotect((void *)PAGE_START(ptr),
        PAGE_END((intptr_t)ptr + len) - PAGE_START(ptr),
        PROT_READ | PROT_WRITE | PROT_EXEC);

    if (ret == -1)
        return -1;

    return 0;
}

#undef PAGE_START
#undef PAGE_END

typedef int (*funcp) (int x);

int main(void) {
    unsigned char codigo[] = {0x89, 0xf8, 0x83, 0xc0, 0x01, 0xc3};
    int i;
    funcp f;

    execpage(codigo, sizeof(codigo));

    f = (funcp)codigo;
    i = (*f)(10);
    
    printf("%d\n", i);
    
    return 0;
}