#include <iostream>
using namespace std;

int maximum_sum_subsequence(int array[],int size_array)
{
	int inclusive = array[0],exclusive=0;
	for(int i=1;i<size_array;i++)
	{
		int temp = inclusive;
		inclusive = (array[i]+exclusive)>inclusive?(array[i]+exclusive):inclusive;
		exclusive = temp;
	}
	return inclusive;
}

int main()
{
	int size_array;
	cout<<"MAXIMUM SUM SUBSEQUENCE WITH NON ADJACENT ELEMENTS\nEnter size of array : ";
	cin>>size_array;
	int array[size_array];
	cout<<"Enter the elements : ";
	for(int a=0;a<size_array;a++)
	{
		cin>>array[a];
	}
	cout<<"Output : "<<maximum_sum_subsequence(array,size_array)<<endl;

}