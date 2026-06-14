#include <stdio.h>

float foo(double a, float b);

int main() {
    float res = foo(3.0, 2.0f);
    printf("%f\n", res);
    return 0;
}