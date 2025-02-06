#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i) % TABLE_SIZE] != -1) {
        i++;
    }
    hashTable[(index + i) % TABLE_SIZE] = key;
}

int search(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i) % TABLE_SIZE] != -1) {
        if (hashTable[(index + i) % TABLE_SIZE] == key) {
            return (index + i) % TABLE_SIZE;
        }
        i++;
    }
    return -1;
}

int main() {
    initHashTable();
    
    insert(5);
    insert(15);
    insert(25);
    
    int key = 15;
    int result = search(key);
    if (result != -1) {
        printf("Key %d found at index %d\n", key, result);
    } else {
        printf("Key %d not found\n", key);
    }
    
    return 0;
}