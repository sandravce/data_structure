#include<stdio.h>
int main()
{
int num;
printf("Enter the number:");
scanf("%d",&num);
if (num%2==0)
{
	printf("%d is a even number");
}
else
{
	printf("%d is a odd number\n");
}
return(0);
}
