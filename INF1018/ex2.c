#include <stdio.h>
#include <stdlib.h>

float foo (float pf);

int main (int argc, char **argv) {
    float f;
    if (argc!=2) {
        exit(0);
    }
    f = atof(argv[1]);
    printf ("foo(%.2f): %.2f\n", f, foo(f));
    return 0;
}