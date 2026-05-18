#include <stdio.h>

void printBits(int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int countOnes(int n) {
    int count = 0;
    while (n != 0) {
        count += (n & 1);
        n = n >> 1;
    }
    return count;
}

void checkEndian() {
    int x = 1;
    char *c = (char*)&x;

    if (*c == 1)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");
}

void printFloatBits(float f) {
    int *p = (int*)&f;
    printBits(*p);
}

int main() {
    int num = 5;

    printf("Bits of %d:\n", num);
    printBits(num);

    printf("Number of 1s: %d\n", countOnes(num));

    checkEndian();

    printf("Bits of negative integer (-5):\n");
    printBits(-5);

    printf("Bits of float (3.5):\n");
    printFloatBits(3.5);

    printf("Bits of negative float (-3.5):\n");
    printFloatBits(-3.5);

    return 0;
}
