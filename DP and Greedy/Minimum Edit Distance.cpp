#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}
int minimum_edit_distance(string s1,string s2)
{
	int matrix[s2.size()+1][s1.size()+1];
	for(int a=0;a<=s2.size();a++)
	{
		for(int b=0;b<=s1.size();b++)
		{
			if(a==0)
			{
				matrix[a][b] = b;
			}
			else if(b==0)
			{
				matrix[a][b] = a;
			}
			else if(s1[a-1]==s2[b-1])
			{
				matrix[a][b] = matrix[a-1][b-1];
			}
			else
			{
				matrix[a][b] = min(matrix[a][b-1],min(matrix[a-1][b-1],matrix[a-1][b]))+1;
			}
		}
	}
	return matrix[s2.size()][s1.size()];
}

int main()
{
	string s1,s2;
	cout<<"MINIMUM EDIT DISTANCE\n";
	cout<<"Enter Initial String : ";
	cin>>s1;
	cout<<"Enter Final String : ";
	cin>>s2;
	cout<<"The minimum edit distance is "<<minimum_edit_distance(s1,s2)<<endl;
	return 0;
}