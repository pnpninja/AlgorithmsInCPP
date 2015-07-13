#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#define clear() printf("\033[H\033[J")
using namespace std;

struct node
{
	int val;
	struct node *left;
	struct node *right;
};

struct listnode
{
	struct listnode* next;
	int val;
};

struct node *HEAD = NULL;
struct listnode *LISTHEAD = NULL;

void add_listnode(struct listnode **head,int new_val)
{
	if (*head == NULL)
	{
		struct listnode *new_listnode = new listnode;
		new_listnode->val=new_val;
		new_listnode->next=NULL;
		*head = new_listnode;
	}
	else
	{
		struct listnode* traverser = *head;
		while(traverser->next!=NULL)
		{
			traverser = traverser->next;
		}
		struct listnode *new_listnode = new listnode;
		new_listnode->val=new_val;
		new_listnode->next=NULL;
		traverser->next = new_listnode;
	}
	return;
}

void view_list(struct listnode **head)
{
	struct listnode *traverser = *head;
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

void view_inorder(struct node **head)
{
	if(*head!=NULL)
	{
		view_inorder(&((*head)->left));
		cout<<(*head)->val<<" ";
		add_listnode(&LISTHEAD,(*head)->val);
		view_inorder(&((*head)->right));
	}
	else
	{
		return;
	}
}

void view_inorder_wrapper(struct node **head)
{
	cout<<"The Inorder Of the Binary Search Tree : \n";
	LISTHEAD = NULL;
	view_inorder(head);
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
void view_preorder(struct node **head)
{
	if(*head!=NULL)
	{		
		cout<<(*head)->val<<" ";
		view_inorder(&((*head)->left));
		view_inorder(&((*head)->right));
	}
	else
	{
		return;
	}
}

void view_preorder_wrapper(struct node **head)
{
	cout<<"The Inorder Of the Binary Search Tree : \n";
	view_preorder(head);
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
void view_postorder(struct node **head)
{
	if(*head!=NULL)
	{	
		view_inorder(&((*head)->left));
		view_inorder(&((*head)->right));	
		cout<<(*head)->val<<" ";
	}
	else
	{
		return;
	}
}

void view_postorder_wrapper(struct node **head)
{
	cout<<"The Inorder Of the Binary Search Tree : \n";
	view_postorder(head);
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
void add_element(struct node **head,int val)
{
	if(*head==NULL)
	{
		struct node *temp = new node;
		temp->val = val;
		temp->left = NULL;
		temp->right = NULL;
		*head = temp;
		return;
	}
	else
	{
		if(val < (*head)->val)
		{
			add_element(&((*head)->left),val);
		}
		else if(val > (*head)->val)
		{
			add_element(&((*head)->right),val);
		}
		else
		{
			return;
		}
	}
}

void add_element_wrapper(struct node **head)
{
	int val;
	char temp;
	cout<<"Enter value to add into tree : ";
	cin>>val;
	add_element(head,val);
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
		cout<<"BST BASICS\n";
		cout<<"1. Add new element\n";
		cout<<"2. Inorder View\n";
		cout<<"3. Pre Order View\n";
		cout<<"4. Post Order View\n";
		cout<<"5. Delete an element\n";
		cout<<"6. Tree to List View\n";
		cout<<"7. Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: add_element_wrapper(&HEAD);
					break;
			case 2: view_inorder_wrapper(&HEAD);
					break;
			case 3: view_preorder_wrapper(&HEAD);
					break;
			case 4: view_postorder_wrapper(&HEAD);
					break;
			case 5: //delete_element_wrapper(&HEAD);
					break;
					//CALL INORDER BEFORE CASE 6
			case 6: view_list(&LISTHEAD);
					break;
			default:break;
		}
		if(choice==7)
			break;
	}
	return 0;
}