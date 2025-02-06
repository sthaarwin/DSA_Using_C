#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; // -1 indicates that the cell is empty
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[index] = key;
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: \n", i);
        }
    }
}

int main() {
    initHashTable();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(45);
    insert(55);
    insert(65);
    insert(75);
    insert(85);
    insert(95);
    displayHashTable();
    return 0;
}