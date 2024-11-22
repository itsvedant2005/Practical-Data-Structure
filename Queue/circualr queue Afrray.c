#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;

// queue is full
int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}

//queue is empty
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Insert
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (front == -1)  // If inserting the first element
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

// Delete
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d from the queue\n", queue[front]);
        if (front == rear) {  //  one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Display 
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);  // Print the last element (rear)
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu:\t");
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
