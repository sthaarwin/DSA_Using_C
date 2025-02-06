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
    while (hashTable[(index + i * i) % TABLE_SIZE] != -1) {
        i++;
    }
    hashTable[(index + i * i) % TABLE_SIZE] = key;
}

void display() {
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
    display();
    return 0;
}