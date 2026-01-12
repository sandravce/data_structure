#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *link;
};

struct node *head=NULL;

void display()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("List is empty..");
	}
	else
	{
		ptr=head;
		printf("Elements are :");
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
	}
}

void InsertAtFront(int item)
{
	struct node *newnode,*ptr;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=head;
	head=newnode;
	display();
}

void InsertAtEnd(int item)
{
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        ptr = head;
        while(ptr->link != NULL)   
        {
            ptr = ptr->link;
        }
        ptr->link = newnode;      
    }
    display();
}



void InsertAtAny(int key, int item)
{
    struct node *newnode, *ptr;

    if(head == NULL)
    {
        printf("List is empty. Insertion not possible.");
        return;
    }

    ptr = head;
    while(ptr != NULL && ptr->data != key)
    {
        ptr = ptr->link;
    }

    if(ptr == NULL)
    {
        printf("Search key not found. Insertion not possible.");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->link = ptr->link;
        ptr->link = newnode;  
    }

    display();
}

void DeleteAtFront()
{
	struct node *temp;
	if(head == NULL)
		printf("List is empty . Deletion is not possible .");
	else
	{
		temp=head;
		head=head->link;
		free(temp);
	}
	display();
}

void DeleteAtEnd()
{
	struct node *prev,*curr,*temp;
	if(head == NULL)
		printf("List is empty . Deletion is not possible.");
	else if(head->link==NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
	}
	else
	{
		prev=head;
		curr=head->link;
		while(curr->link!=NULL)
		{
			prev=curr;
			curr=curr->link;
		}
		prev->link=NULL;
		free(curr);
	}
	display();
}

void DeleteAtAny(int key)
{
	struct node *prev,*curr,*temp;
	if(head == NULL)
		printf("List is empty. Deletion is not possible .");
	else if(head->link==NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
	}
	else
	{
		prev=head;
		curr=head;
		while(curr->data!=key && curr->link!=NULL)
		{
			prev=curr;
			curr=curr->link;
		}
		if(curr->data!=key)
		{
			printf("Search element not found . Deletion is not possible .");
		}
		else
		{
			prev->link=curr->link;
			free(curr);
		}
	}
	display();
}

void Search(int key)
{
	struct node *ptr;
	int pos=1;
	if(head == NULL)
	{
		printf("List is empty . Searching is not possible .");
		return;
	}
	ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->data==key)
			{
				printf("Element %d is found at %d position",key,pos);
				return;
			}
			ptr=ptr->link;
			pos++;
		}
	printf("Element %d not found in list .",key);
}

int main()
{
	int choice,item,key;
	do
	{
		printf("\n-----Linked List Menu------\n 1.InsertAtFront\n 2.InsertAtEnd\n 3.InsertAtAny\n 4.DeleteAtFront\n 5.DeleteAtEnd\n 6.DeleteAtAny\n 7.Search\n 8.Display\n 9.Exit\n");
		
		printf("\nEnter the choice :");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:printf("Enter the new data :");
			scanf("%d",&item);
			InsertAtFront(item);
			break;
			
			case 2:printf("Enter the new data :");
			scanf("%d",&item);
			InsertAtEnd(item);
			break;
			
			case 3:printf("Enter key before to insert :");
			scanf("%d",&key);		
			printf("Enter the new data :");
			scanf("%d",&item);
			InsertAtAny(key,item);
			break;
			
			case 4:DeleteAtFront();
			break;
			
			case 5:DeleteAtEnd();
			break;
			
			case 6:printf("Enter the key element to delete : ")
			scanf("%d",&key);
			DeleteAtAny(key);
			break
			
			case 7:printf("Enter the element to search :");
			scanf("%d",&key);
			Search(key);
			break;
			
			case 8:display();
			break;

			case 9:printf("Exiting program....");
			break;
			
			default:printf("Invalid choice .Please enter choice from 1 - 5 ");
		}
	}while(choice!=9);
	return 0;
}
