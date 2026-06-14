#include <stdio.h>

struct X {
    int v1;
    double vd;
    struct X *next;
};

double foo(double a, int b);
double pack(struct X *px);

int main(void) {
    struct X elem3 = {2, 1.5, NULL};
    struct X elem2 = {-1, 3.0, &elem3};
    struct X elem1 = {4, 2.5, &elem2};
    
    printf("%f\n", pack(&elem1));
    return 0;
}