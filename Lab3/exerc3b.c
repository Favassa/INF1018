#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n) {
    return (x << n) | (x >> (8 - n));
}

int main(void) {
    unsigned char val = 0x61; 
    
    printf("Rotaciona 1 bit: 0x%02X\n", rotate_left(val, 1));
    printf("Rotaciona 2 bits: 0x%02X\n", rotate_left(val, 2));
    printf("Rotaciona 7 bits: 0x%02X\n", rotate_left(val, 7));

    return 0;
}