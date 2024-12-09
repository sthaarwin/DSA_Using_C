#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
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

// Function to check if a tree is a full binary tree
int isFullBinaryTree(struct Node* root) {
    // If the tree is empty
    if (root == NULL)
        return 1;

    // If the tree has no children
    if (root->left == NULL && root->right == NULL)
        return 1;

    // If the tree has both children
    if (root->left != NULL && root->right != NULL)
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

    // If the tree has only one child
    return 0;
}

// Function to print the tree in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    if (isFullBinaryTree(root))
        printf("The tree is a full binary tree.\n");
    else
        printf("The tree is not a full binary tree.\n");

    return 0;
}