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

struct node *parent(struct node **head,struct node* ele)
{
	struct node *traverser = *head;
	while(traverser!=NULL)
	{
		if(traverser->next==ele)
		{
			break;
		}
		else
		{
			traverser=traverser->next;
		}
	}
	return traverser;
}


struct node* middle(struct node **head)
{
	struct node *fast_ptr = *head;
	struct node *slow_ptr = *head;
	while(fast_ptr!=NULL)
	{
		fast_ptr = fast_ptr->next;
		if(fast_ptr!=NULL)	
		{
			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next;
		}
	}
	return slow_ptr;
}
int count_elements(struct node **head)
{
	if(*head==NULL)
	{
		return 0;
	}
	else
	{
		struct node *traverser = *head;
		int count = 0;
		while(traverser!=NULL)
		{
			count++;
			traverser = traverser->next;
		}
		return count;
	}
}
bool palindrome_check(struct node **left,struct node **right)
{
	if(*right==NULL)
	{
		return true;
	}
	bool temp = palindrome_check(left,&((*right)->next));
	if(temp == false)
	{
		return false;
	}

	bool x = (*left)->val == (*right)->val;
	*left = (*left)->next;
	return x;
}

void palindrome_check_wrapper(struct node **head)
{
	if(*head==NULL)
	{
		cout<<"Nothing to do!";
		char temp1;
		cout<<"\nPress Y to return : ";
		cin>>temp1;
		while(temp1!='Y')
		{
			cout<<"Press Y to return : ";
			cin>>temp1;
		}
		return;
	}
	else
	{
		struct node *left = *head;
		struct node *right = *head;
		if(palindrome_check(&left,&right))
		{
			cout<<"It's a palindrome!";
		}
		else
		{
			cout<<"It's not a palindrome!";
		}
		char temp1;
		cout<<"\nPress Y to return : ";
		cin>>temp1;
		while(temp1!='Y')
		{
			cout<<"Press Y to return : ";
			cin>>temp1;
		}
		return;
	}
}
void middle_wrapper(struct node **head)
{
	if(*head!=NULL)
	{
		struct node *temp = middle(head);
		cout<<"\nMiddle element is : "<<temp->val;
		char temp1;
		cout<<"\nPress Y to return : ";
		cin>>temp1;
		while(temp1!='Y')
		{
			cout<<"Press Y to return : ";
			cin>>temp1;
		}
		return;
	}
	else
	{
		cout<<"\nNothing to print!";
		char temp1;
		cout<<"\nPress Y to return : ";
		cin>>temp1;
		while(temp1!='Y')
		{
			cout<<"Press Y to return : ";
			cin>>temp1;
		}
		return;
	}
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

void delete_node2(struct node **head)
{
	cout<<"Enter number to delete : ";
	int target;
	cin>>target;
	struct node *traverser = *head;
	while(traverser!=NULL)
	{
		if(traverser->val==target)
		{
			break;
		}
		else
		{
			traverser=traverser->next;
		}
	}
	if(traverser==NULL)
	{
		cout<<"Element to delete not found!";
		char temp1;
		cout<<"\nPress Y to return : ";
		cin>>temp1;
		while(temp1!='Y')
		{
			cout<<"Press Y to return : ";
			cin>>temp1;
		}
		return;
	}
	else
	{
		struct node *new_node = traverser->next;
		if(new_node!=NULL)
		{
			traverser->val = new_node->val;
			traverser->next = new_node->next;
			delete new_node;
		}
		else
		{
			delete traverser;
		}
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

void print_reverse(struct node **head)
{
	if(*head==NULL)
	{
		return;
	}
	else
	{
		print_reverse(&((*head)->next));
		cout<<(*head)->val<<" ";
		return;
	}
}

void print_reverse_wrapper(struct node **head)
{
	if(*head==NULL)
	{
		cout<<"Nothing to do!";
		char temp1;
		cout<<"\nPress Y to return : ";
		cin>>temp1;
		while(temp1!='Y')
		{
			cout<<"Press Y to return : ";
			cin>>temp1;
		}
		return;
	}
	else
	{
		cout<<"The reverse list is : \n";
		print_reverse(head);
		char temp1;
		cout<<"\nPress Y to return : ";
		cin>>temp1;
		while(temp1!='Y')
		{
			cout<<"Press Y to return : ";
			cin>>temp1;
		}
		return;
	}
}
void remove_duplicates(struct node **head)
{
	if(*head==NULL||(*head)->next==NULL)
	{
		return;
	}
	else
	{
		struct node *first_level_traverser = *head;
		while(first_level_traverser!=NULL)
		{
			struct node* second_level_traverser_parent = first_level_traverser;
			struct node* second_level_traverser = first_level_traverser->next;
			while(second_level_traverser!=NULL)
			{
				cout<<endl<<first_level_traverser->val<<" "<<second_level_traverser->val;
				if(second_level_traverser->val==first_level_traverser->val)
				{	
					struct node* new_node = second_level_traverser;
					second_level_traverser_parent->next = new_node->next;
					second_level_traverser = new_node->next;
					delete new_node;
				}
				else
				{
					second_level_traverser_parent = second_level_traverser;
					second_level_traverser = second_level_traverser->next;
				} 
			}
			first_level_traverser = first_level_traverser->next;
		}
		return;
	}
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
		cout<<"3. View elements in reverse\n";
		cout<<"4. Delete element - Type 1\n";
		cout<<"5. Delete element - Type 2 (Don't use to delete last element)\n";
		cout<<"6. Insert into position\n";
		cout<<"7. Delete from position\n";
		cout<<"8. Merge Sort\n";
		cout<<"9. Reverse\n";
		cout<<"10. Print Middle Element\n";
		cout<<"11. Palindrome Check\n";
		cout<<"12. Remove Duplicates\n";
		cout<<"13. Exit\n";
		cout<<"Enter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: add_node(&HEAD);
					break;
			case 2: view_list(&HEAD);
					break;
			case 3:print_reverse_wrapper(&HEAD);
					break;
			case 4: delete_node(&HEAD);
					break;
			case 5: delete_node2(&HEAD);
					break;
			case 6: insert_into_position(&HEAD);
					break;
			case 7: delete_from_position(&HEAD);
					break;
			case 8: merge_sort(&HEAD);
					char temp1;
					cout<<"Done!\nEnter Y to continue : ";
					cin>>temp1;
					while(temp1!='Y')
					{
						cout<<"Press Y to return : ";
						cin>>temp1;
					}
					break;
			case 9: reverse(&HEAD);
					char temp2;
					cout<<"Done!\nEnter Y to continue : ";
					cin>>temp2;
					while(temp2!='Y')
					{
						cout<<"Press Y to return : ";
						cin>>temp2;
					}
					break;
			case 10:middle_wrapper(&HEAD);
					break;
			case 11:palindrome_check_wrapper(&HEAD);
					break;
			case 12:remove_duplicates(&HEAD);
					break;
			default:break;
		}
		if(choice==13)
			break;
	}
	return 0;
}

