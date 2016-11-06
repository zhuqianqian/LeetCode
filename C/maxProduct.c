/*
 * https://leetcode.com/problems/maximum-product-of-word-lengths/
 * Given a string array words, find the maximum value of
 * length(word[i]) * length(word[j]) where the two words do not 
 * share common letters. You may assume that each word will contain
 * only lower case letters. If no such two words exist, return 0.
 *
 * 2015/12/21
 */
 
#include <stdio.h>
#include <stdlib.h>

int maxProduct(char** words, int wordsSize) {
    int* lengths = (int *)malloc(wordsSize * sizeof(int));
    unsigned int * masks = (unsigned int*)malloc(wordsSize * sizeof(int));
    
    /*Pre-process the words into two arrays: one is the array of lengths of
     *the words and the other is the bit-representation of the words.
     */
    char *str;
    int i, j, result;
    
    for (i = 0; i < wordsSize; i++) {
        lengths[i] = 0;
        masks[i] = 0;
        for (str = *(words + i); *str; str++) {
            lengths[i]++;
            masks[i] |= (1 << (*str - 'a'));
        }
    }
    result = 0;
    for (i = 0; i < wordsSize; i++) {
        for (j = i + 1; j < wordsSize; j++) {
            if (!(masks[i] & masks[j]) && lengths[i] * lengths[j] > result) {
                result = lengths[i] * lengths[j];
            }
        }
    }
    free(lengths);
    free(masks);
    return result;
}

int main(int argc, char **argv) {
    char ** s = argv + 1;
    printf("Maxp product of word lengths: %d\n", maxProduct(s, argc - 1));
    return 0;
}
