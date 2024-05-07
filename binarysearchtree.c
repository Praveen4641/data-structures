//c program to implement binary search trees using recursion
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *lchild,*rchild;
}; 
typedef struct node NODE;
NODE *root=NULL;
NODE* insert(NODE* ,int );
void inorder(NODE* );
void preorder(NODE* );
void postorder(NODE* );
void search(NODE*,int );
int height(NODE* );
int count_nodes(NODE *);
int edges(NODE *);
int main()
{
	int ch,item,key;
	while(1)
	{
		printf("\n>>>MENU<<<\n");
		printf("1.Insert\n");
		printf("2.Inorder Traversal\n");
		printf("3.Pre Order Traversal\n4.Post Order Traversal \n5.Key to be Search in the tree\n6.Height of the tree and Depth of the tree\n7.The no of nodes in the tree\n8.The no of edges in the tree\n9.Exit\n");
		printf("Enter your choice :\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("enter element to be inserted:");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:	inorder(root);
				break;
			case 3:	preorder(root);
				break;
			case 4:	postorder(root);
				break;
			case 5:	printf("enter the key:");
				scanf("%d",&key);
				search(root,key);
				break;	
			case 6:	height(root);
				printf("Height of the tree is:%d\n",height(root));
				printf("Depth of the tree is :%d",height(root));
				break;
			case 7:	count_nodes(root);
				printf("the no.of nodes im the tree is :%d",count_nodes(root));		
				break;
			case 8:	edges(root);
				printf("No.of edges in the tree is:%d",edges(root));
				break;	
			case 9:	exit(0);
			default:printf("enter invalid choice\n");				
		}
	}
}

NODE *insert(NODE *root,int item)
{
	if(root==NULL)
	{
		root=(NODE*)malloc(sizeof(NODE));
		root->data=item;
		root->rchild=root->lchild=NULL;
	}
	else if(item>root->data)
	{
		root->rchild=insert(root->rchild,item);
	}
	else
	{
		root->lchild=insert(root->lchild,item);
	}
	return root;
}

void inorder(NODE *root)
{
	if(root->lchild!=NULL)	
		inorder(root->lchild);
	printf("%d ",root->data);
	if(root->rchild!=NULL)
		inorder(root->rchild);	
}

void preorder(NODE*root)
{
	printf("%d ",root->data);
	if(root->lchild!=NULL)
		preorder(root->lchild);
	if(root->rchild!=NULL)
		preorder(root->rchild);	
}

void postorder(NODE *root)
{
	if(root->lchild!=NULL)
		postorder(root->lchild);
	if(root->rchild!=NULL)
		postorder(root->rchild);
	printf("%d ",root->data);		
}

void search(NODE *root,int key)
{
	if(root==NULL)
		printf("key is not found\n");
	else if(key==root->data)
		printf("key is found in the tree\n");	
	else if(key>root->data)	
		search(root->rchild,key);
	else
		search(root->lchild,key);	
}

int height(NODE*root)
{
	int lst,rst;
	if(root!=NULL)
	{
		lst=height(root->lchild);
		rst=height(root->rchild);
		if(lst<=rst)
			return (rst+1);
		else
			return (lst+1);	
	}
	else
		return 0;
}

int count_nodes(NODE *root)
{
	if(root==NULL)
		return 0;
	else	
		return (count_nodes(root->lchild)+count_nodes(root->rchild)+1);
}
int edges(NODE *root)
{
	if(root==NULL)
		return 0;
	else
		return (count_nodes(root)-1);	
}
