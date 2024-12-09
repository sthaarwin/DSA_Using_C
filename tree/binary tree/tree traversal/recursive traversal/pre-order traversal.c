#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform pre-order traversal
void preOrderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    // Print the data of the node
    printf("%d ", node->data);

    // Recur on the left subtree
    preOrderTraversal(node->left);

    // Recur on the right subtree
    preOrderTraversal(node->right);
}

// Main function to test the pre-order traversal
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Pre-order traversal of binary tree is: ");
    preOrderTraversal(root);

    return 0;
}