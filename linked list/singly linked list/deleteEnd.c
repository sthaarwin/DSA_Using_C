#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insert(struct node** head, int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteEnd(struct node** head){
    if(*head == NULL){
        printf("The list is empty.\n");
        return;
    }
    if((*head)->next == NULL){
        *head = NULL;
        return;
    }

    struct node* temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

void traverse(struct node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

int main(){
    struct node* head = NULL;
    deleteEnd(&head);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 5);
    printf("Before deletion : ");
    traverse(head);
    printf("After deletion : ");
    deleteEnd(&head);
    traverse(head);
    return 0;
}