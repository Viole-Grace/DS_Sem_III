//Linked Stacks - Optimization of space against regular Stacks.
//Below Implementation uses multiple linked stacks.
//FUNCTIONS : Self Explanatory

*******************************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
typedef struct element
{
	int key;
}element;
struct stack
{
	element data;
	struct stack *link;
};
typedef struct stack* stackpointer;
stackpointer top[10];
void push(element item,int i)
{
	stackpointer temp;
	temp=(stackpointer)malloc(sizeof(struct stack));
	temp->data=item;
	temp->link=top[i];
	top[i]=temp;
}
element pop(int i)
{
	stackpointer temp=top[i];
	element item;
	if(!temp)
	{
		item.key=-1;
		return item;
	}
	item=temp->data;
	top[i]=temp->link;
	free(temp);
	return item;
}
void display(int i)
{
	stackpointer temp;
	temp=top[i];
	if (top[i]==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	printf("stack %d is\n",i+1);
	for(;temp;temp=temp->link)
		printf("%d\n",temp->data.key);
	printf("\n");
}
int main()
{
	int stackno,choice;
	element item;
	while(1)
	{
		printf("Enter\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
		scanf("%d",&choice);
		if(choice!=4)
		{
			printf("Enter stack number from 1-10\n");
			scanf("%d",&stackno);
		}
		switch(choice)
		{
			case 1: printf("Enter data to be inserted: ");
					scanf("%d",&item.key);
					push(item,stackno-1);
					break;
			case 2: item=pop(stackno-1);
					if(item.key==-1)
						printf("Stack empty\n");
					else
						printf("Element deleted: %d\n",item.key);
					break;
			case 3: display(stackno-1);
					break;
			case 4: printf("Operation Complete\n");
					exit(0);
		}
	}
}
