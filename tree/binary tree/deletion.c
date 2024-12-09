#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
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

// Function to find the minimum value node in a tree
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Function to delete a node from the binary tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to test the deletion
int main() {
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("Inorder traversal of the given tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}