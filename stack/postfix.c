#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

int isDigitCustom(char c)
{
    return (c >= '0' && c <= '9');
}

void push(int x)
{
    if (top >= MAXSIZE - 1)
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int evaluatePostfix(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (isDigitCustom(exp[i]))
        {
            push(exp[i]-'0');
        }
        else
        {
            int op1 = pop();
            int op2 = pop();
            switch (exp[i])
            {
            case '+':
                push(op2 + op1);
                break;
            case '-':
                push(op2 - op1);
                break;
            case '*':
                push(op2 * op1);
                break;
            case '/':
                push(op2 / op1);
                break;
            }
        }
        i++;
    }
    return pop();
}

int main()
{
    char exp[] = "231*+9-";
    printf("Value of %s is %d\n", exp, evaluatePostfix(exp));
    return 0;
}
