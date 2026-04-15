#include <stdio.h>
#define MAX 10

struct X {
  int val;
  struct X *next;
};

int add2 (struct X *x);

int main (void) {
  struct X a[MAX];
  int i;

  for (i=0; i<MAX; ++i)
    a[i].val = i;

  for (i=MAX-1; i>0; --i)
    a[i].next = &a[i-1];
  a[0].next = NULL;

  printf ("resultado do add: %d\n", add2(&a[MAX-1]));
  return 0;
}