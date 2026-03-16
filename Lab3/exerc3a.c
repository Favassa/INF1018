#include <stdio.h>

unsigned char switch_byte(unsigned char x) {
    return ((x & 0x0F) << 4) | (x >> 4);
}

int main(void) {
    unsigned char val = 0xAB;
    
    printf("Original: 0x%02X | Invertido: 0x%02X\n", val, switch_byte(val));
    
    return 0;
}