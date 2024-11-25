#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct
{
    int front, rear;
    int data[MAXSIZE];
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue *q)
{
    return (q->rear == MAXSIZE - 1);
}

int isEmpty(Queue *q)
{
    return (q->front > q->rear);
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }
    q->data[++q->rear] = value;
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    q->front++;
    if (q->front > q->rear)
    {
        initQueue(q);
    }
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d -> ", q->data[i]);
    }
    printf("null\n");
}

int main()
{
    Queue q;
    initQueue(&q);

    display(&q);
    enqueue(&q, 4);
    enqueue(&q, 1);
    display(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 7);
    display(&q);
    dequeue(&q);          
    display(&q);

    return 0;
}
