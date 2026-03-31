#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;
  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

struct X6 {
  short s1;
  int i;
  char c[3];
  short s2;
};

int main(void) {
  struct X6 x6 = {0xAABB, 0xCCDDeeFF, {0x11, 0x22, 0x33}, 0x4455};
  printf("Tamanho de X6: %zu bytes\n", sizeof(struct X6));
  dump(&x6, sizeof(x6));
  return 0;
}