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

void add_node(struct node **head)
{
	cout<<"Enter a value : ";
	int new_val;
	cin>>new_val;
	if (*head == NULL)
	{
		struct node *new_node = new node;
		new_node->val=new_val;
		new_node->next=NULL;
		*head = new_node;
		cout<<"Added!\n";
	}
	else
	{
		struct node* traverser = *head;
		while(traverser->next!=NULL)
		{
			traverser = traverser->next;
		}
		struct node *new_node = new node;
		new_node->val=new_val;
		new_node->next=NULL;
		traverser->next = new_node;
		cout<<"Added!\n";
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

void delete_node(struct node **head)
{
	cout<<"Enter number to delete : ";
	int target;
	cin>>target;
	struct node *traverser = *head;
	struct node *pre_traverser = NULL;
	while(traverser!=NULL)
	{
		if(traverser->val==target)
		{
			break;
		}	
		else
		{
			pre_traverser = traverser;
			traverser = traverser->next;
		}
	}
	if (traverser==NULL)
	{
		if (*head == NULL)
			cout<<"Nothing to delete\n";
		else
			cout<<"Not found!\n";
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
	else if (traverser==*head)
	{
		*head = (*head)->next;
		cout<<"Found and deleted! \n";
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
	else
	{
		struct node *new_node = traverser;
		pre_traverser->next = traverser->next;
		delete new_node;
		cout<<"Found and deleted! \n";
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
}

void insert_into_position(struct node **head)
{
	int pos,val;
	cout<<"Enter position : ";
	cin>>pos;
	cout<<"Enter value : ";
	cin>>val;
	if (pos == 1)
	{
		struct node *new_node = new node;
		new_node->val = val;
		new_node->next = *head;
		*head = new_node;
		cout<<"Added!\n";
	}
	else
	{
		int ctr = 1;
		struct node *traverser = *head;
		struct node *pre_traverser = NULL;
		while(ctr!=pos&&traverser!=NULL)
		{
			pre_traverser = traverser;
			traverser = traverser->next;
			ctr++;
		}
		struct node *new_node = new node;
		new_node->val = val;
		new_node->next = pre_traverser->next;
		pre_traverser->next=new_node;
		cout<<"Added!\n";

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

void delete_from_position(struct node **head)
{
	int pos;
	cout<<"Enter position to delete : ";
	cin>>pos;
	if(pos<=0)
	{
		cout<<"Can't delete impossible values\n";
	}
	else
	{
		if(pos==1)
		{
			struct node *temp = *head;
			*head = (*head)->next;
			delete temp;
			cout<<"Deleted Head\n";
		}
		else
		{
			int ctr = 1;
			struct node *traverser = *head;
			struct node *pre_traverser = NULL;
			while(traverser!=NULL&&ctr<pos)
			{
				pre_traverser = traverser;
				traverser = traverser->next;
				ctr++;
			};
			if(traverser==NULL)
			{
				cout<<"Position doesn't exist!\n";
			}
			else
			{
				struct node *temp = traverser;
				pre_traverser->next = traverser->next;
				delete temp;
				cout<<"Deleted!\n";
			}
		}
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

struct node* sorted_merge(struct node **a,struct node **b)
{
	struct node *result = NULL;
	if(*a == NULL)
	{
		return *b;
	}
	else
	{
		if(*b == NULL)
		{
			return *a;
		}
	}

	if((*a)->val < (*b)->val)
	{
		result=*a;
		result->next = sorted_merge(&((*a)->next),b);
	}
	else
	{
		result=*b;
		result->next = sorted_merge(a,&((*b)->next));
	}
	return result;
}

void front_back_split(struct node **head,struct node **front_ref,struct node **back_ref)
{
	if(*head == NULL || (*head)->next == NULL)
	{
		*front_ref = *head;
		*back_ref = NULL;
	}
	else
	{
		struct node *fast = (*head)->next;
		struct node *slow = (*head);
		while(fast!=NULL)
		{
			fast = fast->next;
			if(fast!=NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		*front_ref = *head;
		*back_ref = slow->next;
		slow->next = NULL;
	}
	return;
}

void merge_sort(struct node **head)
{
	if(*head == NULL ||(*head)->next == NULL)
	{
		return;
	}
	else
	{
		struct node *a = NULL;
		struct node *b = NULL;
		front_back_split(head,&a,&b);

		merge_sort(&a);
		merge_sort(&b);
		*head = sorted_merge(&a,&b);
	}
}

void reverse(struct node **head)
{
	struct node *post = (*head)->next;
	struct node *in = *head;
	struct node *pre = NULL;

	while(post!=NULL)
	{
		in->next = pre;
		pre = in;
		in = post;
		post = post->next;
	}
	in->next = pre;
	*head = in;
	return;

}


int main(int argc, char* argv[])
{
	while(1)
	{
		clear();
		int choice;
		cout<<"LINKED LISTS BASICS\n";
		cout<<"1. Add new element\n";
		cout<<"2. View elements\n";
		cout<<"3. Delete element\n";
		cout<<"4. Insert into position\n";
		cout<<"5. Delete from position\n";
		cout<<"6. Merge Sort\n";
		cout<<"7. Reverse\n";
		cout<<"8. Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: add_node(&HEAD);
					break;
			case 2: view_list(&HEAD);
					break;
			case 3: delete_node(&HEAD);
					break;
			case 4: insert_into_position(&HEAD);
					break;
			case 5: delete_from_position(&HEAD);
					break;
			case 6: merge_sort(&HEAD);
					char temp1;
					cout<<"Done!\nEnter Y to continue : ";
					cin>>temp1;
					while(temp1!='Y')
					{
						cout<<"Press Y to return : ";
						cin>>temp1;
					}
					break;
			case 7: reverse(&HEAD);
					char temp2;
					cout<<"Done!\nEnter Y to continue : ";
					cin>>temp2;
					while(temp2!='Y')
					{
						cout<<"Press Y to return : ";
						cin>>temp2;
					}
					break;
			default:break;
		}
		if(choice==8)
			break;
	}
	return 0;
}

