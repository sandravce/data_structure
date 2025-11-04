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
}

// Delete at front
void deleteAtFront()
{
	struct node*ptr;
	if (header == NULL)
	{
		printf("Deletion is not possible since there is no node.\n");
	}
	else
	{
		struct node *ptr;
		ptr = header;
		header = header->link;
		free(ptr);
	}
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
}

// Delete at end 
void deleteAtEnd()
{
	if(header == NULL)
    	{
        	printf("Deletion is not possible since there is no node.\n");
    	}
    	else
    	{
		struct node *ptr,*ptr1;
		ptr=ptr1=header;
		while(ptr->link!=NULL)
		{
			ptr=ptr1;
			ptr=ptr->link;
		}
		printf("Deleted element is %d",ptr->data);
		ptr->link=NULL;
		free(ptr);
	}
}


// Insert after a key
void insertAtAny(int key, int item) {
    struct node *ptr = header, *ptr1 = NULL, *newnode;

    while (ptr != NULL && ptr->data != key) {
        ptr1 = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key %d not found, insertion not possible.\n", key);
    } else {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->link = ptr->link;
        ptr->link = newnode;
        printf("Inserted %d after %d successfully\n", item, key);
    }
}

//Delete at any 


// Traverse and print
void traverselist() {
    struct node *ptr = header;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

// Main function
int main() 
{
	insertAtFront(10);
	insertAtFront(20);
	insertAtFront(30);
	insertAtFront(40);
	insertAtFront(50);

	printf("List after inserting at front:\n");
	traverselist();

	deleteAtFront();  
	printf("List after deleting at front:\n");
	traverselist();

	printf("List after inserting at end:\n");
	insertAtEnd(50);
	traverselist();

	printf("List after deleting at end :\n");
	deleteAtEnd();
	traverselist();
		
	printf("List after inserting after 30:\n");
	insertAtAny(30, 45);
	traverselist();

    return 0;
}


