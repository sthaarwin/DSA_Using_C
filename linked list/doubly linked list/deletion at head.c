#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete the head node of a doubly linked list
void deleteHead(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = temp->next;

    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }

    free(temp);
    printf("Head node deleted.\n");
}

// Function to push a new node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create a doubly linked list: 10 <-> 20 <-> 30
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    printf("Original list: ");
    printList(head);

    // Delete the head node
    deleteHead(&head);

    printf("List after deleting head: ");
    printList(head);

    return 0;
}