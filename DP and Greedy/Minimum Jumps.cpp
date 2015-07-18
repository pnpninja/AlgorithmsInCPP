#include <iostream>
#include <limits.h>
using namespace std;

void min_jumps(int array[],int size_array)
{
	int nos_jumps_array[size_array];
	int source_array[size_array];
	source_array[0] = -1;
	nos_jumps_array[0] = 0;
	for(int i=1;i<size_array;i++)
	{
		nos_jumps_array[i] = INT_MAX;
		for(int j=0;j<i;j++)
		{
			if(j+array[j]>=i&&nos_jumps_array[j]+1<nos_jumps_array[i])
			{
				source_array[i] = j;
				nos_jumps_array[i] = nos_jumps_array[j]+1;
			}
		}
	}
	int step=source_array[size_array-1];
	cout<<endl<<"The steps taken are "<<size_array-1<<"->";
	while(step!=-1)
	{	if(step!=0)
			cout<<step<<"->";
		else
			cout<<step;
		step = source_array[step];
	}
	cout<<endl;
}

int main()
{
	int size_array;
	cout<<"MINIMUM JUMPS\n";
	cout<<"Enter size of array : ";
	cin>>size_array;
	int array[size_array];
	cout<<"Enter the max steps that can be taken from each position in array : ";
	for(int a=0;a<size_array;a++)
	{
		cin>>array[a];
	}
	min_jumps(array,size_array);
	return 0;
}