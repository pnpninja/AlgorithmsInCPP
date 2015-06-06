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

void add(struct node **head,int val)
{
	if(*head == NULL)
	{
		struct node *new_node = new node;
		new_node->val = val;
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		struct node *traverser = *head;
		while(traverser->next!=NULL)
		{
			traverser = traverser->next;
		}
		struct node *new_node = new node;
		new_node->val = val;
		new_node->next = NULL;
		traverser->next = new_node;
	}
	return;
}

int deletes(struct node **head)
{
	if(*head == NULL)
	{
		return -999;
	}
	else
	{
		int temp = (*head)->val;
		struct node *temp_node = *head;
		*head = (*head)->next;
		delete temp_node;
		return temp;
	}
}

void add_wrapper(struct node **head)
{
	int val;
	cout<<"Enter number to add : ";
	cin>>val;
	add(head,val);
	cout<<"Added!\n";
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

void deletes_wrapper(struct node **head)
{
	int deleted_value = deletes(head);
	if(deleted_value == -999)
	{
		cout<<"Nothing to delete!";
	}
	else
	{
		cout<<"Deleted "<<deleted_value<<" from head!\n";
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

void view_list(struct node **head)
{
	cout<<"The queue is : \n";
	struct node *traverser = *head;
	while(traverser!=NULL)
	{
		cout<<traverser->val<<" ";
		traverser = traverser->next;
	}
	cout<<"\nPress Y to return : ";
	char temp;
	cin>>temp;
	while(temp!='Y')
	{
		cout<<"Press Y to return : ";
		cin>>temp;
	}
	return;

}
struct node *HEAD = NULL;

void add_at_start(struct node **head)
{
	int val;
	cout<<"Enter value to add first : ";
	cin>>val;
	struct node *temp_queue = NULL;
	add(&temp_queue,val);
	while(*head!=NULL)
	{
		add(&temp_queue,deletes(head));
	}
	while(temp_queue!=NULL)
	{
		add(head,deletes(&temp_queue));
	}
	cout<<"Press Y to return : ";
	char temp;
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
		cout<<"QUEUE BASICS\n";
		cout<<"1. Add\n";
		cout<<"2. View elements\n";
		cout<<"3. Delete\n";
		cout<<"4. Add element at start using only add and delete\n";
		cout<<"5. Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: add_wrapper(&HEAD);
					break;
			case 2: view_list(&HEAD);
					break;
			case 3: deletes_wrapper(&HEAD);
					break;
			case 4: add_at_start(&HEAD);
					break;
			default:break;
		}
		if(choice==5)
			break;
	}
	return 0;
}