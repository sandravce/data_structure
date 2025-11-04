#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *link;
};

struct node *header = NULL;

// Insert at front
void insertAtFront(int item) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = header;
    header = newnode;
    printf("Inserted %d at the front.\n", item);
}

// Insert at end
void insertAtEnd(int item) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;

    if (header == NULL) {
        header = newnode;
    } else {
        struct node *ptr = header;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
    printf("Inserted %d at the end.\n", item);
}

// Insert after a specific key
void insertAtAny(int key, int item) {
    struct node *ptr = header, *newnode;

    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key %d not found, insertion not possible.\n", key);
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->link = ptr->link;
        ptr->link = newnode;
        printf("Inserted %d after %d successfully.\n", item, key);
    }
}

// Delete at front
void deleteAtFront() {
    if (header == NULL) {
        printf("Deletion is not possible since there is no node.\n");
    } else {
        struct node *ptr = header;
        printf("Deleted element is %d\n", ptr->data);
        header = header->link;
        free(ptr);
    }
}

// Delete at end
void deleteAtEnd() {
    if (header == NULL) {
        printf("Deletion is not possible since there is no node.\n");
    } 
    else if (header->link == NULL) {
        printf("Deleted element is %d\n", header->data);
        free(header);
        header = NULL;
    }
    else {
        struct node *ptr = header;
        struct node *prev = NULL;

        while (ptr->link != NULL) {
            prev = ptr;
            ptr = ptr->link;
        }

        printf("Deleted element is %d\n", ptr->data);
        prev->link = NULL;
        free(ptr);
    }
}

// Delete by key
void deleteAtAny(int key) {
    struct node *ptr = header, *prev = NULL;

    while (ptr != NULL && ptr->data != key) {
        prev = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key %d not found, Deletion not possible.\n", key);
    } else {
        printf("Deleted element is %d\n", ptr->data);

        if (prev != NULL)
            prev->link = ptr->link;   // middle or last node
        else
            header = ptr->link;       // first node

        free(ptr);
    }
}

// Search for an element
void search(int key) {
    struct node *ptr = header;
    int pos = 1, found = 0;

    while (ptr != NULL) {
        if (ptr->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            found = 1;
            break;
        }
        ptr = ptr->link;
        pos++;
    }

    if (!found)
        printf("Element %d not found in the list.\n", key);
}

// Traverse and print
void traverselist() {
    struct node *ptr = header;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Current List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, item, key;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Key\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at End\n");
        printf("6. Delete by Key\n");
        printf("7. Search Element\n");
        printf("8. Traverse List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &item);
                insertAtFront(item);
                break;

            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &item);
                insertAtEnd(item);
                break;

            case 3:
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insertAtAny(key, item);
                break;

            case 4:
                deleteAtFront();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteAtAny(key);
                break;

            case 7:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 8:
                traverselist();
                break;

            case 9:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

