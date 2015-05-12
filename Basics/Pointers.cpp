#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#define clear() printf("\033[H\033[J")
using namespace std;

struct node
{
	int val;
	node *next;
};

struct node* head = NULL;

void add_node(struct node *hea)
{
	char f;
	int val;
	cout<<"Enter value : ";
	cin>>val;
	if(head==NULL)
	{
		head = new(struct node);
		head->val = val;
		head->next = NULL;
	}
	else
	{
		node *traverser = hea;
		node *traverser_prev = NULL;
		while(traverser!=NULL)
		{
			traverser_prev = traverser;
			traverser=traverser->next;
		}
		traverser = new(struct node);
		traverser->val = val;
		traverser->next = NULL;
		traverser_prev->next=traverser;
	}
	cout<<"\nEnter Y to return : ";
	cin>>f;
	while(f!='Y')
	{
		cout<<"Wrong entry.Enter again : ";
		cin>>f;
	}
	return;
}

void view_list(struct node *hea)
{
	char f;
	node *traverser = hea;
	while(traverser!=NULL)
	{
		cout<<traverser->val<<" ";
		traverser=traverser->next;
	}
	cout<<"\nEnter Y to return : ";
	cin>>f;
	while(f!='Y')
	{
		cout<<"Wrong entry.Enter again : ";
		cin>>f;
	}
	return;
}

void delete_node(node*& hea)
{
	char f;
	int del_value;
	cout<<"Enter value to be deleted :";
	cin>>del_value;

	node *traverser = hea;
	cout<<"OK1\n";
	node* traverser_prev = new node;
	traverser_prev->next=NULL;
	cout<<"OK2\n";

	while(traverser!=NULL)
	{
		if(traverser->val==del_value)
		{
			if(traverser==hea)
			{
				node *temp = hea;
				hea = hea->next;
				cout<<"Here cond1\n";
				delete temp;
				return;
			}
			else
			{
				traverser_prev->next = traverser->next;
				cout<<"Here cond2\n";
				return;
			}
		}
		else
		{
			traverser_prev = traverser;
			traverser = traverser->next;
			cout<<"Here cond3\n";
		}
	}
	cout<<"\nEnter Y to return : ";
	cin>>f;
	while(f!='Y')
	{
		cout<<"Wrong entry.Enter again : ";
		cin>>f;
	}
	return;
}

void insert_into_position(node*& hea)
{
	char f;
	int pos;
	int val;
	cout<<"Enter position : ";
	cin>>pos;
	cout<<"Enter value : ";
	cin>>val;
	int ctr=0;

	node* traverser = hea;
	node* traverser_prev = NULL;

	if(pos==1)
	{
		node* new_node = new node;
		new_node->val = val;
		new_node->next=hea;
		hea=new_node;

	}
	else
	{
		pos = pos - 1;
		while(traverser!=NULL)
		{
			ctr = ctr+1;
			traverser_prev = traverser;
			traverser = traverser->next;
			if(ctr==pos)
			{
				node* new_node = new node;
				new_node->val = val;
				new_node->next = traverser;
				traverser_prev->next = new_node;
				break;
			}
		}
	}
	cout<<"\nEnter Y to return : ";
	cin>>f;
	while(f!='Y')
	{
		cout<<"Wrong entry.Enter again : ";
		cin>>f;
	}
	return;

}

void delete_from_position(node*& hea)
{
	char f;
	int pos;
	cout<<"Enter position : ";
	cin>>pos;
	int ctr=0;

	node* traverser = hea;
	node* traverser_prev = NULL;

	if(pos==1)
	{
		node* temp = hea;
		hea = hea->next;
		delete temp;
	}
	else
	{
		pos = pos - 1;
		while(traverser!=NULL)
		{
			ctr = ctr+1;
			traverser_prev = traverser;
			traverser = traverser->next;
			if(ctr==pos)
			{
				node* new_node = traverser;
				traverser_prev->next = traverser->next;
				delete new_node;
				break;
			}
		}
	}
	cout<<"\nEnter Y to return : ";
	cin>>f;
	while(f!='Y')
	{
		cout<<"Wrong entry.Enter again : ";
		cin>>f;
	}
	return;
}
int main(int argc, char* argv[])
{
	while(1)
	{
		clear();
		int choice;
		cout<<"POINTER BASICS\n";
		cout<<"1. Add new element\n";
		cout<<"2. View elements\n";
		cout<<"3. Delete element\n";
		cout<<"4. Insert into position\n";
		cout<<"5. Delete from position\n";
		cout<<"6. Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: add_node(head);
					break;
			case 2: view_list(head);
					break;
			case 3: delete_node(head);
					break;
			case 4: insert_into_position(head);
					break;
			case 5: delete_from_position(head);
					break;
			default:break;
		}
		if(choice==6)
			break;
	}
}