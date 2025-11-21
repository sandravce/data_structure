#include<stdio.h>
#include<ctype.h>
int i;
char univ_set[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

char set1[26], set2[26];
int bit_vect1[26], bit_vect2[26], result[26];

void initializeSet()
{
	//initialize the arrays bit_vect1, bit_vect2, result
	for(i=0; i<26; i++)
	{
		bit_vect1[i] = 0;
		bit_vect2[i] = 0;
		result[i] = 0;
	}
}

void bitvector(char ary[26], int bit[26], int num)
{
	//Represent the array in bitvector form
	for(int i=0; i<num ; i++)
	{
		for(int j=0; j<26; j++)
		{
			int c = toupper(ary[i]);
			if(c == univ_set[j])
			{
				bit[j] = 1;
			}
		}
	}
}

void setUnion(int bit1[26], int bit2[26])
{
	for(int i=0; i<26; i++)
	{
		result[i] = bit1[i]|bit2[i];
	}
}

void setIntersection(int bit1[26], int bit2[26])
{
	for(int i=0; i<26; i++)
	{
		result[i]=bit1[i]&bit2[i];
	}
}

void setCompliment(int bit[26])
{
	for(int i=0; i<26; i++)
	{
		if(bit[i] == 0)
		{
			result[i] = 1;
		}
		else
		{
			result[i]=0;
		}
	}
}

void setDifference(int bit1[26], int bit2[26])
{
	setCompliment(bit2);
	setIntersection(bit1, result);
}

int main()
{
	int num1,num2;
	initializeSet();
	bitvector(set1, bit_vect1, num1);
	bitvector(set2, bit_vect2, num2);
	setUnion(bit_vect1, bit_vect2);
	setIntersection(bit_vect1, bit_vect2);
	setCompliment(bit_vect1);
	setDifference(bit_vect1, bit_vect2);
	printf("Enter the number of elements in set 1 :");
	scanf(" %d",&num1);        //Get user inputs to Set 1
	printf("Enter the Set1 elements :");
	for(int i=0; i<num1; i++)
	{
		scanf(" %c",&set1[i]);
	}           
	printf("Enter the number of elements in set 2 :");
	scanf("%d",&num2);  //Get user inpuits to Set2 
	printf("Enter the Set2 elements :");
	for(int i=0; i<num2; i++)
	{
		scanf(" %c",&set2[i]);
	}

}
