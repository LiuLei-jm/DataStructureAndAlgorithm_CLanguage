#include "uthash.h"

typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} HashTable;

HashTable *hashtable;

HashTable *Find(int key)
{
    HashTable *tmp;
    HASH_FIND_INT(hashtable, &key, tmp);
    return tmp;
}

void Insert(int key, int val)
{
    HashTable *t = Find(key);
    if (t == NULL)
    {
        HashTable *tmp = malloc(sizeof(HashTable));
        tmp->key = key;
        tmp->val = val;
        HASH_ADD_INT(hashtable, key, tmp);
    }
    else
    {
        t->val = val;
    }
}
