#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform in-order traversal
void inOrderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }

    // Traverse the left subtree
    inOrderTraversal(node->left);

    // Visit the root
    printf("%d ", node->data);

    // Traverse the right subtree
    inOrderTraversal(node->right);
}

int main() {
    // Creating a simple binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order traversal of the binary tree is: ");
    inOrderTraversal(root);

    return 0;
}