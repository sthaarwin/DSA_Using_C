#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse a circular linked list
void reverse(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    struct Node *prev = NULL, *current = *head_ref, *next = NULL;
    struct Node *head = *head_ref;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    head->next = prev;
    *head_ref = prev;
}

// Function to push a node to the circular linked list
void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data = data;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
    } else {
        new_node->next = new_node;
    }

    *head_ref = new_node;
}

// Function to print nodes in a given circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    printf("Original Circular Linked List: \n");
    printList(head);

    reverse(&head);

    printf("Reversed Circular Linked List: \n");
    printList(head);

    return 0;
}