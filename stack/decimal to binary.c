#include<stdlib.h>
#include<stdio.h>

#define MAXSIZE 100

typedef struct stack{
    int top;
    int item[MAXSIZE];
}stack;

void initStack(stack *s){
    s->top=-1;
}

int isEmpty(stack *s){
    return (s->top == -1);
}

int isFull(stack *s){
    return(s->top>=MAXSIZE-1);
}

void push(stack *s, int x){
    if(!isFull(s)) s->item[++s->top]=x;
    else printf("stack is full.");
}

int pop(stack *s){
    if(!isEmpty(s)) return s->item[s->top--];
    else return 0;
}

int convert(int x){
    stack s;
    initStack(&s);
    while(x!=0){
        push(&s, x%2);
        x/=2;
    }
    int binary = 0;
    while(!isEmpty(&s)){
       binary*= 10;
       binary += pop(&s);
    }
    return binary;
}

int main(){
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    printf("Decimal : %d\nBinary : %d", num, convert(num));
    return 0;
}