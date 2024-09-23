#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct stack
{
    int top;
    int item[MAXSIZE];
} stack;

void init(stack *s)
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

void push(stack *s, int c)
{
    if (!isFull(s))
    {
        s->item[++s->top] = c;
    }
    else
    {
        printf("Stack is full.\n");
    }
}

int pop(stack *s)
{
    if (!isEmpty(s))
    {
        return s->item[s->top--];
    }
    else
    {
        printf("Stack is empty.\n");
        return -1;
    }
}

int peek(stack *s)
{
    if (!isEmpty(s))
    {
        return s->item[s->top];
    }
    else
    {
        printf("Stack is empty.\n");
        return -1;
    }
}

void sort(stack *s)
{
    stack t;
    init(&t);
    while (!isEmpty(s))
    {
        int current = pop(s);
        while (!isEmpty(&t) && peek(&t) > current)
        {
            push(s, pop(&t));
        }
        push(&t, current);
    }
    while (!isEmpty(&t))
    {
        push(s, pop(&t));
    }
}

int main()
{
    stack s;
    init(&s);
    int val;

    while (1)
    {
        printf("Enter a value to push to stack: ");
        scanf("%d", &val);
        push(&s, val);

        printf("Enter 1 to exit, 0 to continue: ");
        scanf("%d", &val);
        if (val == 1)
        {
            break;
        }
    }

    sort(&s);
    printf("Sorted order: ");
    while (!isEmpty(&s))
    {
        printf("%d ", pop(&s));
    }
    printf("\n");

    return 0;
}
