#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

// Function to insert an element into the queue
void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is full! Cannot insert %d.\n", value);
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Function to delete an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Nothing to dequeue.\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        front++;
        if (front > rear) {  // Reset the queue if empty
            front = rear = -1;
        }
    }
}

// Function to display the queue
void display() {
    if (front == -1)
        printf("Queue is empty!\n");
    else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    
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
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
