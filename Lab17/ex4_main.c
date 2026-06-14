#include <stdio.h>

struct X1 {
    int v1;
    float vf;
};

double foo(double a, int b);
double pack1(struct X1 *px, int n);

int main(void) {
    struct X1 arr[3] = {
        {2, 1.5f},
        {-1, 3.0f},
        {4, 2.5f}
    };
    
    printf("%f\n", pack1(arr, 3));
    return 0;
}