/*
* https://leetcode.com/problems/multiply-strings/
*
* 2016/01/07
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mtab[][10] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
    0,  2,  4,  6,  8, 10, 12, 14, 16, 18,
    0,  3,  6,  9, 12, 15, 18, 21, 24, 27,
    0,  4,  8, 12, 16, 20, 24, 28, 32, 36,
    0,  5, 10, 15, 20, 25, 30, 35, 40, 45,
    0,  6, 12, 18, 24, 30, 36, 42, 48, 54,
    0,  7, 14, 21, 28, 35, 42, 49, 56, 63,
    0,  8, 16, 24, 32, 40, 48, 56, 64, 72,
    0,  9, 18, 27, 36, 45, 54, 63, 72, 81
};

char* multiply(char* num1, char* num2) {
    char *result = NULL, *w, *h, temp;
    int i, j, carry;
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    result = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
    memset(result, 0, l1 + l2 + 1);
    w = NULL;
    for (i = l2 - 1; i >= 0; i--) {
        w = result + l2 - i - 1;
        if (num2[i] == '0') { continue; }
        for (carry = 0, j = l1 - 1; j >= 0; j--, w++) {
            *w = (*w + carry + mtab[num2[i] - '0'][num1[j] - '0']);
            if (*w > 9) {
                carry = *w / 10;
                *w %= 10;
            }
            else { carry = 0; }
        }
        if (carry > 0) { *w++ = carry; }
    }
    while (w > result && *w == 0) w--;
    /* Reverse the string, and make them numbers*/
    for (h = result; h <= w; h++, w--) {
        temp = *h;
        *h = *w + '0';
        *w = temp + '0';
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("multiply <number1> <number2>\n");
        return 0;
    }
    char *sp = multiply(argv[1], argv[2]);
    printf("Product: %s\n", sp);
    free(sp);
    return 0;
}