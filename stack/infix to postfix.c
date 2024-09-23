#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct stack {
    int top;
    char item[MAXSIZE];
} stack;

void init(stack *s) {
    s->top = -1;
}

int isEmpty(stack *s) {
    return (s->top == -1);
}

int isFull(stack *s) {
    return (s->top >= MAXSIZE - 1);
}

void push(stack *s, char c) {
    if (!isFull(s)) {
        s->item[++s->top] = c;
    } else {
        printf("Stack is full.\n");
    }
}

char pop(stack *s) {
    if (!isEmpty(s)) {
        return s->item[s->top--];
    } else {
        printf("Stack is empty.\n");
        return '\0';
    }
}

char peek(stack *s) {
    if (!isEmpty(s)) {
        return s->item[s->top];
    } else {
        printf("Stack is empty.\n");
        return '\0';
    }
}

int isAlNum(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '-' || c == '+') return 1;
    else if (c == '*' || c == '/') return 2;
    return 0;
}

void convert(char *infix, char *postfix) {
    int i = 0, j = 0;
    stack s;
    init(&s);
    for (i = 0; infix[i] != '\0'; i++) {
        if (isAlNum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s); 
            }
            push(&s, infix[i]);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s); 
    }
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAXSIZE], postfix[MAXSIZE];
    printf("Enter infix statement: ");
    scanf("%s", infix);
    convert(infix, postfix);
    printf("Postfix statement: %s\n", postfix);
    return 0;
}
