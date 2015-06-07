#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string>
#include <cctype>
#define clears() printf("\033[H\033[J")
using namespace std;

struct node
{
	struct node *next;
	string val;
};
struct node *str_stack = NULL;
//struct node *symbol_stack = NULL;

void push(struct node **head,string val)
{
	if(*head == NULL)
	{
		struct node *temp = new node;
		temp->val=val;
		temp->next=NULL;
		*head = temp;
	}
	else
	{
		struct node *temp = new node;
		temp->val = val;
		temp->next = *head;
		*head = temp;
	}
	return;
}

string pop(struct node **head)
{
	struct node *temp = *head;
	string val = temp->val;
	*head = (*head)->next;
	delete temp;
	return val;
}

string last_char(struct node **head)
{
	return (*head)->val;
}

string postfix_to_infix(string input)
{
	string output = "";
	for(string::size_type int_iterator = 0;int_iterator < input.length();int_iterator++)
	{
		string iterator(1, input[int_iterator]);
		char ignor;
		if(iterator == "^" || iterator == "*" || iterator == "/" || iterator == "+" || iterator == "-")
		{
			string str1 = pop(&str_stack);
			string str2 = pop(&str_stack);
			string new_str = '(' + str2 + ')'+ iterator +'('+ str1 + ')';
			push(&str_stack,new_str);
		}
		else
		{
			push(&str_stack,iterator);
		}
	}
	output = pop(&str_stack);
	return output;
}

int main(int argc,char* argv[])
{
	while(1)
	{	clears();
		string input,output;
		int choice;
		char temp1;
		cout<<"Pre/Postfix To Infix Conversions\n";
		cout<<"1. Postfix to Infix\n";
		cout<<"2. Prefix to Infix\n";
		cout<<"3. Exit\n";
		cout<<"Enter choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: __fpurge(stdin);
					cout<<"Enter string : ";
					getline(cin,input);
					cout<<"Infix : "<<postfix_to_infix(input)<<"\n";
					cout<<"Press Y to return : ";
					cin>>temp1;
					while(temp1!='Y')
					{
						cout<<"Press Y to return : ";
						cin>>temp1;
					}
					break;
			case 2: __fpurge(stdin);
					cout<<"Enter string : ";
					getline(cin,input);
					for(string::size_type i=0;i <input.length()/2;i++)
					{
						char temp = input[i];
						input[i] = input[input.length()-i-1];
						input[input.length()-i-1] = temp;
					}
					output = postfix_to_infix(input);
					for(string::size_type i=0;i < output.length();i++)
					{
						if(output[i] == '(')
						{
							output[i] = ')';
						}
						else 
						{	
							if(output[i] == ')')
							{
								output[i] = '(';
							}
							
						}
					}
					for(string::size_type i=0;i <output.length()/2;i++)
					{
						char temp = output[i];
						output[i] = output[output.length()-i-1];
						output[output.length()-i-1] = temp;
					}
					cout<<"Infix : "<<output<<"\n";
					cout<<"Press Y to return : ";
					cin>>temp1;
					while(temp1!='Y')
					{
						cout<<"Press Y to return : ";
						cin>>temp1;
					}
					break;
			default: break;
		}
		if(choice==3)
		{
			break;
		}
	}
	return 0;
}