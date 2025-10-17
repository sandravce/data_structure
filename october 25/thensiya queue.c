#include<stdio.h>
#define max_size 5
int queue[max_size],front=-1,rear=-1;
void enqueue(int item)
{
	if (rear>=max_size-1)
		printf("queue is full\n");
	if (front == -1) 
		front = 0;
	printf("Enter the element to insert: ");
	scanf("%d", &item);
	rear=rear+1;
	queue[rear]=item;
}
void dequeue() 
{
	if(front==-1)
		printf("queue is empty\n");
	else
	{
		printf("deleted element is %d \n", queue[front]);
		front=front+1;
	}
	if (front > rear) 
        	front = rear = -1;
}
void display()
{
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
}
int main()
{
	int n,item;
	do
	{
		printf("\n 1. insert \n 2. delete \n 3. dispaly \n 4. exit \n Enter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: enqueue(item);
				break;
			case 2: dequeue();
				break;
			case 3: printf("queue elements are:\n");
				display();
				break;
			default: printf("your choice is invalid");
				break;
		}	
	}while(n!=4);
return(0);
}
