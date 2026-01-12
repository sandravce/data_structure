#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *link;
};

struct node *top;

void display()
{
	struct node *ptr;
	if(top == NULL)
		printf("\nStack is empty..");
	else
	{
		ptr=top;
		printf("Stack elements are :");
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
	}
}

void push(int item)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=top;
	top=newnode;
	display();
}

void pop()
{
	struct node *temp;
	if(top==NULL)
		printf("Stack is empty..");
	else
	{
		temp=top;
		printf("Popped element is %d\n",top->data);
		top=top->link;
		free(temp);
	}
	display();
}

int main()
{
	int choice,item;
	do
	{
		printf("\n====STACK MENU====\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("Enter the data to be inserted :");
			scanf("%d",&item);
			push(item);
			break;
			
			case 2:pop();
			break;
			
			case 3:display();
			break;
			
			case 4:printf("Exiting program ....");
			break;
			
			default:printf("Invalid choice ..Try again..");
			break;			
		}
	}while(choice !=4);
}