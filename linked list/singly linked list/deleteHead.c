#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteHead(struct node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    *head = (*head)->next;
}

void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

int main(){
    struct node* head = NULL;
    deleteHead(&head);
    printf("Before deletion : ");
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 4);
    insert(&head, 3);
    traverse(head);

    printf("After deletion : ");
    deleteHead(&head);
    traverse(head);
}