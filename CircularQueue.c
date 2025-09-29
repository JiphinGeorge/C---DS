#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum size of Circular Queue

int queue[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Insert an element into the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full! Cannot insert %d\n", value);
    } else {
        if (front == -1) // First element
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

// Delete an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty! Cannot delete.\n");
    } else {
        int data = queue[front];
        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("%d deleted from queue.\n", data);
    }
}

// Display elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

// Count elements in the circular queue
void countElements() {
    if (isEmpty()) {
        printf("Queue is Empty! Count = 0\n");
    } else {
        int count = (rear - front + SIZE) % SIZE + 1;
        printf("Total elements in queue: %d\n", count);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Count Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
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
                countElements();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
