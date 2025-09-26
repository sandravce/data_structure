/* write a c program to merge two sorted arrays */

#include<stdio.h>
void display_array(int arr[],
int size) 
{
    for(int i=0; i<size; i++) 
    {
        printf("%d\n", arr[i]);
    }   
}

int main()
{
	int n,a[50],a2[50],i,b,j;
	printf("Enter how many elements you need to store to array 1:");
	scanf("%d",&n);
	
	if(n>50)
	{
		printf("Maximum number of elements which can be inserted into array 1 is 50.\n");
	}
	
	printf("Enter the elements :\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("The array is:\n"); // To print the array 1
	for(i=1;i<=n;i++)
	{
		printf("%d\n",a[i]);
	}	
	
	 // starting of array 2
	 
		printf("Enter how many elements you need to store to array 2:\n");
		scanf("%d",&b);
		
		if(n>50)
		{
			printf("Maximum number of elements which can be inserted into array 2 is 50.\n");
		}
		
		printf("Enter the elements :\n");
		for(i=1;i<=b;i++)
		{
			scanf("%d",&a2[i]);
		}
		printf("The array is:\n");// To print the array 2
		
		for(j=1;j<=b;j++)
		{
			printf("%d\n",a2[j]);
		}
		
}	
	
		
