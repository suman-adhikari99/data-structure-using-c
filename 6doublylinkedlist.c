#include<stdio.h>
#include<malloc.h>
struct node
{
	struct node *prev;
	int info;
	struct node *next;
};
void insertstart(struct node **s,int data);
void insertlast(struct node **s,int data);
void insertafter(struct node **s,struct node *ptr,int data);
struct node* find(struct node **s,int data);
int deletefirst(struct node **s);
int deletelast(struct node **s);
int deleteintermediate(struct node **s,struct node *ptr);
void veiwlist(struct node **s);
int getfirst(struct node **s);
int getlast(struct node **s);
int main()
{
    struct node *start=NULL;
	struct node *ptr;
	int choice,k,i;
	do
	{
	printf("\n1.insert at first:\n2.insert at last:\n3.insert after node:\n4.delete first node:\n5.delete last node:\n6.delete itermediate node:\n7.viewlist");
	printf("\n8.getfisrst\n9.get last\n10.exit");
	printf("\n\n\n                            enter your choice::");
	scanf("%d",&choice);
	switch(choice) 
	{
		case 1:
			printf("\nenter the data that you want to store in first node");
			scanf("%d",&k);
			insertstart(&start,k);
			break;
		case 2:
			printf("\nenter the data that you want to store in last node");
			scanf("%d",&k);
			insertlast(&start,k);
			break;
		case 3:
			printf("\nenter that element after which you want to insert data,and inserted data");
			scanf("%d%d",&k,&i);
			ptr=find(&start,k);
			insertafter(&start,ptr,i);
			break;
		case 4:
				printf("\n the deleted element is \t%d",deletefirst(&start));
				break;
		case 5:
			printf("\nthe deleted element is\t%d",deletelast(&start));
			break;
		case 6:
			printf("\nthe deleted element is\t%d",deleteintermediate(&start,ptr));
			break;
		case 7:
			viewlist(&start);
			break;
		case 8:
			printf("\nthe first  element is \t%d",getfirst(&start));
			break;
		case 9:
			printf("\nthe last element is \t%d",getlast(&start));
			break;
			default:
				printf("\ninvalid choice try again ...........");
	}
	}while(choice!=10);
/*	insertstart(&start,10);
	insertlast(&start,20);
	ptr=find(&start,20);
	insertafter(&start,ptr,30);
	printf("\nfirst value is %d",getfirst(&start));
	printf("\nlast value is %d",getlast(&start));
	deleteintermediate(&start,find(&start,30));
	viewlist(&start);*/
}
void insertstart(struct node **s,int data)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->info=data;
	p->prev=NULL;
	p->next=*s;
	*s=p;
}
void insertlast(struct node **s,int data)
{
    struct node *p,*t;
	p=(struct node*)malloc(sizeof(struct node));
	p->info=data;
	p->next=NULL;
	t=*s;
	if(*s==NULL)
	{
		p->prev=NULL;
		*s=p;
	}
	else{
		t=*s;
		while(t->next!=NULL)
		{
			t=t->next;
			p->prev=t;
			t->next=p;
		}
	}
}
void insertafter(struct node **s,struct node *ptr,int data)
{
		struct node *p;
		if(ptr==NULL)

			printf("\ninvalid insertion");

		else
		{
        p=(struct node*)malloc(sizeof(struct node));
		p->info=data;
		p->prev=ptr;
		p->next=ptr->next;
		     if(ptr->next!=NULL)
			ptr->next->prev=p;
			ptr->next=p;
		}
}
struct node* find(struct node **s,int data)
{
	struct node *t;
	if(*s==NULL)
        {
	return(NULL);
	}
	else{
		t=*s;
		while(t!=NULL)
		{
			if(t->info==data)
			return(t);
			t=t->next;
		}
		return(NULL);
	}
}
int deletefirst(struct node **s)
{
	struct node *t;
	if(*s==NULL)
	return(0);
	else
	{
		t=*s;
		*s=(*s)->next;
		(*s)->prev=NULL;
		free(t);
		return(1);
	}
}
int deletelast(struct node **s)
{
	struct node *t;
	if(*s==NULL)
	return(0);
	else{
		t=*s;
		while(t->next!=NULL)
		{
			t=t->next;
			if((*s)->next==NULL)
			*s=NULL;
			else
			t->prev->next==NULL;
			free(t);
		}
	}
}
int deleteintermediate(struct node **s,struct node *ptr)
{
	if(*s==NULL)
	return(0);
	if(ptr->prev==NULL)
	{
		*s=ptr->next;
		free(ptr);
		return(1);
	}
	if(ptr->next==NULL)
	{
		ptr->prev->next=ptr->next;
		free(ptr);
		return(1);
	}
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
	free(ptr);
	return(1);
}
int viewlist(struct node **s)
{
	struct node *t;
	if(*s==NULL)
	printf("list is empty");
	else
	t=*s;
	while(t!=NULL)
	{
		printf("%d   ",t->info);
		t=t->next;
	}
}
int getfirst(struct node **s)
{
	if(*s==NULL){
	printf("list is empty");
	return(-1);}
	else
	return((*s)->info);
}
int getlast(struct node **s)
{
	struct node *t;
	if(*s==NULL)
	{
		printf("list is empty");
		return(-1);
	}
	else
	{
		t=*s;
		while(t->next!=NULL)
			t=t->next;
			return(t->info);
	}
}
