#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

union U1 {
  int i;
  char c[5];
};

int main(void) {
  union U1 u1; 
  u1.i = 0xAABBCCDD; 
  printf("Tamanho de U1: %zu bytes\n", sizeof(union U1));
  dump(&u1, sizeof(u1));
  return 0;
}