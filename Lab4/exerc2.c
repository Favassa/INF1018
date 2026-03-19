/*

Os valores impressos pelo dump são iguais (03 e 80) uma vez que a representação em bits de -32765 (em complemento a 2) 
e de 32771 (sem sinal) é exatamente a mesma na memória (0x8003).

*/
#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  short l = -32765;
  unsigned short k = 32771;
  printf("l=%d, k=%u \n", l, k);
  printf("dump de l: \n");
  dump(&l, sizeof(l));
  printf("dump de k: \n");
  dump(&k, sizeof(k));
  return 0;
}