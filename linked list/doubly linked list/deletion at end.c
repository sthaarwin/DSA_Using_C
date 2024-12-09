#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to delete the node at the end of the doubly linked list
void deleteAtEnd(struct Node** head_ref) {
    // If the list is empty, return
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Find the last node
    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // If the list has only one node
    if (temp->prev == NULL) {
        *head_ref = NULL;
    } else {
        temp->prev->next = NULL;
    }

    // Free the memory of the last node
    free(temp);
    printf("Node deleted at the end.\n");
}

// Function to push a new node at the beginning of the list
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

// Main function to test the deletion at end function
int main() {
    struct Node* head = NULL;

    // Create a doubly linked list: 10<->20<->30<->40
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    printf("Original list: ");
    printList(head);

    // Delete the node at the end
    deleteAtEnd(&head);

    printf("List after deletion at end: ");
    printList(head);

    return 0;
}