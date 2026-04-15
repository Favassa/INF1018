#include <stdio.h>

struct X {
  int val1;
  int val2;
};

void boo (struct X *px, int n, int val);

int f(int i, int v) {
  if (i == v)
    return 1;
  else
    return 0;
}

int main (void) {
  struct X a[3] = {{1,0}, {2,0}, {3,0}};
  int i;

  printf("Antes:\n");
  for (i=0; i<3; ++i)
    printf (" (%d,%d) ", a[i].val1, a[i].val2);
  
  boo(a, 3, 2);
  
  printf("\nDepois:\n");
  for (i=0; i<3; ++i)
    printf (" (%d,%d) ", a[i].val1, a[i].val2);
  printf("\n");
  
  return 0;
}