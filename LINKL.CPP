#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Element %d inserted at the end.\n", data);
}

// Function to insert at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        printf("Element %d inserted at position %d.\n", data, position);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range. Inserting element %d at the end.\n", data);
        insertEnd(head, data);
    } else {
        new_node->next = temp->next;
        temp->next = new_node;
        printf("Element %d inserted at position %d.\n", data, position);
    }
}



// Function to delete from a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, no node to delete.\n");
        return;
    }

    struct Node* temp = *head;

    // If the node to be deleted is the first node
    if (position == 1) {
        *head = temp->next;  // Change head
        printf("Element %d deleted from position %d.\n", temp->data, position);
        free(temp);  // Free the old head
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is greater than the number of nodes
    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of range.\n");
        return;
    }

    struct Node* next = temp->next->next;  // Node to be deleted
    printf("Element %d deleted from position %d.\n", temp->next->data, position);
    free(temp->next);  // Free memory
    temp->next = next;  // Unlink the deleted node
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu-driven interface
int main() {
    struct Node* head = NULL;
    int choice, value, pos;

    do {
        // Menu-driven options
        printf("\nMenu:\n");
        printf("1. Insert at the End\n");
        printf("2. Insert at a Specific Position\n");
        printf("3. Delete from a Specific Position\n");
        printf("4. Display the List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to insert at the end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter an element to insert at a specific position: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertAtPosition(&head, value, pos);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 4:
                printf("Linked List: ");
                display(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    getch();
}