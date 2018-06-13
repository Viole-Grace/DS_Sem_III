#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *llink;
    struct node *rlink;
};
typedef struct node* nodepointer;
void insert(int item,nodepointer head)
{
    nodepointer temp;
    temp=(nodepointer)malloc(sizeof(struct node));
    temp->key=item;
    temp->llink=head;
    temp->rlink=head->rlink;
    head->rlink->llink=temp;
    head->rlink=temp; 
    head=temp;
}
void delete(int item, nodepointer head)
{
    head=head->rlink;
    if(head==NULL)
    {
        printf("EMPTY LIST : No element to be deleted\n");
        return;
    }
    if((head)->key==-1)
    {
        printf("Cannot delete header node\n");
        return;
    }
    while((head)->key!=-1)
    {
        if((head)->key==item)
        {
            printf("Element deleted : %d",item);
            if(head->rlink)
                (head->llink)->rlink=head->rlink;
            if(head->llink)
                (head->rlink)->llink=head->llink;
            return;
        }
        head=head->rlink;
    }
    printf("Element not found\n");
    return;
}
void displayr(nodepointer head)
{
    head=head->rlink;
    if(head==NULL)
    {
        printf("EMPTY LSIT\n");
        return;
    }
    while((head->rlink)->key!=-1)
    {
        printf("%d\t",head->key);
        head=head->rlink;
    }
    if(head->key!=-1)
        printf("%d\n",head->key);
    else
        printf("EMPTY LIST\n");
}
void displayf(nodepointer head)
{
    head=head->llink;
    if(head==NULL)
    {
        printf("EMPTY LSIT\n");
        return;
    }
    while((head->llink)->key!=-1)
    {
        printf("%d\t",head->key);
        head=head->llink;
    }
    if(head->key!=-1)
        printf("%d\n",head->key);
    else
        printf("EMPTY LIST\n");
}
int main()
{
    int ch,element;
    nodepointer first;
    first=(nodepointer)malloc(sizeof(struct node));
    first->key=-1;
    first->llink=first;
    first->rlink=first;
    while(1)
    {
        printf("\nEnter\n1. Insert\n2. Delete\n3. Display Forward\n4. Display Backward\n5. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter element to be inserted\n");
                scanf("%d",&element);
                insert(element,first);
                break;
            case 2: printf("Enter element to be deleted\n");
                    scanf("%d",&element);
                    delete(element, first);
                break;
            case 3: printf("List is\n");
                displayf(first);
                break;
            case 4: printf("List is\n");
                displayr(first);
                break;
            case 5:printf("Operation Complete\n");
                exit(0);
        }
    }
}
