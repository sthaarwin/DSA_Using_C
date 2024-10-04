#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head, int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp ->next = newNode;
}
void traversal(struct node *head){
    while(head!=NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

int main(){
    struct node* head = NULL;
    insertAtEnd(&head, 6);
    traversal(head);
    insertAtEnd(&head, 4);
    traversal(head);
    insertAtEnd(&head, 3);
    traversal(head);
    return 0;
}