#include<stdio.h>

int parent[50],rank[50];

void makeSet(int x)
{
	parent[x]=x;
	rank[x]=0;
}

int findSet(int x)
{
	if(x != parent[x])
	{
		parent[x] = findSet(parent[x]);
	return parent([x]);
	}0
	
}

void link(int x, int y)
{
	if(x!=y)
	{
		if(rank[x]>rank[y])
		{
			parent[y]=x;0
		else
		{
			parent[x]=y;
		}
		if(rank[x] == rank[y])
		{
			rank[y] = rank[y] + 1;
		}
	
}

void unionSet(int x, int y)
{
	link(findSet(x), findSet(y))
}

int main()
{
	makeSet(0);
	makeSet(1);
	makeSet(2);
	makeSet(3);
	makeSet(4);
	makeSet(5);
	makeSet(6);
	
	unionSet(0,1);
	unionSet(1,2);
	unionSet(3,4);
	unionSet(5,6);
	unionSet(4,5);
	unionSet(2,6);
	
	for(int i=0; i<7; i++)
		printf("%d ", parent[i])
	return(0);
}



