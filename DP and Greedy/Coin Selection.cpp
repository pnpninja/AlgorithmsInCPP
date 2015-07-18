#include <iostream>
#include <stdlib.h>
using namespace std;

int min_coins(int total,int coins[],int nos_coins)
{
	int matrix[nos_coins][total+1];
	for(int a=0;a<nos_coins;a++)
	{
		for(int b=0;b<=total;b++)
		{
			if(b==0)
			{
				matrix[a][b] = 0;
			}
			else if(a==0)
			{
				matrix[a][b] = b;//ASSUMING DENOMINATION 1 IS ALWAYS PRESENT
			}
			else if(b<coins[a])
			{
				matrix[a][b] = matrix[a-1][b];
			}
			else
			{
				matrix[a][b] = matrix[a-1][b]<matrix[a][b-coins[a]]?matrix[a-1][b]:matrix[a][b-coins[a]]+1;
			}
		}
	}
	return matrix[nos_coins-1][total];
}
int compare(const void *a,const void *b)
{
	return (*(int *)a- *(int *)b);
}
int main()
{
	cout<<"COIN SELECTION\n(Note - Make sure denomination 1 exists)\n";
	int nos_coins;
	cout<<"Enter nos. of coins : ";
	cin>>nos_coins;
	int coins[nos_coins];
	cout<<"Enter the denominations : ";
	for(int a=0;a<nos_coins;a++)
	{
		cin>>coins[a];
	}
	int total;
	cout<<"Enter total : ";
	cin>>total;
	qsort(coins,nos_coins,sizeof(int),compare);
	cout<<"Minimum number of coins required is "<<min_coins(total,coins,nos_coins)<<endl;
}