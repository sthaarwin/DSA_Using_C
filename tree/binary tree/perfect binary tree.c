#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
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

// Function to check if a binary tree is perfect
int isPerfect(struct Node* root, int depth, int level) {
    if (root == NULL) {
        return 1;
    }
    if (root->left == NULL && root->right == NULL) {
        return (depth == level + 1);
    }
    if (root->left == NULL || root->right == NULL) {
        return 0;
    }
    return isPerfect(root->left, depth, level + 1) && isPerfect(root->right, depth, level + 1);
}

// Function to find the depth of the leftmost node
int findDepth(struct Node* node) {
    int depth = 0;
    while (node != NULL) {
        depth++;
        node = node->left;
    }
    return depth;
}

// Main function to check if the tree is perfect
int isPerfectBinaryTree(struct Node* root) {
    int depth = findDepth(root);
    return isPerfect(root, depth, 0);
}

// Function to print the tree in-order
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    if (isPerfectBinaryTree(root)) {
        printf("The binary tree is perfect.\n");
    } else {
        printf("The binary tree is not perfect.\n");
    }

    printf("In-order traversal of the tree: ");
    inOrder(root);
    printf("\n");

    return 0;
}