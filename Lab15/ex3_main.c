#include <stdio.h>
#include <math.h>

double foo2(float a, float b);

int main() {
    double res = foo2((float)M_PI_2, (float)M_PI);
    printf("%f\n", res);
    return 0;
}