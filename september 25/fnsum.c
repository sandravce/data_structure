#include<stdio.h>
int add(int,int);
int add(int a,int b)
{
int result;
result=a+b;
return(result);
}
	int main()
	{
	int a,b,result;
	printf("Enter the first number to add:");
	scanf("%d",&a);
	printf("Enter the second number to add:");
	scanf("%d",&b);
	result=add(a,b);
	printf("sum is %d\n",result);
	return(0);
	}	                
