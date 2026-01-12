#include<stdio.h>

void display(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void sort(int arr[],int size)
{
	int i,j,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void merge(int arr1[],int size1,int arr2[],int size2,int merged[])
{
	int i;
	for(i=0;i<size1;i++)
	{
		merged[i]=arr1[i];
	}
	for(i=0;i<size2;i++)
	{
		merged[size1+i]=arr2[i];
	}
}

int main()
{
	int A[50],B[50],merged[100];
	int n1,n2,i;
	
	printf("Enter the size of first array :");
	scanf("%d",&n1);
	printf("Enter %d elements :",n1);
	for(i=0;i<n1;i++)
	{
		scanf("%d",&A[i]);
	}
	
	printf("Enter the size of second array :");
	scanf("%d",&n2);
	printf("Enter %d elements :",n2);
	for(i=0;i<n2;i++)
	{
		scanf("%d",&B[i]);
	}
		
		
sort(A,n1);
sort(B,n2);

merge(A,n1,B,n2,merged);
sort(merged,n1 + n2);

printf("Sorted merged array :");
display(merged,n1+n2);

return 0;
}