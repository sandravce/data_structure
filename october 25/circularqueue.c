// write a c program to implement circular queue operaions using array //
//1)Enqueue 2)Dequeue 3)Display //

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % MAX == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    printf("%d enqueued.\n", val);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("%d dequeued.\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\nMenu:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nChoose: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

}

