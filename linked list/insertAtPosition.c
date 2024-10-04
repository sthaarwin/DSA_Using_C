#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insertAtPosition(struct node** head, int value, int position){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if(position == 0 || *head == NULL){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    int i;
    for(i = 0; i<position-1&&temp->next!=NULL;i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("out of bounds.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void traverse(struct node* head){
    while(head!=NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

int main(){
    struct node* head = NULL;
    insertAtPosition(&head, 5, 0);
    traverse(head);
    insertAtPosition(&head, 3, 1);
    insertAtPosition(&head, 7, 2);
    traverse(head);
    insertAtPosition(&head, 6, 1);
    traverse(head);
    insertAtPosition(&head, 2, 0);
    traverse(head);
    return 0;
}