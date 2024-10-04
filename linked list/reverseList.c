#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insert(struct node** head, int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode ->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp ->next = newNode;
}

void reverseList(struct node** head){
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 1);
    insert(&head, 7);
    insert(&head, 2);
    insert(&head, 4);

    printf("Before reversal : ");
    traverse(head);

    printf("After traversal : ");
    reverseList(&head);
    traverse(head);

    return 0;
}