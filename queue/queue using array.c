#include <stdio.h>
#include <stdlib.h>

#define N 5
int queue[N];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Queue overflow.\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = -1;
    }
    printf("enqueued : %d\n", x);
    rear++;
    queue[rear]= x;
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue underflow.\n");
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    printf("dequeued : %d\n", queue[front]);
    front++;
}

void peek(){
    printf("Top : %d\n", queue[front]);
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue underflow.\n");
    }
    else{
        printf("Displaying the queue : ");
        int i = 0;
        for(i = front;i<rear+1;i++){
            printf("%d\t", queue[i]);
        }
    }
    printf("\n");
}

int main(){
    enqueue(5);
    enqueue(4);
    enqueue(2);
    enqueue(3);
    enqueue(1);
    enqueue(7);
    dequeue();
    dequeue();
    dequeue();
    display();
    peek();
    enqueue(5);
    display();
}