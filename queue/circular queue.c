#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef struct{
    int front, rear;
    int item[MAXSIZE];
}queue;

void init(queue *q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(queue *q){
    return (q->front==-1);
}

int isFull(queue *q){
        return ((q->rear+1)%MAXSIZE ==q->front);
}

void insert(queue *q, int x){
    if(isFull(q)){
        printf("Queue is full.");
        return;
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear=(q->rear+1)%MAXSIZE;
    q->item[q->rear]=x;
    printf("Inserted : %d\n", x);
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.");
        return -1;
    }
    int value = q->item[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front=(q->front+1)%MAXSIZE;
    }
    printf("Removed : %d\n", value);
    return value;
}

int peek(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    return (q->item[q->front]);
}

int main(){
    queue q;
    init(&q);
    insert(&q, 5);
    insert(&q, 2);
    insert(&q, 8);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    insert(&q, 1);
    printf("current front : %d", peek(&q));
    return 0;
}