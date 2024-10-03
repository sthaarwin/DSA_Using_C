#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int main(){
    node* n1 = (node*)malloc(sizeof(node));
    node* n2 = (node*)malloc(sizeof(node));
    
    n1->data = 5;
    n1->next = n2;
    n2->data = 6;
    n2->next = NULL;

    printf("Node 1: %d\n", n1->data);
    printf("Node 2: %d\n", n2->data);
    free(n1);
    free(n2);
    return 0;
}   