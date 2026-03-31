#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

struct X1 {
  char c1;
  int i;
  char c2;
};

int main(void) {
  struct X1 x1 = {0xAA, 0xBBCCDDee, 0xFF};
  printf("Tamanho de X1: %zu bytes\n", sizeof(struct X1));
  dump(&x1, sizeof(x1));
  return 0;
}