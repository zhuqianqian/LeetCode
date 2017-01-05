#ifndef __HASH_H__
#define __HASH_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _hash_obj* hash_table;

typedef unsigned int uint;

typedef uint (*hashfunc)(void*);
typedef int (*equalfunc)(void*, void*);
typedef void (*clean)(void*);

hash_table hash_create(uint size, hashfunc hf, equalfunc ef);

void hash_free(hash_table h);

void hash_put(hash_table h, void* key, void* val);

void* hash_get(hash_table h, void* key);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __HASH_H__ */