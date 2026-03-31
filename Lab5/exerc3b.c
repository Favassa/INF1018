#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

struct X2 {
  long l;
  char c;
};

int main(void) {
  struct X2 x2 = {0x1122334455667788, 0x99};
  printf("Tamanho de X2: %zu bytes\n", sizeof(struct X2));
  dump(&x2, sizeof(x2));
  return 0;
}