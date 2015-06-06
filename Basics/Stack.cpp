#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#define clear() printf("\033[H\033[J")
using namespace std;

struct node
{
	struct node* next;
	int val;
};

struct node *HEAD = NULL;

void view_list(struct node **head)
{
	struct node *traverser = *head;
	while(traverser!=NULL)
	{
		cout<<traverser->val<<" ";
		traverser = traverser->next;
	}
	char temp;
	cout<<"\nPress Y to return : ";
	cin>>temp;
	while(temp!='Y')
	{
		cout<<"Press Y to return : ";
		cin>>temp;
	}
	return;
}


void push(struct node **head)
{
	int val;
	cout<<"Enter element to push : ";
	cin>>val;
	if(*head == NULL)
	{
		struct node *temp = new node;
		temp->next=NULL;
		temp->val=val;
		*head = temp;
	}
	else
	{
		struct node *temp = new node;
		temp->next=*head;
		temp->val=val;
		*head = temp;
	}
	char temp;
	cout<<"Press Y to return : ";
	cin>>temp;
	while(temp!='Y')
	{
		cout<<"Press Y to return : ";
		cin>>temp;
	}
	return;
}

void pop(struct node **head)
{
	if(*head==NULL)
	{
		cout<<"Nothing to pop!";
	}
	else
	{
		cout<<"Popped value : "<<(*head)->val<<"\n";
		struct node *temp = *head;
		*head = (*head)->next;
		delete temp;
	}
	char temp;
	cout<<"Press Y to return : ";
	cin>>temp;
	while(temp!='Y')
	{
		cout<<"Press Y to return : ";
		cin>>temp;
	}
	return;
}

void alternate_push(struct node **head,int val)
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

int alternate_pop(struct node **head)
{
	struct node *temp = *head;
	int val = temp->val;
	*head = (*head)->next;
	delete temp;
	return val;
}

void add_at_end(struct node **head)
{
	int val_to_add;
	cout<<"Enter value to add : ";
	cin>>val_to_add;
	struct node *temp_stack = NULL;
	while(*head!=NULL)
	{
		alternate_push(&temp_stack,(*head)->val);
		alternate_pop(head);
	}
	alternate_push(&temp_stack,val_to_add);
	while(temp_stack!=NULL)
	{
		alternate_push(head,temp_stack->val);
		alternate_pop(&temp_stack);		
	}
	char temp;
	cout<<"Done!\nPress Y to return : ";
	cin>>temp;
	while(temp!='Y')
	{
		cout<<"Press Y to return : ";
		cin>>temp;
	}
	return;
}

int main(int argc, char* argv[])
{
	while(1)
	{
		clear();
		int choice;
		cout<<"STACK BASICS\n";
		cout<<"1. Push\n";
		cout<<"2. View elements\n";
		cout<<"3. Pop\n";
		cout<<"4. Add element at end using only push and pop\n";
		cout<<"5. Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: push(&HEAD);
					break;
			case 2: view_list(&HEAD);
					break;
			case 3: pop(&HEAD);
					break;
			case 4: add_at_end(&HEAD);
			//		break;
			default:break;
		}
		if(choice==5)
			break;
	}
	return 0;
}

