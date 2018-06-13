//Max Heap - Complete Binary tree, where Parent node is > either of its children nodes
//Since Heap is a Complete BT, an Array representation is easier and typical
//Left Child - given by (i * 2) ; Right Child - given by (i * 2) + 1, where i is the array position of the parent node
//USES : Priority Queue, Heap Sort
//Traversal - Level Order

//FUNCTIONS : 
//void insert(element item, int *n) : Inserts an element into array
//element deleteHeap(int *n) : Removes an element from the array
//void display(int n) : Displays Heap

*******************************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101
typedef struct
{
	int key;
}element;
element heap[MAX_SIZE];
void insert(element item, int *n)
{
	int i;
	if((*n)==MAX_SIZE-1)
	{
		printf("Heap Full\n");
		return;
	}
	i=++(*n);
	while(i!=1 && item.key>heap[i/2].key)
	{
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=item;
}
element deleteHeap(int *n)
{
	int parent, child;
	element temp, item;
	if(*n==0)
	{
		printf("Heap Empty\n");
		item.key=-1;
		return item;
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while(child<=*n)
	{
		if(child<*n && heap[child].key < heap[child+1].key)
			child++;
		if(temp.key >= heap[child].key)
			break;
		heap[parent]=heap[child];
		parent=child;
		child=child*2;
	}
	heap[parent]=temp;
	return item;
}
void display(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d\n",heap[i].key);
	}
}
int main()
{
	int choice,n=0;
	element item;
	while(1)
	{
		printf("MENU : \n 1. Insert\n 2. Display\n 3. Delete\n 4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter element to insert : ");
					scanf("%d", &item.key);
					insert(item, &n);
					break;
			case 2:	printf("Heap is\n");
					display(n);
					break;
			case 3: item = deleteHeap(&n);
					if(item.key!=-1)
						printf("Element Deleted : %d\n",item.key);
					break;
			case 4: printf("Operation Complete\n");
            		exit(0);
		}
	}
}
