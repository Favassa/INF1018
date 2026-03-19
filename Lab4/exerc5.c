#include <stdio.h>
/*


O "-1" é expandido para 32 bits. Por ter sinal, os bits novos são preenchidos com 1, virando 0xFFFFFFFF.
O 0xFFFFFFFF gerado passa a ser lido pela linguagem como unsigned int.
*/

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  signed char sc = -1;
  unsigned int ui = sc;
  
  printf("dump de ui:\n");
  dump(&ui, sizeof(ui));
  
  return 0;
}