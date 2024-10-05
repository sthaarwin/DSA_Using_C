#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void push(struct node **top, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}
void pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow.\n");
        return;
    }
    struct node *temp = *top;
    *top = (*top)->next;
    free(temp);
}
int peek(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    return top->data;
}
void display(struct node *top){
    while(top != NULL){
        printf("%d -> ", peek(top));
        top = top->next;
    }
    printf("null\n");
}
int main(){
    struct node* stack = NULL;
    printf("Before push operation : ");
    pop(&stack);
    push(&stack, 4);
    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 5);
    push(&stack, 8);
    push(&stack, 7);
    printf("After push operation : ");
    display(stack);
    pop(&stack);
    printf("After pop operation : ");
    display(stack);
    return 0;
}