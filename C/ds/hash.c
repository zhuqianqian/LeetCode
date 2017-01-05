#include "hash.h"
#include <stdlib.h>

typedef struct hash_node {
    void* key;
    void* value;
    struct hash_node* next;
} hnode, *hnode_ptr;

typedef struct _hash_obj {
    hnode_ptr* array;
    hashfunc hash;
    equalfunc equals;
    uint size;
    float load_factor; /* not used right now */
}* hash_table;

hash_table hash_create(uint size, hashfunc hf, equalfunc ef) {
    if (size < 1u) {
        return NULL;
    }
    hash_table ht = (hash_table)malloc(sizeof(struct _hash_obj));
    ht->array = (hnode_ptr*)malloc(sizeof(hnode_ptr)*size);
    if (ht->array == NULL) {
        return NULL;
    }
    memset(ht->array, 0, sizeof(hnode_ptr)*size);
    ht->load_factor = 0.75f;
    ht->hash = hf;
    ht->equals = ef;
    ht->size = size;
    return ht;
}

void hash_put(hash_table h, void* key, void* value) {
    uint hk = h->hash(key) % h->size;

    hnode_ptr node = h->array[hk];
    if (node != NULL) {
        while (node->next) node = node->next;
        node->next = (hnode_ptr)malloc(sizeof(hnode));
        node = node->next;
    }
    else {
        h->array[hk] = node = (hnode_ptr)malloc(sizeof(hnode));
    }
    node->key = key;
    node->value = value;
    node->next = NULL;
}

void* hash_get(hash_table ht, void* key) {
    uint index = ht->hash(key) % ht->size;
    hnode_ptr node = ht->array[index];
    while (node != NULL && ht->equals(key, node->key) == 0) {
        node = node->next;
    }
    return node == NULL? NULL : node->value;
}

void hash_free(hash_table ht) {
    hnode_ptr t;
    if (ht != NULL) {
        for (int i = 0; i < ht->size; i++) {
            hnode_ptr node = ht->array[i];
            while (node != NULL) {
                t = node;
                node = node->next;
                /* call cleanup function for key and 
                 * value, ignored for now
                 */
                free(t);
            }
        }
        free(ht->array);
    }
    free(ht);
}
