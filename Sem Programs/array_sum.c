#include<stdio.h>
 int main()
 {
	 int num,A[50],i,sum=0;
	 do
	 {
		 printf("How many elements you want to store (max 50) :");
		 scanf("%d",&num);
		 
		 if(num > 50)
			 printf("Not enough space ..Try again..\n");
	 }while(num > 50);
	 
	 printf("Enter %d elements :",num);
	 for(i=0; i<num; i++)
	 {
		 scanf("%d",&A[i]);
		 sum=sum+A[i];
	 }
	 
	 printf("Sum of %d elements are %d:",num,sum);
 }
 
 