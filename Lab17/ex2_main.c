#include <stdio.h>

double foo(double a, int b);

int main(void) {
    printf("%f\n", foo(2.5, 3));
    printf("%f\n", foo(-1.5, -4));
    return 0;
}