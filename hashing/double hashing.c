#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(int hash_table[], int key) {
    int index = hash1(key);
    int step_size = hash2(key);

    while (hash_table[index] != -1) {
        index = (index + step_size) % TABLE_SIZE;
    }

    hash_table[index] = key;
}

void display(int hash_table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != -1) {
            printf("%d -> %d\n", i, hash_table[i]);
        } else {
            printf("%d -> \n", i);
        }
    }
}

int main() {
    int hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = -1;
    }

    insert(hash_table, 5);
    insert(hash_table, 25);
    insert(hash_table, 15);
    insert(hash_table, 35);
    insert(hash_table, 95);

    display(hash_table);

    return 0;
}