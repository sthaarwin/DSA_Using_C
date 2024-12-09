#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Definition for a queue node.
struct QueueNode {
    struct TreeNode *treeNode;
    struct QueueNode *next;
};

// Definition for a queue.
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Function to create a new tree node.
struct TreeNode* createTreeNode(int val) {
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node.
struct QueueNode* createQueueNode(struct TreeNode *treeNode) {
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue.
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty.
int isQueueEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

// Function to enqueue a tree node.
void enqueue(struct Queue *queue, struct TreeNode *treeNode) {
    struct QueueNode *newNode = createQueueNode(treeNode);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue a tree node.
struct TreeNode* dequeue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    struct QueueNode *temp = queue->front;
    struct TreeNode *treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

// Function to perform level-order traversal of a binary tree.
void levelOrderTraversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    struct Queue *queue = createQueue();
    enqueue(queue, root);
    while (!isQueueEmpty(queue)) {
        struct TreeNode *current = dequeue(queue);
        printf("%d ", current->val);
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
    printf("\n");
}

// Main function to test the level-order traversal.
int main() {
    struct TreeNode *root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->left = createTreeNode(6);
    root->right->right = createTreeNode(7);

    printf("Level-order traversal of the binary tree:\n");
    levelOrderTraversal(root);

    return 0;
}