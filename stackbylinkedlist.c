#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5
int counter=0;

struct stack
{
	int data;
	struct stack *link;
};
struct stack *top = NULL;

void push(int item)
{
	struct stack *newnode;
	newnode=(struct stack*)malloc(sizeof(struct stack));
	newnode->data=item;
	newnode->link=NULL;
	
	if(top == NULL)
	{
		top = newnode;
	}
	else
	{
		if(counter < MAX_SIZE)
		{
			newnode->link=top;
			top=newnode;
			counter=counter+1;
		}
		else
		{
			printf("stack is full")
		}
	}
	counter=counter+1;
}

void pop(int item)
{
	struct stack





}


