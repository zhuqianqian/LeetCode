#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

typedef bool(*fptr)(int);

/**
 * Count the 1s in the binary (aka, hamming weight)
 * Numbers that are power of 2 only have one 1.
 * 4ms / 1108 cases.
 */
bool isPowerOfTwo(int n) {
    int w = 0;
    unsigned int un = (unsigned int)n;
    if (n <= 0) return false;
    while (un) {
        w++;
        un &= (un - 1);
    }
    return w == 1;
}

/**
 * Inspired by the above method (calc hamming weight),
 * if the number n has only one 1, (n-1) should have
 * all 1s in the bits after the one and the first 1
 * set to 0. (That is to say, n&(n-1) should equal to 0.
 * 4ms / 1108 cases. (I thought this would be faster...)
 */
bool isPowerOfTwoB(int n) {
    return n < 1 ? false : (n&(n-1)) == 0;
}

/**
 * The direct way with recursion
 */
bool isPowerOfTwoR(int n) {
    if (n <= 1) return n == 1;
    return (n & 0x01) == 0 && isPowerOfTwoR(n / 2);
}

/**
 * The direct way with loop
 */
bool isPowerOfTwoL(int n) {
    while (n > 1 && !(n&0x01)) {  n = n / 2; }
    return n == 1;
}

bool isPowerOfThreeL(int n) {
    while (n > 1 && !(n%3)) {  n = n / 3; }
    return n == 1;
}

bool isPowerOfThree(int n) {
    return isPowerOfThreeL(n);
}

bool isPowerOfThreeR(int n) {
    if (n <= 1) return n == 1;
    return (n % 3) == 0 && isPowerOfThreeR(n / 3);
}


fptr funcs[] = { isPowerOfTwo, isPowerOfTwoB, isPowerOfTwoL, isPowerOfTwoR,
    isPowerOfThree, isPowerOfThreeL, isPowerOfThreeR};
char names[][16] = {"isPowerOfTwo", "isPowerOfTwoB", "isPowerOfTwoL", 
"isPowerOfTwoR", "isPowerOfThree", "isPowerOfThreeL", "isPowerOfThreeR" };
char result[][4] = { "FK", "OK" };

void unitTest() {
    fptr f;
    int i, j;
    char *fname;
    int nums[][10] = { { -2147483648, 0, 1, 6, 16, 128, 4096, 512, 65535, 65536 },
                       { -3, 0, 1, 6, 9, 27, 1162261467, 81, 6564, 6561 } };
    int eresult[] = { false, false, true, false, true, true, true, true, false, true };
    for (i = 0; i < 7; i++) {
        printf("Testing %s:", names[i]);
        for (f = funcs[i], j = 0; j < 10; j++) {
            printf("%s ", result[eresult[j] == f(nums[i/4][j])]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {    
    printf("Run unit Test:\n");
    unitTest();
    return 0;
}
