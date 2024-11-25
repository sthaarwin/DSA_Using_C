#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
typedef struct{
    int data;
    int priority;
}Element;

typedef struct{
    Element elements[MAX_SIZE];
    int size;
}PriorityQueue;

void initQueue(PriorityQueue *pq){
    pq->size = 0;
}

int isEmpty(PriorityQueue *pq){
    return pq->size == 0;
}

int isFull(PriorityQueue *pq){
    return pq->size == MAX_SIZE;
}

 void enqueue(PriorityQueue *pq, int value, int priority){
    Element temp;
    temp.data = value;
    temp.priority = priority;
    
    if(isEmpty(pq)){
        pq->elements[0] = temp;
        pq -> size ++;
        return;
    }

    if (isFull(pq)){
        printf("Queue is full.\n");
        return;
    }

    int i;
    for(i = pq->size - 1; i >= 0; i--) {
        if(priority < pq->elements[i].priority) {
            pq->elements[i + 1] = pq->elements[i];
        } else {
            break;
        }
    }
    pq->elements[i + 1] = temp;
    pq ->size++;
 }

void display(PriorityQueue pq){
    int i = 0;
    while(i < pq.size){
        printf("%d priority (%d) -> ", pq.elements[i].data, pq.elements[i].priority);
        i++;
    }
    printf("null\n");
}

int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty.\n");
        exit(0);
    }
    int value = pq->elements[0].data;
    int i;
    for ( i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    pq->size--;
    return value;
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);
    enqueue(&pq, 5, 1);
    enqueue(&pq, 4, 3);
    enqueue(&pq, 3, 7);
    display(pq);
    printf("Dequeued: %d\n", dequeue(&pq));
    display(pq);
    printf("Dequeued: %d\n", dequeue(&pq));
    display(pq);
    return 0;
}