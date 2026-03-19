#include <stdio.h>
//Compara int com unsigned. A linguagem converte automaticamente o int (-1) para unsigned (4294967295) antes de comparar. Sendo falso, imprime "não".

int main (void) {
  int x = 0xffffffff;
  unsigned int y = 2;
  printf("x=%d, y=%u\n", x, y);
  printf("x é menor do que y? %s\n", (x<y)?"sim":"nao");
  return 0;
}