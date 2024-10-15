#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue underflow.\n");
        return;
    }
    struct node *temp = front;
    if (front == rear)
    {
        front = rear = NULL;
        free(temp);
        return;
    }
    front = front ->next;
    free(temp);
}

void print(){
    struct node* temp = front;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp ->next;
    }
    printf("null\n");
}

int main()
{
    print();
    dequeue();
    enqueue(5);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    enqueue(8);
    print();
    dequeue();
    print();
    dequeue();
    print();
    enqueue(7);
    print();
}