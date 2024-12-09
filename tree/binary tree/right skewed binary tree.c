#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
struct Node {
    int data;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the right-skewed binary tree
struct Node* insertRightSkewed(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    root->right = insertRightSkewed(root->right, data);
    return root;
}

// Function to print the right-skewed binary tree
void printRightSkewed(struct Node* root) {
    struct Node* current = root;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->right;
    }
    printf("NULL\n");
}

// Main function to demonstrate the right-skewed binary tree
int main() {
    struct Node* root = NULL;
    root = insertRightSkewed(root, 10);
    root = insertRightSkewed(root, 20);
    root = insertRightSkewed(root, 30);
    root = insertRightSkewed(root, 40);
    root = insertRightSkewed(root, 50);

    printf("Right-Skewed Binary Tree:\n");
    printRightSkewed(root);

    return 0;
}