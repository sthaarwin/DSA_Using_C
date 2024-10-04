#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void insertAtBegining(struct node**head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void traverse(struct node* head){
    while(head!=NULL){
        printf("%d -> ", head->data);
        head= head->next;
    }
    printf("null\n");
}

int main(){
    struct node* head =NULL;
    insertAtBegining(&head, 5);
    traverse(head);
    insertAtBegining(&head, 3);
    traverse(head);
    insertAtBegining(&head, 7);
    traverse(head);
    return 0;
}
