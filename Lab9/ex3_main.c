#include <stdio.h>

void foo(int a[], int n);

int main(void) {
    int arr[] = {1, 2, 0, 4, 5, 0};
    int n = 6;
    int i;
    
    foo(arr, n);
    
    for (i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}