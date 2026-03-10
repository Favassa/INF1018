#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int base) {
    int a = 0;
    for (; *s; s++) {
        int val;
        
        if (*s >= '0' && *s <= '9') {
            val = *s - '0'; 
        } else if (*s >= 'a' && *s <= 'z') {
            val = *s - 'a' + 10; 
        } else if (*s >= 'A' && *s <= 'Z') {
            val = *s - 'A' + 10; 
        } else {
            break; 
        }
        
        a = a * base + val;
    }
    return a;
}

int main (void) {
    printf("--- Testes Base < 10 ---\n");
    printf("777 base 8  -> Decimal: %d\n", string2num("777", 8));
    printf("777 base 10 -> Decimal: %d\n\n", string2num("777", 10));

    printf("--- Testes Base > 10 ---\n");
    printf("1a base 16   -> Decimal: %d\n", string2num("1a", 16));
    printf("a09b base 16 -> Decimal: %d\n", string2num("a09b", 16));
    printf("z09b base 36 -> Decimal: %d\n", string2num("z09b", 36));

    return 0;
}