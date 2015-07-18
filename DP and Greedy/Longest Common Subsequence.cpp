#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#define LEFT 1
#define UP 2
#define DIAG 3
using namespace std;

string longest_common_subsequence(string s1,string s2)
{
	int matrix[s1.size()+1][s2.size()+1];
	int dir_matrix[s1.size()+1][s2.size()+1];
	for(int a=0;a<=s1.size();a++)
	{
		for(int b=0;b<=s2.size();b++)
		{
			if(a==0||b==0)
			{
				matrix[a][b]=0;
				dir_matrix[a][b]=0;
			}
			else if(s1[a-1]==s2[b-1])
			{
				matrix[a][b] = matrix[a-1][b-1]+1;
				dir_matrix[a][b] = DIAG;
			}
			else
			{
				if(matrix[a-1][b]>matrix[a][b-1])
				{
					matrix[a][b] = matrix[a-1][b];
					dir_matrix[a][b] = UP;
				}
				else
				{
					matrix[a][b] = matrix[a][b-1];
					dir_matrix[a][b] = LEFT;
				}
			}
		}
	}
	string lcs = "";
	int a=s1.size(),b=s2.size();
	while(a!=0&&b!=0)
	{
		if(dir_matrix[a][b]==DIAG)
		{
			lcs = lcs+s1[a-1];
			a--;
			b--;
		}
		else if(dir_matrix[a][b]==UP)
		{
			a--;
		}
		else
		{
			b--;
		}
	}
	for(int c=0;c<lcs.size()/2;c++)
	{
		char temp = lcs[c];
		lcs[c] = lcs[lcs.size()-1-c];
		lcs[lcs.size()-1-c] = temp;
	}
	
	return lcs;
}

int main()
{
	string s1,s2;
	cout<<"LONGEST COMMON SUBSEQUENCE\n";
	cout<<"Enter String 1 : ";
	cin>>s1;
	cout<<"Enter String 2 : ";
	cin>>s2;
	cout<<"Longest Common Subsequence is "<<longest_common_subsequence(s1,s2)<<"\n";
}