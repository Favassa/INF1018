#include <stdio.h>
//Compara unsigned com int (4294967295 < 2). Sendo falso, imprime "não".

int main (void) {
  unsigned int x = 0xffffffff;
  int y = 2;
  printf("x=%u, y=%d\n", x, y);
  printf("x é menor do que y? %s\n", (x<y)?"sim":"nao");
  return 0;
}