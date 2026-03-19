#include <stdio.h>
//Compara int com int (-1 < 2). Sendo verdadeiro, imprime "sim".

int main (void) {
  int x = 0xffffffff;
  int y = 2;
  printf("x=%d, y=%d\n", x, y);
  printf("x é menor do que y? %s\n", (x<y)?"sim":"nao");
  return 0;
}