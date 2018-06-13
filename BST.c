//BST - Binary Search Tree
//Time Complexity - Search - O(n), Delete - O(n), Insert - O(n)
//Uses - Solving Expression Parsers, Indexing a Data-Base
//Data Structure Used - Tree

//Functions :
//void insert(treepointer *root, int d) : Node Insertion, given the 'root' of the tree, a node 'd' is inserted.
//boolean search(treepointer root, int d) : Searches for node with element 'key'. Returns True if key is found in the tree.
//void inOrder(treepointer ptr) : Prints Inorder traversal of the tree.
******************************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
typedef enum{false, true} boolean;
struct node
{
	int key;
	struct node *llink;
	struct node *rlink;
};
typedef struct node* treepointer;
void insert(treepointer *root, int d)
{
	if((*root)==NULL)
	{
		*root=(treepointer)malloc(sizeof(struct node));
		(*root)->key=d;
		(*root)->llink=NULL;
		(*root)->rlink=NULL;
		return;
	}
	else if(d>((*root)->key))
	{
		insert(&((*root)->rlink), d);
	}
	else if(d<((*root)->key))
	{
		insert(&((*root)->llink), d);
	}
}
boolean search(treepointer root, int d)
{
	if(root==NULL)
		return false;
	else if(root->key==d)
	{
		return true;
	}
	else if(d>((root)->key))
	{
		return search((root)->rlink, d);
	}
	else if(d<((root)->key))
	{
		return search(((root)->llink), d);
	}
}
void inOrder(treepointer ptr)
{
	if(ptr)
	{
		inOrder(ptr->llink);
		printf("%d\t",ptr->key);
		inOrder(ptr->rlink);
	}
}
int main()
{
	treepointer root;
	root=NULL;
	int choice,key;
	while(1)
	{
		printf("\n1. Insert\n2. InOrder Traversal\n3. Search\n4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter key to be inserted\n");
					scanf("%d",&key);
					insert(&root, key);
					break;
			case 2:	inOrder(root);
					printf("\n");
					break;
			case 3: printf("Enter key to be searched for: ");
					scanf("%d",&key);
					if(search(root, key))
						printf("Data found\n");
					else
						printf("Data not found\n");
					break;
        	case 4: printf("Operation Complete\n");
        			exit(0);
		}
	}
}
