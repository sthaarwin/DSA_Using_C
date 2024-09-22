#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct stack
{
    int top;
    char item[MAXSIZE];
} stack;

void initStack(stack *s)
{
    s->top = -1;
}

int isEmpty(stack *s)
{
    return (s->top == -1);
}

int isFull(stack *s)
{
    return (s->top >= MAXSIZE - 1);
}

void push(stack *s, char c)
{
    if (!isFull(s))
    {
        s->item[++s->top] = c;
    }
    else
    {
        printf("Stack is full, cannot push %c.\n", c);
    }
}

char pop(stack *s)
{
    if (!isEmpty(s))
    {
        return (s->item[s->top--]);
    }
    else
    {
        printf("Stack is empty, cannot pop. \n");
        return '\0';
    }
}

int isMatching(char open, char close)
{
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

int isBalanced(char *c){
    stack s;
    initStack(&s);
    int i;
    for(i = 0; c[i]!='\0';i++){
        if(c[i]== '('||c[i]== '{'||c[i]== '['){
            push(&s, c[i]);
        }
        
        else if(c[i]== ')'||c[i]== '}'||c[i]== ']'){
            if(isEmpty(&s) || !isMatching(pop(&s), c[i])){
                return 0;
            }
        }

    }
    return (isEmpty(&s));
}

int main(){
      char c[MAXSIZE];
    printf("Enter a string of parentheses: ");
    scanf("%s", c); 
    
    if(isBalanced(c)){
        printf("the given string contains balanced parantheses.\n");
    }
    else{
        printf("the given string doesn't contain balanced parantheses.\n");
    }
}