#include <stdio.h>
#include <stdlib.h>
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

void deleteAtPosition(struct node **head, int position)
{
    if (*head == NULL)
    {
        printf("the list is empty.\n");
        return;
    }
    if (position == 0)
    {
        *head = (*head)->next;
        return;
    }

    struct node *temp = *head;
    int i = 0;
    for (i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        printf("out of bounds.\n");
        return;
    }

    struct node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
}

void traversal(struct node *head)
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
    deleteAtPosition(&head, 1);

    printf("Before deletion : ");
    insert(&head, 2);
    insert(&head, 6);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 1);
    traversal(head);

    printf("After deletion : ");
    deleteAtPosition(&head, 1);

    traversal(head);
    return 0;
}