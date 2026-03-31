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

struct X4 {
  struct X2 x;
  char c;
};

int main(void) {
  struct X4 x4 = {{0x1122334455667788, 0x99}, 0xAA};
  printf("Tamanho de X4: %zu bytes\n", sizeof(struct X4));
  dump(&x4, sizeof(x4));
  return 0;
}