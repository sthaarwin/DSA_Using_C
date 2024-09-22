#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 10

typedef struct stack
{
    int top;
    int item[MAXSIZE];
}stack;

void initStack(stack *s){
    s-> top = -1;
}

bool isEmpty(stack *s){
    return (s->top<0);
}

bool isFull(stack *s){
    return (s->top>=MAXSIZE-1);
}

void push(stack *s, int x){
    if(isFull(s)){
        printf("Stack is full\n");
        return;
    }
    s->item[++s->top]=x;
}

void pop(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    s->top--;
}

int peek(stack *s){
    if(isEmpty(s)){
        printf("The stack is empty\n");
        return -1;
    }
    else{
    return s->item[s->top];
    }
}

int main(){
    stack s;
    initStack(&s);
    push(&s, 5);
    push(&s, 10);
    push(&s, 15);
    printf("Top element is %d\n", peek(&s));
    pop(&s);
    printf("Top element is %d\n", peek(&s));
    return 0;
}