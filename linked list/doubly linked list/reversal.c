#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to reverse the doubly linked list
void reverse(struct Node** head_ref) {
    struct Node* temp = NULL;
    struct Node* current = *head_ref;

    // Swap next and prev for all nodes of the doubly linked list
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing the head, check for the cases like empty list and list with only one node
    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

// Function to push a node at the beginning of the doubly linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test the above functions
int main() {
    struct Node* head = NULL;

    // Create the doubly linked list: 10<->8<->4<->2
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("Original list: ");
    printList(head);

    // Reverse the doubly linked list
    reverse(&head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}