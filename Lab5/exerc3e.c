#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

struct X5 {
  char c1;
  char c2;
  char c3;
};

int main(void) {
  struct X5 x5 = {0xAA, 0xBB, 0xCC};
  printf("Tamanho de X5: %zu bytes\n", sizeof(struct X5));
  dump(&x5, sizeof(x5));
  return 0;
}