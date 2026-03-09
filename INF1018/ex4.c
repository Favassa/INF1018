#include <stdio.h>

void dump (void *p, int n);

int main() {
    char c1 = 1;
    char c2 = '1';
    int i = 1;
    char v[] = "1";

    printf("valor de c1: %d -> na memoria: ", c1);
    dump(&c1, sizeof(c1));
    printf("\n");

    printf("valor de c2: %d -> na memoria: ", c2);
    dump(&c2, sizeof(c2));
    printf("\n");

    printf("valor de i: %d -> na memoria: ", i);
    dump(&i, sizeof(i));
    printf("\n");

    printf("valor de v: %s -> na memoria: ", v);
    dump(v, sizeof(v));
    printf("\n");

    return 0;
}