#include<stdio.h>
int main()
{
	int a[50],i,n,sum=0;
	printf("Enter how many numbers you want to store :");
	scanf("%d",&n);
	printf("Enter %d numbers:",n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			sum=sum+a[i];
		}
		
		printf("Sum of %d numbers are:%d\n",n,sum);
		return(0);
}
