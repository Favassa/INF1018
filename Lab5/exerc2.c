#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

struct X {
  int a;
  short b;
  int c;
} x = {0xa1a2a3a4, 0xb1b2, 0xc1c2c3c4};

int main(void) {
  printf("Tamanho da struct X: %zu bytes\n\n", sizeof(struct X));
  printf("Dump da memoria de x:\n");
  dump(&x, sizeof(x));
  
  return 0;
}