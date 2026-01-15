#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>  // size_t

typedef struct HashMapEntry {
    char *key;                  
    void *value;                
    struct HashMapEntry *next;  
} HashMapEntry;


typedef struct HashMap {
    HashMapEntry **buckets;
    size_t bucket_count;    
    size_t size;            /* number of stored entries */
} HashMap;

HashMap *hashmap_create(size_t bucket_count);

/* Destroy the hash map and free all internal memory (keys + entries) */
void hashmap_destroy(HashMap *map);

/*
 * Returns:
 *  0 on success
 * -1 if key already exists
 * -2 on allocation failure
 */
int hashmap_put(HashMap *map, const char *key, void *value);

/* Get the value associated with a key, or NULL if not found */
void *hashmap_get(const HashMap *map, const char *key);

/*
 * Returns:
 *  0 on success
 * -1 if key not found
 */
int hashmap_remove(HashMap *map, const char *key);

/* Returns 1 if key exists, 0 otherwise */
int hashmap_contains(const HashMap *map, const char *key);

/* Returns the number of stored entries */
size_t hashmap_size(const HashMap *map);

#endif /* HASHMAP_H */
