#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *next;
};

void banner() {
    system("clear");
    printf(" ___________________________________________ \n");
    printf("|                                           |\n");
    printf("|               NODE COUNTER                |\n");
    printf("|___________________________________________|\n");
}

int displayChoice() {
    printf("1. Insert into the list\n");
    printf("2. Remove from the list\n");
    printf("3. Reverse the list\n");
    printf("4. Display the list\n");
    printf("5. Count the node in the list\n");
    printf("6. Exit\n");
    printf("Enter your choice : ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

void insert(struct node **head, int value, int position) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 0 || *head == NULL) {
        newNode->next = *head;  
        *head = newNode;
        printf("Inserted at the head.\n");
        return;
    }

    struct node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) { 
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete(struct node **head, int position) {
    if (*head == NULL) {
        printf("Error!!! List is empty.\n");
        return;
    }

    struct node *temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        printf("Successfully removed the head.\n");
        return;
    }

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) { 
        printf("Invalid position.\n");
        return;
    }

    struct node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Successfully deleted.\n");
    free(nodeToDelete);
}

void reverse(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("Successfully reversed the list.\n");
}

void traverse(struct node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

int countNode(struct node *head) {
    int counter = 0;
    struct node *temp = head;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void Exit() {
    printf("Thank you for trying.\n");
}

int main() {
    int Continue = TRUE;
    struct node *head = NULL;

    while (Continue == TRUE) {
        banner();
        int choice = displayChoice();

        int value, position;
        switch (choice) {
            case 1:
                printf("Enter a number you want to insert: ");
                scanf("%d", &value);
                printf("Enter the position in which you want to insert: ");
                scanf("%d", &position);
                insert(&head, value, position);
                break;

            case 2:
                printf("Enter the position in which you want to delete: ");
                scanf("%d", &position);
                delete(&head, position);
                break;

            case 3:
                reverse(&head);
                break;

            case 4:
                traverse(head);
                break;

            case 5:
                printf("Current node count: %d\n", countNode(head));
                break;

            case 6:
                Continue = FALSE;
                break;

            default:
                printf("Out of bounds. Please choose a valid option.\n");
                break;
        }

        if (Continue) {
            printf("Do you want to continue? (1 for Yes, 0 for No): ");
            scanf("%d", &Continue);
        }
    }

    Exit();
    return 0;
}
