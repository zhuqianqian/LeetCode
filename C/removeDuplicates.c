#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * Always find the smallest letter before the last presence
 * of any letter. In other wors, it is a concatenation of 
 * sort of each segments that are separated by the last 
 * presence of a letter. <Greedy>.
 */
char* removeDuplicateLetters(char* s) {
    char* result = (char *)malloc(sizeof(char)*27);
    int count[128] = {0};
    char *p = s,
         *n = s,
         *w = result;
    while(*p) {count[*p]++; p++;}
    char small;
    while(*n) {
        small = 0x7f;
        for(p = n; *p && (count[*p] >= 1 || count[*p] < 0); p++) {               
            if (count[*p] > 0 && small > *p) { small = *p; n = p; }
            if (count[*p] == 1) { break; }            
            if (count[*p] > 0) { count[*p]--; }
        }
        p--;
        count[*n] = INT_MIN;
        while(p>n) count[*p--]++;
        *w++ = *n++;
        while(*n && count[*n] <= 0) n++;
    }
    *w = 0;
    return result;
}

/**
 * Loop through the source and push the letter on a
 * stack. Each time, before push the new letter, 
 * check if it is smaller than the ones in the stack
 * until when the top on the stack is the last one
 * in source string. The stack is thus always the 
 * answer to the string from start up to the current
 * examined letter. <Greedy>.
 */
char* removeDuplicateLetters2(char *s) {
    char* result = (char *)malloc(sizeof(char)*27);
    char* w;
    int count[128] = {0};
    int used[128] = {0};
    for(w = s; *w; w++) count[*w]++;
    for(w = result; *s; s++) {
        count[*s]--;
        if(used[*s]) { continue; }
        w--; 
        while(w >= result && *w > *s && count[*w] > 0) {
            used[*w] = 0; w--;
        }
        w++;
        *w++ = *s; used[*s] = 1; 
    }
    *w = 0;
    return result;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("removeDuplicateLetters <string>\n");
    return 0;
    }
    char boolStr[][8] = {"false", "true"};
    char* r = removeDuplicateLetters(argv[1]);
    char* r2 = removeDuplicateLetters2(argv[1]);
    printf("%s\t%s\tEqual=%s\n", r, r2, boolStr[!strcmp(r, r2)]);
    free(r); free(r2);
    return 0;
}
