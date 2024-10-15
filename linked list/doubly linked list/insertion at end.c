#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void insert(struct node** head, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = value;
    temp -> prev = NULL;
    temp -> next = NULL;

    if(*head == NULL){
        *head = temp;
        return;
    }

    struct node* last = *head;
    while(last -> next != NULL){
        last = last -> next;
    }
    last -> next = temp;
    temp -> prev = last;
    last = temp;
}

void print(struct node* head){
    while(head != NULL){
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("null\n");
}

int main(){
    struct node* head = NULL;
    print(head);
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 4);
    print(head);
    insert(&head, 7);
    insert(&head, 3);
    print(head);
    insert(&head, 1);
    print(head);
    return 0;    
}