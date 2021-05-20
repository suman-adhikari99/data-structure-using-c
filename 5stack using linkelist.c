#include<stdio.h>
#include<malloc.h>
struct node
{
int info;
struct node *next;	
};
struct node* create()
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	return(n);
}
struct node* push(struct node **s,int data)
{
	struct node *stack;
	//stack=(struct node*)malloc(sizeof(struct node));
	stack=create();
    if(stack!=NULL)
	stack->info=data;
	if(*s!=NULL)
	{
		stack->next=NULL;
		*s==stack;
		printf("\nnot");
		stack->next=*s;
		*s=stack;
	}
	return(*s);
}
void pop(struct node **s)
{
	struct node *temp,stack;
	int el;
	if(*s==NULL)
	printf("?");
	el=(*s)->info;
	temp=*s;
	*s=(*s)->next;
	free(temp);
	printf("%d",el);
	//return(el);
}
void display(struct node **s)
{
	struct node *stack;
	stack=*s;
	while(stack->next!=NULL){
	printf("the element in the stack are    %d",stack->info);
	stack=stack->next;
}
}
int main()
{
	int choice,var,k;
	struct node *s=NULL;
    s=push(&s,7);
}
/*	do
	{
	printf("\n1.pushed element in the stack\n2.poped element from the stack\n3.display\nchoose your choice");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	printf("\nenter the element you want to pushed in stack");
	scanf("%d",&var);
	s=push(&s,var);
	break;
	case 2:
		pop(&s);
		//printf("the poped element is %d",pop(&s));
		break;
		case 3:
			display(&s);
			break;
		default:
		printf("\ninvalid choice");
	}
}while(choice!=4);
}
*/
