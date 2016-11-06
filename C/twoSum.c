#include <stdlib.h>
#include <stdbool.h>

struct inthash {
    int key;
    int val;
    struct inthash* next;
};

#define DEFAULT_SIZE (8192)

unsigned int __ihm;
struct inthash* bucket;

void inthashCreate(unsigned int size) {
    int clz;
    struct inthash** bucket;
    if (size < 1) {
        size = DEFAULT_SIZE;
    }
    else {
        clz = __builtin_clz(size);
        size = 1 << (32 - clz);
    }
    __ihm = size - 1;
    bucket = (struct int**)malloc(sizeof(struct int)*size);
}

void inthashRelease() {

}

bool inthashPut(int key, int val) {

}

int inthashGet(int key) {

}

