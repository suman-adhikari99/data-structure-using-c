#include<stdio.h>
#include<malloc.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
typedef struct node NodeType;
NodeType *last=NULL;
NodeType *first=NULL;
void insertbeg(int el)
{
    NodeType *Newnode;
    //Newnode=(NodeType*)malloc(sizeof(NodeType));
    Newnode->info=el;
    if(first==NULL)
    {

        first=Newnode;
        last=Newnode;
        Newnode->next=Newnode;
        Newnode->prev=Newnode;
    }
    else
    {

        Newnode->next=first;
        first->prev=Newnode;
        first=Newnode;
        last->next=first;
        first->prev=last;
    }
}
void insertend(int el)
{
	NodeType *Newnode;
	Newnode=(NodeType*)malloc(sizeof(NodeType));
	Newnode->info=el;
	if(first==NULL)
	{
		
        first=Newnode;
        last=Newnode;
        Newnode->next=Newnode;
        Newnode->prev=Newnode;
	}
	else
	{
        last->next=Newnode;
		Newnode->prev=last;
		last=Newnode;
		last->next=first;
		first->prev=last;
	}
}
void deletefirst()
{
	NodeType *temp;
	temp=first;
	if(first==NULL)
	{
		printf("Empty list");
	}
	else if(first==last)
	{
	
		first=NULL;
		last=NULL;
		free(temp);
	}
	
	else
	{
		first=first->next;
		last->next=first;
		first->prev=last;
		free(temp);
	}
}
void deletelast()
{
	NodeType *temp;
	temp=first;
	if(last==NULL)
	{
		printf("list is empty");
	}
	else if(first==last)
	{
		first=NULL;
		last=NULL;
		free(temp);
	}
	else
	{
		while(temp->next!=last)
		{
			temp=temp->next;
		}
	last=temp;
	last->next=first;
	first->prev=last;
	free(temp->next);
}
}
void display()
{
	NodeType *temp;
	temp=first;
	if(first==NULL)
	{
		printf("list is empty");
	}
	else
	{
		while(temp!=last)
		{
			printf("%d\t",temp->info);
			temp=temp->next;
		}
	}
}
void main()
{
	int choice;
	int item;
	printf("1:insert at begining");
	printf("\n2:insert at last");
	printf("\n3:delete first node");
	printf("\n4:delete last node");
	prinft("\n5:display");
	while(choice>6)
	{
		printf("\nenter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("insert data item to be inserted");
				scanf("%d",&item);
				insertbeg(item);
				break;
			case 2:
				printf("insert data item to be inserted");
				scanf("%d",&item);
				insertend(item);
				break;
			case 3:
				deletefirst();
				break;
			case 4:
				deletelast();
				break;
			case 5:
				display();
				break;
			default:
				printf("invalid choice please enter correct choice");
		}
	}
}
