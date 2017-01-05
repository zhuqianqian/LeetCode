#include <stdlib.h>
#include "hash.h"
#include <string.h>
#include <stdio.h>
uint str_hash(const char* key) {
    int h = 0;
    while (*key) {
        h += *key * 31;
        key++;
    }
    return h;
}

int str_equal(char* s1, char* s2) {
    return 0 == strcmp(s1, s2);
}

int main(int argc, char** argv) {
    hash_table ht = hash_create(1024, str_hash, str_equal);
    hash_put(ht, "one", "I");
    hash_put(ht, "two", "II");
    hash_put(ht, "three", "III");
    char* one = hash_get(ht, "one");
    char* two = hash_get(ht, "two");
    char* three = hash_get(ht, "three");
    if (strcmp("I", one) != 0 ||
        strcmp("II", two) != 0 ||
        strcmp("III", three) != 0) {
        printf("ERROR");
    }
    return 0;
}