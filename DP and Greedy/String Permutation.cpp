#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void string_permutation(string str,int start,int end)
{
	if(start==end)
	{
		cout<<str<<endl;
	}
	else
	{
		for(int a=start;a<=end;a++)
		{
			char temp = str[start];
			str[start] = str[a];
			str[a]=temp;
			string_permutation(str,start+1,end);
			temp = str[start];
			str[start] = str[a];
			str[a]=temp;
		}
	}
}

int main()
{
	string str;
	cout<<"STRING PERMUTATION\nEnter the string to permute : ";
	cin>>str;
	cout<<"The permutations are : \n";
	string_permutation(str,0,str.size()-1);
}