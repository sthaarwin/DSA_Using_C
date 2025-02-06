#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct HashTable {
    Entry *table[TABLE_SIZE];
} HashTable;

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

HashTable* create_table() {
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable *hashTable, const char *key, int value) {
    unsigned int index = hash(key);
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = hashTable->table[index];
    hashTable->table[index] = newEntry;
}

int search(HashTable *hashTable, const char *key) {
    unsigned int index = hash(key);
    Entry *entry = hashTable->table[index];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1; // Key not found
}

void free_table(HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *entry = hashTable->table[i];
        while (entry != NULL) {
            Entry *temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashTable);
}

int main() {
    HashTable *hashTable = create_table();
    insert(hashTable, "key1", 1);
    insert(hashTable, "key2", 2);
    insert(hashTable, "key3", 3);

    printf("Value for key1: %d\n", search(hashTable, "key1"));
    printf("Value for key2: %d\n", search(hashTable, "key2"));
    printf("Value for key3: %d\n", search(hashTable, "key3"));

    free_table(hashTable);
    return 0;
}