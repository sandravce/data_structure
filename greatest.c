#include<stdio.h>
int main()
{
int greatest=0,i=1,num;

while(i<=5)
{
	printf("Enter the number  :");
	scanf("%d",&num);	
}
	if(num>greatest)
	{
	greatest=num;
	i=i+1;
	}
		printf("The greatest number is :%d",greatest);
return(0);
}


