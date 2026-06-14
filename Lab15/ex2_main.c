#include <stdio.h>
#include <math.h>

float foo1(float a, float b);

int main() {
    float res = foo1((float)M_PI_2, 1.0f);
    printf("%f\n", res);
    return 0;
}