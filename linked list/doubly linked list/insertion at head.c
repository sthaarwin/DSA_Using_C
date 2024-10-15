#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

void insert(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = value;
    temp -> next = NULL;
    temp -> prev = NULL;

    if(head == NULL){
        head = temp;
        return;
    }

    head -> prev = temp;
    temp -> next = head;
    head = temp;
}

void print(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("null\n");
}

int main(){
    print();
    insert(6);
    insert(2);
    print();
    insert(3);
    insert(5);
    insert(7);
    print();
    return 0;
}
