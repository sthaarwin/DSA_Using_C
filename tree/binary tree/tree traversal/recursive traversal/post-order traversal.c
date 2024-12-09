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

// Function to perform post-order traversal
void postOrderTraversal(struct Node* node) {
    if (node == NULL) {
        return;
    }

    // Traverse the left subtree
    postOrderTraversal(node->left);

    // Traverse the right subtree
    postOrderTraversal(node->right);

    // Visit the root node
    printf("%d ", node->data);
}

int main() {
    // Creating a simple binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Post-order traversal of the binary tree is: ");
    postOrderTraversal(root);

    return 0;
}