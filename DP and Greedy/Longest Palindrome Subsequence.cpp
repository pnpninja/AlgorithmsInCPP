#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}
int longest_palindrome_sequence(string str,int start,int end)
{
	if(start==end)
	{
		return 1;
	}
	else if(str[start]==str[end]&&start+1==end)
	{
		return 2;
	}
	else if(str[start]==str[end])
	{
		return 2+longest_palindrome_sequence(str,start+1,end-1);
	}
	else
	{
		return max(longest_palindrome_sequence(str,start+1,end),longest_palindrome_sequence(str,start,end-1));
	}
}

int main()
{
	string str;
	cout<<"LONGEST PALINDROME SUBSEQUENCE";
	cout<<"\nEnter string : ";
	cin>>str;
	cout<<"The longest palindromic subsequence is "<<longest_palindrome_sequence(str,0,str.size()-1)<<endl;
	return 0;
}