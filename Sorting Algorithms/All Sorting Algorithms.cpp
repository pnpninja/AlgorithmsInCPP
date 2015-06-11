#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#define clear() printf("\033[H\033[J")
using namespace std;

void view_array(int arr[],int size_arr)
{
	char temp;
	cout<<"Elements are : ";
	for(int a=0;a<size_arr;a++)
	{
		cout<<arr[a]<<" ";
	}
	cout<<"\nPress Y to return : ";
	cin>>temp;
	while(temp!='Y')
	{
		cout<<"Press Y to return : ";
		cin>>temp;
	}
	return;
}

void selection_sort(int arr[],int size_arr)
{
	int temp_arr[100];
	for(int a=0;a<size_arr;a++)
	{
		temp_arr[a] = arr[a];
	}
	for(int a=0;a<size_arr;a++)
	{
		int min = temp_arr[a];
		int min_pos = a;
		for(int b=a+1;b<size_arr;b++)
		{
			if(temp_arr[b]<min)
			{
				min_pos = b;
				min = temp_arr[b];
			}
		}
		int temp_xchange = temp_arr[a];
		temp_arr[a] = temp_arr[min_pos];
		temp_arr[min_pos] = temp_xchange;
	}
	view_array(temp_arr,size_arr);
	return;
}

void insertion_sort(int arr[],int size_arr)
{
	int temp_arr[100];
	for(int a=0;a<size_arr;a++)
	{
		temp_arr[a] = arr[a];
	}

	for(int a=1;a<size_arr;a++)
	{
		int key = temp_arr[a];
		int b = a-1;
		while(b>=0&&temp_arr[b]>key)
		{
			temp_arr[b+1] = temp_arr[b];
			b = b-1;
		}
		temp_arr[b+1] = key;
	}
	view_array(temp_arr,size_arr);
	return;

}

void bubble_sort(int arr[], int size_arr)
{
	int temp_arr[100];
	for(int a=0;a<size_arr;a++)
	{
		temp_arr[a] = arr[a];
	}

	for(int a=0;a<size_arr;a++)
	{
		for(int b=0;b<size_arr-a-1;b++)
		{
			if(temp_arr[b]>temp_arr[b+1])
			{
				int temp = temp_arr[b];
				temp_arr[b] = temp_arr[b+1];
				temp_arr[b+1] = temp;
			}
		}
	}
	view_array(temp_arr,size_arr);
	return;
}

void merge(int *arr,int start_pos,int mid_pos,int end_pos)
{
	int temp_arr[100];
	int iter1 = start_pos;
	int iter2 = mid_pos+1;
	int iter = start_pos;
	while(iter1<=mid_pos&&iter2<=end_pos)
	{
		if(arr[iter1]<=arr[iter2])
		{
			temp_arr[iter] = arr[iter1];
			iter++;
			iter1++;
		}
		else
		{
			temp_arr[iter] = arr[iter2];
			iter++;
			iter2++;
		}
	}
	while(iter1<=mid_pos)
	{
		temp_arr[iter] = arr[iter1];
		iter++;
		iter1++;
	}
	while(iter2<=end_pos)
	{
		temp_arr[iter] = arr[iter2];
		iter++;
		iter2++;
	}

	for(int a=start_pos;a<=end_pos;a++)
	{
		arr[a] = temp_arr[a];
	}
}

void merge_sort(int* arr,int start_pos,int end_pos)
{
	if(start_pos<end_pos)
	{
		int mid_pos = (start_pos+end_pos)/2;
		merge_sort(arr,start_pos,mid_pos);
		merge_sort(arr,mid_pos+1,end_pos);
		merge(arr,start_pos,mid_pos,end_pos);
	}
	return;

}


void merge_sort_wrapper(int arr[],int size_arr)
{
	int temp_arr[100];
	for(int a=0;a<size_arr;a++)
	{
		temp_arr[a] = arr[a];
	}
	merge_sort(temp_arr,0,size_arr-1);
	view_array(temp_arr,size_arr);
	return;
}

int partition(int arr[],int start_pos, int end_pos)
{
	int pivot = arr[(start_pos+end_pos)/2];
	int left_iterator = start_pos;
	int right_iterator = end_pos;
	int temp;
	while(1)
	{
		while(arr[left_iterator]<pivot)
		{
			left_iterator++;
		}
		while(arr[right_iterator]>pivot)
		{
			right_iterator--;
		}
		if(left_iterator<right_iterator)
		{
			temp = arr[left_iterator];
			arr[left_iterator] = arr[right_iterator];
			arr[right_iterator] = temp;
		}
		else
		{
			break;
		}
	}
	if(right_iterator == ((start_pos+end_pos)/2))
	{
		return right_iterator;
	}
	else
	{
		temp = arr[(start_pos+end_pos)/2];
		arr[(start_pos+end_pos)/2] = arr[right_iterator];
		arr[right_iterator] = temp;
		return right_iterator;
	}
}

void quick_sort(int arr[],int start_pos,int end_pos)
{
	int divider;
	if(start_pos<end_pos)
	{
		divider = partition(arr,start_pos,end_pos);
		quick_sort(arr,start_pos,divider-1);
		quick_sort(arr,divider+1,end_pos);
	}
	return;
}

void quick_sort_wrapper(int arr[],int size_arr)
{
	int temp_arr[100];
	for(int a=0;a<size_arr;a++)
	{
		temp_arr[a] = arr[a];
	}
	quick_sort(temp_arr,0,size_arr-1);
	view_array(temp_arr,size_arr);
	return;
}

int main(int argc, char* argv[])
{
	int arr[100];
	int size_arr = -1;
	char temp;
	int choice;
	while(1)
	{
		clear();
		cout<<"Sorting Algorithms\n";
		cout<<"1. Insert Elements into Array\n";
		cout<<"2. View elements\n";
		cout<<"3. Selection Sort\n";
		cout<<"4. Insertion Sort\n";
		cout<<"5. Bubble Sort\n";
		cout<<"6. Merge Sort\n";
		cout<<"7. Quick Sort\n";
		cout<<"8. Exit\n";
		cout<<"Enter choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter number of elements : ";
					cin>>size_arr;
					while(size_arr<1)
					{
						cout<<"Enter number of elements : ";
						cin>>size_arr;
					}
					for(int a=0;a<size_arr;a++)
					{
						cout<<"Element "<<a+1<<" : ";
						cin>>arr[a];
					}
					cout<<"Added!";
					cout<<"\nPress Y to return : ";
					cin>>temp;
					while(temp!='Y')
					{
						cout<<"Press Y to return : ";
						cin>>temp;
					}
					break;
			case 2: if(size_arr==-1)
					{
						cout<<"Nothing to display!";
					}
					else
					{
						view_array(arr,size_arr);
					}
					break;
			case 3: selection_sort(arr,size_arr);
					break;
			case 4: insertion_sort(arr,size_arr);
					break;
			case 5: bubble_sort(arr,size_arr);
					break;
			case 6: merge_sort_wrapper(arr,size_arr);
					break;
			case 7: quick_sort_wrapper(arr,size_arr);
					break;
			default:break;

		}
		if(choice==8)
			break;
	}
	return 0;
}

