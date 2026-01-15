#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "utils.h"

// djb2 Hash function
static size_t hash_function(const char *str, size_t bucket_count) {
    unsigned long hash = 5381; // magic number
    int c;

    while ((c = (unsigned char)*str++)) //Continues until NULL
        hash = ((hash << 5) + hash) + c; //hash * 33 + current char

    return hash % bucket_count;
}


HashMap *hashmap_create(size_t bucket_count) {
    if (bucket_count == 0){
        return NULL;
    } 

    HashMap *map = malloc(sizeof(HashMap));
    if (!map){
        return NULL;
    } 

    map->buckets = calloc(bucket_count, sizeof(HashMapEntry *)); //set buckets to NULL
    if (!map->buckets) {
        free(map);
        return NULL;
    }

    map->bucket_count = bucket_count;
    map->size = 0;

    return map;
}


void hashmap_destroy(HashMap *map) {
    if (!map){
        return;
    } 

    for (size_t i = 0; i < map->bucket_count; i++) {
        HashMapEntry *entry = map->buckets[i];
        while (entry) {
            HashMapEntry *next = entry->next;
            free(entry->key); // Have to free key because created new when added to playlist
            free(entry);
            entry = next;
        }
    }

    free(map->buckets);
    free(map);
}


int hashmap_put(HashMap *map, const char *key, void *value) {
    if (!map || !key){
        return -2;
    } 

    char *lc_key = lowercase(key);
    if (!lc_key){
        return -2;
    }

    size_t index = hash_function(lc_key, map->bucket_count);
    HashMapEntry *entry = map->buckets[index];


    while (entry) {
        if (strcmp(entry->key, lc_key) == 0) {
            free(lc_key);
            return -1; /* key already exists */
        }
        entry = entry->next;
    }

    /* Create new entry */
    HashMapEntry *new_entry = malloc(sizeof(HashMapEntry));
    if (!new_entry) {
        free(lc_key);
        return -2;
    }

    new_entry->key = lc_key;  // store lowercase key
    new_entry->value = value;

    /* Insert at head of bucket list */
    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;

    map->size++;
    return 0;
}


void *hashmap_get(const HashMap *map, const char *key) {
    if (!map || !key) return NULL;

    char *lc_key = lowercase(key);
    if (!lc_key) return NULL;

    size_t index = hash_function(lc_key, map->bucket_count);
    HashMapEntry *entry = map->buckets[index];

    while (entry) {
        if (strcmp(entry->key, lc_key) == 0) {
            free(lc_key);
            return entry->value;
        }
        entry = entry->next;
    }

    free(lc_key);
    return NULL;
}


int hashmap_remove(HashMap *map, const char *key) {
    if (!map || !key){
        return -1;
    } 

    char *lc_key = lowercase(key);
    if (!lc_key){
        return -1;
    }

    size_t index = hash_function(lc_key, map->bucket_count);
    HashMapEntry *entry = map->buckets[index];
    HashMapEntry *prev = NULL;

    while (entry) {
        if (strcmp(entry->key, lc_key) == 0) {
            if (prev) {
                prev->next = entry->next;
            } else {
                map->buckets[index] = entry->next;
            }
            free(entry->key);
            free(entry);
            map->size--;
            free(lc_key);
            return 0;
        }
        prev = entry;
        entry = entry->next;
    }

    free(lc_key);
    return -1;
}


int hashmap_contains(const HashMap *map, const char *key) {
    return hashmap_get(map, key) != NULL;
}


size_t hashmap_size(const HashMap *map) {
    if (!map){
        return 0;
    }
    return map->size;
}
