#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
using namespace std;

int longest_increasing_subsequence(int array[],int size_array)
{
	int temp_array[size_array];
	for(int a=0;a<size_array;a++)
	{
		temp_array[a] = 1;
	}
	for(int i=1;i<size_array;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(array[i]>array[j]&&temp_array[i]<temp_array[j]+1)
			{
				temp_array[i] = temp_array[j]+1;
			}
		}
	}
	return temp_array[size_array-1];
}

int main()
{
	int size_array;
	cout<<"LONGEST INCREASING SUBSEQUENCE\n";
	cout<<"Enter size of array : ";
	cin>>size_array;
	int array[size_array];
	for(int a=0;a<size_array;a++)
	{
		cout<<"Array["<<a<<"] : ";
		cin>>array[a];
	}
	cout<<"The size of longest increasing subsequence is "<<longest_increasing_subsequence(array,size_array)<<"\n";

}