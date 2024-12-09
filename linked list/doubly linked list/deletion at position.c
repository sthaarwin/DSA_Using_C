#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to delete a node at a given position
void deleteNodeAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        return;
    }

    struct Node* current = *head_ref;

    // Traverse to the node at the given position
    for (int i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }

    // If the position is more than the number of nodes
    if (current == NULL) {
        return;
    }

    // If the node to be deleted is the head node
    if (*head_ref == current) {
        *head_ref = current->next;
    }

    // Change next only if the node to be deleted is NOT the last node
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    // Change prev only if the node to be deleted is NOT the first node
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    // Free the memory occupied by the node
    free(current);
}

// Function to push a node at the beginning
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

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

    // Create a doubly linked list: 10 <-> 8 <-> 4 <-> 2
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("Original list: ");
    printList(head);

    // Delete node at position 2
    deleteNodeAtPosition(&head, 2);

    printf("Modified list: ");
    printList(head);

    return 0;
}