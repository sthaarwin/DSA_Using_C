#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
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

// Function to insert a node in a left-skewed manner
struct Node* insertLeftSkewed(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    root->left = insertLeftSkewed(root->left, data);
    return root;
}

// Function to print the tree in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insertLeftSkewed(root, 10);
    root = insertLeftSkewed(root, 20);
    root = insertLeftSkewed(root, 30);
    root = insertLeftSkewed(root, 40);
    root = insertLeftSkewed(root, 50);

    printf("Inorder traversal of the left-skewed binary tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}