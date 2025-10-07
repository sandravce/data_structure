#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue operation
int enqueue() {
    int item;
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue more elements.\n");
        return 0;
    } else {
        printf("Enter the element to enqueue: ");
        scanf("%d", &item);
        if (front == -1) {  // First element
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("%d is enqueued into the queue.\n", item);
        return 1;
    }
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return 0;
    } else {
        int item = queue[front];
        if (front == rear) {  // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("The dequeued element is %d\n", item);
        return 1;
    }
}

// Display queue contents
int display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return 0;
    } else {
        printf("Queue contents (front to rear):\n");
        int i = front;
        while (1) {
            printf("%d\n", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX_SIZE;
        }
        return 1;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Enter the correct choice.\n");
        }
    }

    return 0;
}


