#include<stdio.h>
#define max_size 5
int stack[max_size],top=-1;
void push(int item)
{

	if (top>=max_size-1)
		printf("Stack is full");
	else
	{
	
		printf("Enter the element to push: ");
		scanf("%d", &item);
		top=top+1;
		stack[top]=item;
	}
}
void pop()
{
	if(top==-1)
		printf("Stack is empty");
	else
	{
		printf("pop element is %d \n", stack[top]);
		top=top-1;
	}
}
void display()
{
	int i;
	for (i=top;i>-1;i--)
		printf("%d\n",stack[i]);
}
int main()
{
	int n,item;
	do
	{
		printf("\n 1. push \n 2. pop \n 3. dispaly \n 4. exit \n Enter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: push(item);
				break;
			case 2: pop();
				break;
			case 3: printf("Stack elements are:\n");
				display();
				break;
			default: printf("your choice is invalid");
				break;
		}	
	}while(n!=4);
return(0);
}
