#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

union U2 {
  short s;
  char c[5];
};

int main(void) {
  union U2 u2; 
  u2.s = 0xAABB; 
  printf("Tamanho de U2: %zu bytes\n", sizeof(union U2));
  dump(&u2, sizeof(u2));
  return 0;
}