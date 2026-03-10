#include <stdio.h>

void dump (void *p, int n) {
    unsigned char *p1 = p;
    while (n--) {
        printf("%p - %02x\n", p1, *p1);
        p1++;
    }
}

int main(void) {
    int i = 10000;
    printf("--- a) int (10000) ---\n");
    dump(&i, sizeof(i));

    long l = 10000L;
    printf("\n--- b) long (10000) ---\n");
    dump(&l, sizeof(l));

    short s = 10000;
    printf("\n--- c) short (10000) ---\n");
    dump(&s, sizeof(s));

    char c1 = 'a';
    char c2 = 97;
    printf("\n--- d) char ('a' e 97) ---\n");
    dump(&c1, sizeof(c1));
    dump(&c2, sizeof(c2));

    char str[] = "A a$";
    printf("\n--- e) string e ASCII ---\n");
    dump(str, sizeof(str));

    return 0;
}