#include <stdio.h>
#define MAX 10 /* MAX tem que ser maior que 0 !!! */

struct X {
  int val;
  struct X *next;
};

int add (struct X *x);

int main (void) {
  struct X a[MAX];
  int i;

  for (i=0; i<MAX; ++i)
    a[i].val = i;

  for (i=MAX-1; i>0; --i)
    a[i].next = &a[i-1];
  a[0].next = NULL;

  printf ("resultado do add: %d\n", add(&a[MAX-1]));
  return 0;
}