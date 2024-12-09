#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Stack structure
struct Stack {
    struct TreeNode* data;
    struct Stack* next;
};

// Function to create a new tree node
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to push an element onto the stack
void push(struct Stack** stack, struct TreeNode* node) {
    struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
    newStackNode->data = node;
    newStackNode->next = *stack;
    *stack = newStackNode;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return !stack;
}

// Function to pop an element from the stack
struct TreeNode* pop(struct Stack** stack) {
    if (isEmpty(*stack)) {
        return NULL;
    }
    struct Stack* temp = *stack;
    *stack = (*stack)->next;
    struct TreeNode* popped = temp->data;
    free(temp);
    return popped;
}

// Function for non-recursive in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    struct Stack* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = pop(&stack);
        printf("%d ", current->val);

        // Visit the right subtree
        current = current->right;
    }
}

// Main function to test the traversal
int main() {
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);

    printf("In-order traversal: ");
    inOrderTraversal(root);

    return 0;
}