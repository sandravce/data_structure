#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int s[MAX_SIZE], Top = -1;

// Push operation
int push() {
    int item;
    if (Top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow! Cannot push more elements.\n");
        return 0;
    } 
    else
    {
        printf("Enter the element to push onto the stack: ");
        scanf("%d", &item);
        Top++;
        s[Top] = item;
        printf("%d is pushed onto the stack.\n", item);
        return 1;
    }
}

// Pop operation
int pop() {
    int item;
    if (Top < 0) {
        printf("Stack Underflow! Stack is empty.\n");
        return 0;
    } else {
        item = s[Top];
        Top--;
        printf("The popped element is %d\n", item);
        return 1;
    }
}

// Display stack contents
int display() {
    if (Top < 0) {
        printf("Stack is empty.\n");
        return 0;
    } else {
        printf("Stack contents (top to bottom):\n");
        for (int i = Top; i >= 0; i--) {
            printf("%d\n", s[i]);
        }
        return 1;
    }
}

int main() 
{
    int choice;

    while (true) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
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

