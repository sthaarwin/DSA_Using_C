#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct stack{   
    int top;
    char item[MAXSIZE];
}stack;

void initStack(stack *s){
    s->top = -1;
}

int isEmpty(stack *s){
    return (s->top ==-1);
}

int isFull(stack *s){
    return(s->top >= MAXSIZE-1);
}

void push(stack *s, char c){
    if(!isFull(s)) s->item[++s->top] = c;
    else printf("stack is full.");
}

char pop(stack *s){
    if(!isEmpty(s)) return s->item[s->top--];
    else return '\0';
}

void reverse(char *c){
    int i;
    stack s;
    initStack(&s);
    for(i = 0; c[i] != '\0';i++){
        push(&s, c[i]);
    }

    printf("in reverse order : ");
    for(i = 0; c[i] != '\0'; i++){
        printf("%c", pop(&s));
    }
}

int main(){
    char str[MAXSIZE];
    printf("Enter a string: ");
    fgets(str, MAXSIZE, stdin);
    reverse(str);
    printf("\n"); 
    return 0;
}