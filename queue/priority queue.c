#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int priority;
    int data;
} Node;

typedef struct {
    Node *nodes;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->nodes = (Node*)malloc(sizeof(Node) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index) {
    if (index && pq->nodes[(index - 1) / 2].priority < pq->nodes[index].priority) {
        swap(&pq->nodes[index], &pq->nodes[(index - 1) / 2]);
        heapifyUp(pq, (index - 1) / 2);
    }
}

void heapifyDown(PriorityQueue *pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < pq->size && pq->nodes[left].priority > pq->nodes[largest].priority)
        largest = left;

    if (right < pq->size && pq->nodes[right].priority > pq->nodes[largest].priority)
        largest = right;

    if (largest != index) {
        swap(&pq->nodes[index], &pq->nodes[largest]);
        heapifyDown(pq, largest);
    }
}

void insert(PriorityQueue *pq, int priority, int data) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full\n");
        return;
    }

    pq->nodes[pq->size].priority = priority;
    pq->nodes[pq->size].data = data;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

Node extractMax(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    Node root = pq->nodes[0];
    pq->nodes[0] = pq->nodes[--pq->size];
    heapifyDown(pq, 0);

    return root;
}

int main() {
    PriorityQueue *pq = createPriorityQueue(10);

    insert(pq, 3, 30);
    insert(pq, 1, 10);
    insert(pq, 2, 20);
    insert(pq, 5, 50);

    printf("Extracted max: %d\n", extractMax(pq).data);
    printf("Extracted max: %d\n", extractMax(pq).data);
    printf("Extracted max: %d\n", extractMax(pq).data);
    printf("Extracted max: %d\n", extractMax(pq).data);

    free(pq->nodes);
    free(pq);

    return 0;
}