#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

struct X3 {
  int i;
  char c1;
  char c2;
};

int main(void) {
  struct X3 x3 = {0xAABBCCDD, 0xEE, 0xFF};
  printf("Tamanho de X3: %zu bytes\n", sizeof(struct X3));
  dump(&x3, sizeof(x3));
  return 0;
}