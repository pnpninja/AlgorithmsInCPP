#include <iostream>
#include <limits.h>
using namespace std;

int matrix_chain_multiplication_cost(int array[],int i,int j)
{
	if(i==j)
	{
		return 0;
	}
	else
	{
		int min = INT_MAX;
		for(int a=i;a<j;a++)
		{
			int temp = matrix_chain_multiplication_cost(array,i,a)+matrix_chain_multiplication_cost(array,i+1,j)+(array[i-1]*array[a]*array[j]);
			if(temp<min)
			{
				min = temp;
			}
		}
		return min;
	}
}

int main()
{
	int nos;
	cout<<"MATRIX CHAIN MULTIPLICATION\nEnter the length of array : ";
	cin>>nos;
	int array[nos];
	cout<<"Enter the values : ";
	for(int a=0;a<nos;a++)
	{
		cin>>array[a];
	}
	cout<<"Minimum cost of matrix chain multiplication is "<<matrix_chain_multiplication_cost(array,1,nos-1)<<endl;
}