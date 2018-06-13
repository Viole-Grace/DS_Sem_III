// Time Complexity - O(1)
// Data Structure Used - Queue(Circular)
// Removes the drawbacks of a Regular Queue by utilising empty spaces resulting from deletion of elements
// Uses - CPU Scheduling, Memory Management

// Functions :
// void create() : Creates a Queue of Size 'size'
// void copy(element *start,element *end,element *nq) : Copies an Existing Queue data to a new Queue
// void queueFull() : Resizes the length of queue to twice the current length, if length is reached.
// void enQueue(element item) : Enters an element 'item' into the Queue
// element deQueue() : Removes an element from the Queue
// void displayQueue() : Displays given Queue.

******************************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int key;
}element;
element *queue=NULL;
int rear=0,front=0,size=2;
void create()
{
	queue=(element*)malloc(size*sizeof(element));
}
void copy(element *start,element *end,element *nq)
{
	while(start!=end)
	{
		*nq=*start;
		nq++;
		start++;
	}
}
void queueFull()
{
	element *nq;
	nq=(element*)malloc(2*size*sizeof(queue));
	int start=(front+1)%size;
	if(start<2)
		copy(queue+start,queue+start+size-1,nq);
	else
	{
		copy(queue+start,queue+size,nq);
		copy(queue,queue+rear+1,nq+size-start);
	}
	front=2*size-1;
	rear=size-2;
	size*=2;
	free(queue);
	queue=nq;
}
void enQueue(element item)
{
	rear=(rear+1)%size;
	if (front==rear)
	{
		queueFull();
		rear=(rear+1)%size;
	}
	queue[rear]=item;
}
element deQueue()
{
	element item;
	if(front==rear)
	{
		item.key=-1;
		return item;
	}
	front=(front+1)%size;
	return queue[front];
}
void displayQueue()
{
	int i=front+1;
	if(front==rear)
		printf("\nThe Queue is empty\n");
	else
	{
		printf("\n");
		for(i=(front+1)%size;i!=(rear);i=(i+1)%size)
		{ 
			printf("%d ",queue[i].key);
		}
		printf("%d ",queue[i].key);
		printf("\nfront=%d\trear=%d\n",front,rear);
	}
}
int main()
{
	int choice;
	int n;
	element item;
	create();
	do
	{
		printf("enter choice\n");
		printf("MENU\n");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		scanf("%d",&choice);		
		switch(choice)
		{
			case 1: printf("enter element\n");
					scanf("%d",&n);
					item.key=n;
					enQueue(item);
					break;
			case 2: item=deQueue();
					if(item.key==-1)
						printf("queue is empty\n");
					else
						printf("element deleted is %d\n",item.key);
					break;
			case 3: displayQueue();
					break;
			case 4: printf("operation complete\n");
					break;
			default: printf("invalid choice\n");
					 break;
		}
	}while(choice!=4);
}
