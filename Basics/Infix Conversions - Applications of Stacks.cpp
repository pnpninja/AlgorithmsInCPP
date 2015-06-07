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
	char val;
};
struct node *char_stack = NULL;
//struct node *symbol_stack = NULL;

void push(struct node **head,char val)
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

char pop(struct node **head)
{
	struct node *temp = *head;
	char val = temp->val;
	*head = (*head)->next;
	delete temp;
	return val;
}

char last_char(struct node **head)
{
	return (*head)->val;
}

string infix_to_postfix(string input)
{
	string output = "";
	push(&char_stack,'(');
	for(string::size_type int_iterator = 0;int_iterator < input.length();int_iterator++)
	{
		//cout<<int_iterator<<"\n";
		char iterator = input[int_iterator];
		char ignor;
		switch(iterator)
		{
			case '(': push(&char_stack,'(');
					  //cout<<"Case 1\n";
					  //cout<<output<<"\n";
					  break;
			case ')': while(last_char(&char_stack)!='(')
					  {
					  	output = output + pop(&char_stack);
					  }
					  ignor = pop(&char_stack);
					  //cout<<"Case 2\n";
					  //cout<<output<<"\n";
					  break;
			case '^': push(&char_stack,'^');
					  //cout<<"Case 3\n";
					  //cout<<output<<"\n";
					  break;
			case '*': if(last_char(&char_stack)=='^'||last_char(&char_stack)=='*'||last_char(&char_stack)=='/')
					  {
					    output = output + pop(&char_stack);
					  }
					  push(&char_stack,'*');
					  //cout<<"Case 4\n";
					  //cout<<output<<"\n";
					  break;
			case '/': if(last_char(&char_stack)=='^'||last_char(&char_stack)=='*'||last_char(&char_stack)=='/')
					  {
					    output = output + pop(&char_stack);
					  }
					  push(&char_stack,'/');
					  //cout<<"Case 5\n";
					  //cout<<output<<"\n";
					  break;
			case '+': if(last_char(&char_stack)=='^'||last_char(&char_stack)=='*'||last_char(&char_stack)=='/'||last_char(&char_stack)=='+'||last_char(&char_stack)=='-')
					  {
					    output = output + pop(&char_stack);
					  }
					  push(&char_stack,'+');
					  //cout<<"Case 6\n";
					  //cout<<output<<"\n";
					  break;
			case '-': if(last_char(&char_stack)=='^'||last_char(&char_stack)=='*'||last_char(&char_stack)=='/'||last_char(&char_stack)=='+'||last_char(&char_stack)=='-')
					  {
					    output = output + pop(&char_stack);
					  }
					  push(&char_stack,'-');
					  //cout<<"Case 7\n";
					  //cout<<output<<"\n";
					  break;
			default:  output = output + iterator;
					  //cout<<"Case 8\n";
					  //cout<<output<<"\n";
					  break;
		}
	}
	if(char_stack!=NULL)
	{	while(last_char(&char_stack)!='(')
		{
			output = output+pop(&char_stack);
		}
	}
	//cout<<"Output : "<<output<<"\n";
	return output;
}

int main(int argc,char* argv[])
{
	while(1)
	{	clears();
		string input,output;
		int choice;
		char temp1;
		cout<<"Infix To Pre/Postfix Conversions\n";
		cout<<"1. Infix to Prefix\n";
		cout<<"2. Infix to Postfix\n";
		cout<<"3. Exit\n";
		cout<<"Enter choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: __fpurge(stdin);
					cout<<"Enter string : ";
					getline(cin,input);
					for(string::size_type i=0;i < input.length();i++)
					{
						if(input[i] == '(')
						{
							input[i] = ')';
						}
						else 
						{	
							if(input[i] == ')')
							{
								input[i] = '(';
							}
							
						}
					}
					for(string::size_type i=0;i <input.length()/2;i++)
					{
						char temp = input[i];
						input[i] = input[input.length()-i-1];
						input[input.length()-i-1] = temp;
					}
					input = input+')';
					output = infix_to_postfix(input);
					for(string::size_type i=0;i <output.length()/2;i++)
					{
						char temp = output[i];
						output[i] = output[output.length()-i-1];
						output[output.length()-i-1] = temp;
					}
					cout<<"Prefix : "<<output<<"\n";
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
					input = input + ')';
					output = infix_to_postfix(input);
					cout<<"Postfix : "<<output<<"\n";
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