#include <iostream>
#include <stdlib.h>
using namespace std;

struct sack
{
	int weight;
	int value;
};

int compare(const void *a,const void *b)
{
	struct sack *t1 = (struct sack*)a;
	struct sack *t2 = (struct sack*)b;
	return (t1->weight-t2->weight);
}
int max(int a,int b)
{
	return a>b?a:b;
}
int knapsack_recursive(int W,struct sack all_sacks[],int nos)
{
	if(nos==0||W==0)
	{
		return 0;
	}
	if(all_sacks[nos-1].weight>W)
	{
		return knapsack_recursive(W,all_sacks,nos-1);
	}
	else
	{
		return max(all_sacks[nos-1].value+knapsack_recursive(W-all_sacks[nos-1].weight,all_sacks,nos-1),knapsack_recursive(W,all_sacks,nos-1));
	}
}

int knapsack_non_recursive(int W,struct sack all_sacks[],int nos)
{
	int matrix[nos+1][W+1];
	for(int a=0;a<=nos;a++)
	{
		for(int b=0;b<=W;b++)
		{
			if(a==0||b==0)
			{
				matrix[a][b] = 0;
			}
			else if(all_sacks[a-1].weight>W)
			{
				matrix[a][b] = matrix[a-1][b];
			}
			else
			{
				matrix[a][b] = max(matrix[a-1][b],all_sacks[a-1].value+matrix[a-1][b-all_sacks[a-1].weight]);
			}
		}
	}
	return matrix[nos][W];
}

int main()
{
	cout<<"0-1 KNAPSACK PROBLEM\n";
	int nos;
	cout<<"Enter number of weights and values : ";
	cin>>nos;
	struct sack all_sacks[nos];
	for(int a=0;a<nos;a++)
	{
		cout<<"Enter weight and value of sack "<<a+1<<" : ";
		cin>>all_sacks[a].weight>>all_sacks[a].value;
	}
	int weight;
	cout<<"Enter maximum weight : ";
	cin>>weight;
	qsort(all_sacks,nos,sizeof(struct sack),compare);
	cout<<"The maximum value in knapsack is "<<knapsack_recursive(weight,all_sacks,nos)<<"\n";
}