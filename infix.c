#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 100

int operandStack[MAXSIZE];
char operatorStack[MAXSIZE];
int topOperand = -1, topOperator = -1;

void pushOperand(int value) {
    operandStack[++topOperand] = value;
}

int popOperand() {
    return operandStack[topOperand--];
}

void pushOperator(char op) {
    operatorStack[++topOperator] = op;
}

char popOperator() {
    return operatorStack[topOperator--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

void evaluateTop() {
    int b = popOperand();
    int a = popOperand();
    char op = popOperator();
    pushOperand(applyOperation(a, b, op));
}

int evaluateInfix(char* exp) {
    int i = 0;
    
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            pushOperand(exp[i] - '0');
        } else if (exp[i] == '(') {
            pushOperator('(');
        } else if (exp[i] == ')') {
            while (operatorStack[topOperator] != '(') {
                evaluateTop();
            }
            popOperator();
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            while (topOperator != -1 && precedence(operatorStack[topOperator]) >= precedence(exp[i])) {
                evaluateTop();
            }
            pushOperator(exp[i]);
        }
        i++;
    }
    
    while (topOperator != -1) {
        evaluateTop();
    }
    
    return popOperand(); 
}

int main() {
    char exp[] = "2+(3-5)";
    printf("Result: %d\n", evaluateInfix(exp));
    return 0;
}
