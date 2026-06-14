#include <stdio.h>
#include <math.h>

double foo3(double *a, int n);

int main() {
    double arr[3];
    double res;
    
    arr[0] = 0.0;
    arr[1] = M_PI_2;
    arr[2] = M_PI;
    
    res = foo3(arr, 3);
    printf("%f\n", res);
    
    return 0;
}