#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} HashItem;

HashItem* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;

    while (hashTable[hashIndex] != NULL && hashTable[hashIndex]->key != -1) {
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
        if (hashIndex == originalIndex) {
            printf("Hash table is full\n");
            return;
        }
    }

    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = (HashItem*) malloc(sizeof(HashItem));
    }

    hashTable[hashIndex]->key = key;
    hashTable[hashIndex]->value = value;
}

int search(int key) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;

    while (hashTable[hashIndex] != NULL) {
        if (hashTable[hashIndex]->key == key) {
            return hashTable[hashIndex]->value;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
        if (hashIndex == originalIndex) {
            break;
        }
    }

    return -1;
}

void delete(int key) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;

    while (hashTable[hashIndex] != NULL) {
        if (hashTable[hashIndex]->key == key) {
            hashTable[hashIndex]->key = -1;
            hashTable[hashIndex]->value = -1;
            return;
        }
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
        if (hashIndex == originalIndex) {
            break;
        }
    }

    printf("Key not found\n");
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL && hashTable[i]->key != -1) {
            printf("Key: %d, Value: %d\n", hashTable[i]->key, hashTable[i]->value);
        } else {
            printf("Key: ~, Value: ~\n");
        }
    }
}

int main() {
    insert(1, 10);
    insert(2, 20);
    insert(12, 30);
    insert(22, 40);

    display();

    printf("Value for key 2: %d\n", search(2));

    delete(2);
    display();

    return 0;
}