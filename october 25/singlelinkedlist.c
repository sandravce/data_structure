#include<stdio.h>
#include<stdlib.h>
// "node" template structure
struct node
{
	int data;
	struct node *link;
};
struct node *header;
header=NULL;

void createnode()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data= 0;
	newnode->link=NULL;
	header=newnode;
}

int main()
{
	createnode();
	printf("Data:%d",);
	return(0);
}
