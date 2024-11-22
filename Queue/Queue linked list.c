#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert element into the queue
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        printf("Inserted %d into the queue\n", data);
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
    printf("Inserted %d into the queue\n", data);
}

// Function to delete an element from the queue
void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = *front;
    *front = (*front)->next;

    // If front becomes NULL, set rear to NULL as well
    if (*front == NULL) {
        *rear = NULL;
    }

    printf("Deleted %d from the queue\n", temp->data);
    free(temp);
}

// Function to display the elements of the queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, data;

    while (1) {
        printf("\nQueue Menu:\t");
        printf("1. Enqueue\t");
        printf("2. Dequeue\t");
        printf("3. Display\t");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
