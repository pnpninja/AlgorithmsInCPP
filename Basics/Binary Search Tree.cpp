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
struct listnode *STACKHEAD = NULL;
int size_of_tree(struct node **head)
{
	if(*head==NULL)
	{
		return 0;
	}
	else
	{
		return size_of_tree(&((*head)->left))+1+size_of_tree(&((*head)->right));
	}
}

void size_of_tree_wrapper(struct node **head)
{
	cout<<"Size of the tree is "<<size_of_tree(head);
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
	cout<<"The post order Of the Binary Search Tree : \n";
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

struct node *parent(struct node *head,struct node *ele)
{
	
}
struct next_biggest_number(struct node *head)
{
	if(head->right!=NULL)
	{
		struct node *traverser = head->right;
		while(traverser!=NULL)
		{
			traverser=traverser->left;
		}
		return traverser;
	}
	else
	{

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

bool nos_subtrees_in_range(struct node **head,int low,int high,int &count)
{
	if(*head==NULL)
	{
		return true;
	}
	else
	{
		bool left = ((*head)->left)?nos_subtrees_in_range(&((*head)->left),low,high,count):true;
		bool right = ((*head)->right)?nos_subtrees_in_range(&((*head)->right),low,high,count):true;
		if(left && right && (*head)->val>=low && (*head)->val<=high)
		{
			++count;
			return true;
		}
		else
		{
			return false;
		}
	}
}

void nos_subtrees_in_range_wrapper(struct node **head)
{
	int low,high,count=0;
	cout<<"Enter lower and upper limit : ";
	cin>>low>>high;
	bool tem = nos_subtrees_in_range(head,low,high,count);
	cout<<"The number of subtrees in that range are : "<<count;
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

void nos_nodes_in_range(struct node **head,int low,int high,int &count)
{
	if(*head==NULL)
	{
		return;
	}
	else
	{
		nos_nodes_in_range(&((*head)->left),low,high,count);
		nos_nodes_in_range(&((*head)->right),low,high,count);
		if((*head)->val>=low && (*head)->val<=high)
		{
			++count;
		}
		return;
	}
}

void nos_nodes_in_range_wrapper(struct node **head)
{
	int low,high,count=0;
	cout<<"Enter lower and upper limit : ";
	cin>>low>>high;
	nos_nodes_in_range(head,low,high,count);
	cout<<"The number of nodes in that range are : "<<count;
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

struct node* remove_half_nodes(struct node *head)
{
	if(head==NULL)
	{
		return head;
	}
	head->left = remove_half_nodes(head->left);
	head->right = remove_half_nodes(head->right);
	if(head->left==NULL&&head->right==NULL)
	{
		return head;
	}
	else if(head->left==NULL)
	{
		struct node *new_node = head->right;
		delete head;
		return new_node;
	}
	else if(head->right==NULL)
	{
		struct node *new_node = head->left;
		delete head;
		return new_node;
	}
	else
	{	
		return head;
	}
}

void remove_half_nodes_wrapper(struct node **head)
{
	*head = remove_half_nodes(*head);
	view_inorder_wrapper(head);
	return;
}

void kth_largest_element(struct node *head,int k,int &cur)
{
	if(cur>k||head==NULL)
	{
		return;
	}
	else
	{
		kth_largest_element(head->right,k,cur);
		cur++;
		if(cur==k)
		{
			cout<<head->val;
			return;
		}
		kth_largest_element(head->left,k,cur);
	}
}

void kth_largest_element_wrapper(struct node **head)
{
	int k,cur=0;
	cout<<"Enter K : ";
	cin>>k;
	cout<<"The Kth Largest Element is : ";
	kth_largest_element(*head,k,cur);
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
bool is_balanced(struct node *head,int index,int nos_nodes)
{
	if(head==NULL)
	{
		return true;
	}
	else if(index>=nos_nodes)
	{
		return false;
	}
	else
	{
		return (is_balanced(head->left,(2*index+1),nos_nodes)&&is_balanced(head->right,(2*index+2),nos_nodes));
	}
}

void is_balanced_wrapper(struct node *head)
{
	int index = 0;
	int nos_nodes = size_of_tree(&head);
	bool balance_status = is_balanced(head,index,nos_nodes);
	if(balance_status)
	{
		cout<<"It is balanced!";
	}
	else
	{
		cout<<"It is not balanced!";
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

int minimum_vertex_cover(struct node *head)
{
	if(head==NULL||(head->left==NULL&&head->right==NULL))
	{
		return 0;
	}
	else
	{
		int mvc_head_incl = 1+minimum_vertex_cover(head->left)+minimum_vertex_cover(head->right);
		int mvc_head_excl = 0;
		if(head->left)
		{
			mvc_head_excl+= 1+minimum_vertex_cover(head->left->left)+minimum_vertex_cover(head->left->right); 
		}
		if(head->right)
		{
			mvc_head_excl+= 1+minimum_vertex_cover(head->right->left)+minimum_vertex_cover(head->right->right);
		}

		if(mvc_head_excl<mvc_head_incl)
		{
			return mvc_head_excl;
		}
		else
		{
			return mvc_head_incl;
		}
	}
}

void minimum_vertex_cover_wrapper(struct node *head)
{
	cout<<"Minimum vertex cover is : "<<minimum_vertex_cover(head);
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

bool is_complete(struct node *head)
{
	if(head==NULL)
	{
		return true;
	}
	else
	{
		bool curr = ((head->left!=NULL&&head->right!=NULL)||(head->left==NULL&&head->right==NULL));
		bool left = is_complete(head->left);
		bool right = is_complete(head->right);
		return left&&right&&curr;
	}
}

void is_complete_wrapper(struct node *head)
{
	bool status = is_complete(head);
	if(status)
	{
		cout<<"It is complete!";
	}
	else
	{
		cout<<"It is not complete!";
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

void left_leaf_sum(struct node *head,int &sum)
{
	if(head!=NULL)
	{
		if(head->left->left==NULL&&head->left->right==NULL)
		{
			sum+=head->left->val;
			return;
		}
		else
		{
			left_leaf_sum(head->left,sum);
		}
		left_leaf_sum(head->right,sum);
		return;
	}
}

void left_leaf_sum_wrapper(struct node *head)
{
	int sum = 0;
	left_leaf_sum(head,sum);
	cout<<"The sum of all left leaves is : "<<sum;
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

struct node *remove_short_paths(struct node *head,int level,int max)
{
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		head->left=remove_short_paths(head->left,level+1,max);
		head->right=remove_short_paths(head->right,level+1,max);
		if(head->left==NULL&&head->right==NULL&&level<max)
		{
			delete head;
			return NULL;
		}
		else
		{
			return head;
		}
	}
}

int height(struct node *head)
{
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(head->left);
		int rheight = height(head->right);
		if(lheight>rheight)
		{
			return lheight+1;
		}
		else
		{
			return rheight+1;
		}
	}
}
void bottom_view(struct node *head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		bottom_view(head->left);
		if(height(head)==1||height(head)==2)
		{
			cout<<head->val<<" ";
		}
		bottom_view(head->right);
	}
}

void bottom_view_wrapper(struct node *head)
{
	cout<<"The bottom view is : ";
	bottom_view(head);
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
void remove_short_paths_wrapper(struct node **head)
{
	int pl;
	cout<<"Enter min path length : ";
	cin>>pl;
	*head = remove_short_paths(*head,1,pl);
	view_inorder_wrapper(head);
	return;
}

void left_view(struct node *head,int cur_level,int &max_level)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		if(cur_level>max_level)
		{
			cout<<head->val<<" ";
			max_level = cur_level;
		}
		left_view(head->left,cur_level+1,max_level);
		left_view(head->right,cur_level+1,max_level);
	}
}
void right_view(struct node *head,int cur_level,int &max_level)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		if(cur_level>max_level)
		{
			cout<<head->val<<" ";
			max_level = cur_level;
		}
		right_view(head->right,cur_level+1,max_level);
		right_view(head->left,cur_level+1,max_level);
	}
}

void left_view_wrapper(struct node *head)
{
	cout<<"Left view is : ";
	int max_level=0;
	left_view(head,1,max_level);
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

void right_view_wrapper(struct node *head)
{
	cout<<"Right view is : ";
	int max_level=0;
	right_view(head,1,max_level);
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
void print_level_order(struct node *head,int level,int flip_flag)
{
	if(head==NULL)
	{
		return;
	}	
	if(level==1)
	{
		cout<<head->val<<" ";
	}
	else
	{
		if(flip_flag==0)
		{
			print_level_order(head->left,level-1,flip_flag);
			print_level_order(head->right,level-1,flip_flag);
		}
		else
		{
			print_level_order(head->right,level-1,flip_flag);
			print_level_order(head->left,level-1,flip_flag);
		}
	}
}

void print_level_order_wrapper(struct node *head)
{
	cout<<"The Level Order of Binary Search Tree is :";
	int height_tree = height(head);
	for(int a=1;a<=height_tree;a++)
	{
		print_level_order(head,a,0);
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

void spiral_order_print(struct node *head)
{
	cout<<"The Spiral Level Order of Binary Search Tree is :";
	int height_tree = height(head);
	int flip_flag=0;
	for(int a=1;a<=height_tree;a++)
	{
		print_level_order(head,a,flip_flag);
		if(flip_flag==0)
		{
			flip_flag=1;
		}
		else
		{
			flip_flag=0;
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

bool is_mirror(struct node *a,struct node *b)
{
	if(a==NULL&&b==NULL)
	{
		return true;
	}
	if(a==NULL||b==NULL)
	{
		return false;
	}
	else
	{
		return is_mirror(a->left,b->right)&&is_mirror(a->right,b->left);
	}
}


int main(int argc, char* argv[])
{
	while(1)
	{
		clear();
		int choice;
		char temp;
		bool check;
		cout<<"BST BASICS\n";
		cout<<"1. Add new element\n";
		cout<<"2. Inorder View\n";
		cout<<"3. Pre Order View\n";
		cout<<"4. Post Order View\n";
		cout<<"5. Delete an element\n";
		cout<<"6. Tree to List View\n";
		cout<<"7. Size of tree\n";
		cout<<"8. Number of Subtrees in Range\n";
		cout<<"9. Number of Nodes in Range\n";
		cout<<"10. Remove Half nodes\n";
		cout<<"11. Kth Largest Element\n";
		cout<<"12. Check if balanced\n";
		cout<<"13. Minimum Vertex Cover\n";
		cout<<"14. Check if Complete BST\n";
		cout<<"15. Sum of all left leaves\n";
		cout<<"16. Remove paths less than k\n";
		cout<<"17. Bottom View\n";
		cout<<"18. Left View\n";
		cout<<"19. Right View\n";
		cout<<"20. Level Order View\n";
		cout<<"21. Spiral Order View\n";
		cout<<"22. Check if foldable\n";
		cout<<"23. Exit\n";
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
			case 7: size_of_tree_wrapper(&HEAD);
					break;
			case 8: nos_subtrees_in_range_wrapper(&HEAD);
					break;
			case 9: nos_nodes_in_range_wrapper(&HEAD);
					break;
			case 10:remove_half_nodes_wrapper(&HEAD);
					break;
			case 11:kth_largest_element_wrapper(&HEAD);
					break;
			case 12:is_balanced_wrapper(HEAD);
					break;
			case 13:minimum_vertex_cover_wrapper(HEAD);
					break;
			case 14:is_complete_wrapper(HEAD);
					break;
			case 15:left_leaf_sum_wrapper(HEAD);
					break;
			case 16:remove_short_paths_wrapper(&HEAD);
					break;
			case 17:bottom_view_wrapper(HEAD);
					break;
			case 18:left_view_wrapper(HEAD);
					break;
			case 19:right_view_wrapper(HEAD);
					break;
			case 20:print_level_order_wrapper(HEAD);
					break;
			case 21:spiral_order_print(HEAD);
					break;
			case 22:check = is_mirror(HEAD->left,HEAD->right);
					if(check)
					{
						cout<<"\nIt is foldable";
					}
					else
					{
						cout<<"\nIt is not foldable";
					}
					cout<<"\nPress Y to return : ";
					cin>>temp;
					while(temp!='Y')
					{
						cout<<"Press Y to return : ";
						cin>>temp;
					}
			default:break;
		}
		if(choice==23)
			break;
	}
	return 0;
}