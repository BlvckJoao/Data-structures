#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct hash{
        char* name;
        struct hash* next;
}Hash;


typedef struct hash_table {
        char* name;
        Hash* buckets[MAX_SIZE];
}HashTable;

void hash_init(HashTable *t);
int  hash_insert(HashTable *t, const char *name);
int  hash_lookup(HashTable *t, const char *name);
void hash_free(HashTable *t);

#endif