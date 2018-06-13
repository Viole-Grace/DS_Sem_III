//DFS - Depth First Search
//Time Complexity - O(V+E)
//Data Structure Used - Stack( Recursive )
// 	DIFFERENCE:
// BFS: Explores the closest vertices from source, moves outward - Hence, uses a Queue.
// DFS: Explores the vertex farthest away on the link, then backtracks - Hence, uses a Stack.
// USES: Single Solution Problems (e.g : Mazes), Cycle Detection in a Graph, Topological Sorting

//FUNCTIONS : 
//void attach(int v, nodeptr* head) : Attaches a node 'v' to the Graph
//void createGraph() : Creates a Graph
//void displayAdjList() : Displays Adj. List
//void dfs(int v) : Given a node 'v', performs DFS from that node.

********************************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
	int vertex;
	struct node* link;
};
typedef struct node* nodeptr;
nodeptr graph[20]={NULL};
int visited[20]={0};
int n;
void attach(int v, nodeptr* head)
{
	nodeptr new;
	nodeptr temp;
	temp=*head;
	new = (nodeptr)malloc(sizeof(struct node));
	new->vertex=v;
	new->link=NULL;
	if(*head==NULL)
	{
		*head=new;
		return;
	}
	for(; temp->link; temp=temp->link); //Notice the semicolon
	temp->link=new;
}
void createGraph()
{
	int i,numcon,j,v;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Enter number of vertices connected to vertex %d\n",i);
		scanf("%d",&numcon);
		printf("Enter the vertices connected to vertex %d\n",i);
		for(j=0;j<numcon;j++)
		{
			scanf("%d",&v);
			attach(v, &graph[i]);
		}
	}
}
void displayAdjList()
{
	int i;
	nodeptr x;
	for(i=0; i<n; i++)
	{
		printf("%d  --->",i);
		x=graph[i];
		for(;x;x=x->link)
		{
			printf("%d--->",x->vertex);
		}
		printf("NULL\n");
	}
}
void dfs(int v)
{
	nodeptr w;
	visited[v]=1;
	printf("%d\t",v);
	for(w=graph[v]; w; w=w->link)
	{
		if(!visited[w->vertex])
			dfs(w->vertex);
	}
}
int main()
{
	int choice,i,ch;
	double start,end;
	while(1)
	{
		printf("\n1. Create Graph \n2. Display Adjacency List \n3. DFS \n4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: createGraph();
					break;
			case 2:	displayAdjList();
					break;
			case 3: for(i=0;i<n;i++)
				{
					visited[i]=0;
				}	
					start=clock();
					dfs(0);
					end=clock();
					printf("\nThe time taken for execution of DFS is : %f", (end-start)/(double)CLOCKS_PER_SEC);
					break;
			case 4: printf("Operation Complete\n");
					exit(0);
		}
	}
}
