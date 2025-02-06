#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct {
    int key;
    int value;
} HashItem;

HashItem hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = EMPTY;
        hashTable[i].value = 0;
    }
}

void insert(int key, int value) {
    int hashIndex = hashFunction(key);
    while (hashTable[hashIndex].key != EMPTY && hashTable[hashIndex].key != DELETED) {
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }
    hashTable[hashIndex].key = key;
    hashTable[hashIndex].value = value;
}

void delete(int key) {
    int hashIndex = hashFunction(key);
    while (hashTable[hashIndex].key != EMPTY) {
        if (hashTable[hashIndex].key == key) {
            hashTable[hashIndex].key = DELETED;
            hashTable[hashIndex].value = 0;
            return;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
    }
    printf("Key %d not found\n", key);
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != EMPTY && hashTable[i].key != DELETED) {
            printf("Key: %d, Value: %d\n", hashTable[i].key, hashTable[i].value);
        } else {
            printf("Key: -, Value: -\n");
        }
    }
}

int main() {
    initializeTable();
    insert(1, 10);
    insert(2, 20);
    insert(12, 30);
    insert(22, 40);

    printf("Hash table before deletion:\n");
    display();

    delete(12);
    printf("Hash table after deletion of key 12:\n");
    display();

    return 0;
}