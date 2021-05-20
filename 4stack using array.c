#include<stdio.h>
#include<malloc.h>
struct arraystack
{
	int top;
	int capacity;
	int *array;
};
struct arraystack* createstack(int cap)
{
	struct arraystack *stack;
	stack=(struct arraystack*)malloc(sizeof(struct arraystack));
	stack->capacity=cap;
	stack->top=-1;
	stack->array=malloc(sizeof(int)*stack->capacity);
	return(stack);
}
int isfull(struct arraystack *stack)
{
	if(stack->top==stack->capacity-1)
	return(1);
	else
	return(0);
}
int isempty(struct arraystack *stack)
{
	if(stack->top==-1)
	return(1);
	else
	return(0);
}
void push(struct arraystack *stack, int item)
{
	if(!isfull(stack))
	{
		stack->top++;
		stack->array[stack->top]=item;
	}
}
int pop(struct arraystack *stack)
{
	int item;
	if(!isempty(stack))
	{
		item=stack->array[stack->top];
		stack->top--;
		return(item);
	}
	return(-1);
}
void display(struct arraystack *stack)
{
	int i;
	printf("\nthe avialable item in the satac are \t:");
	for(i=0;i<stack->top;i++)
	printf("%d\t",stack->array[i]);
}
int main()
{
	int choice, item;
	struct arraystack *stack;
	stack=createstack(5);
	do
	{
		printf("\n1.create stack\n2.push");
		printf("\n3.pop");
		printf("\n4.display");
		printf("\nenter your choice");
		scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nenter the size of stack");
			scanf("%d",&item);
			stack=createstack(item);
			break;
		case 2:
			printf("\nenter a number");
			scanf("%d",&item);
			push(stack,item);
			break;
		case 3:
			item=pop(stack);
			if(item==-1)
			printf("\npoped value is %d",item);
				break;
		case 4:
			display(stack);
			break;
		default:
		printf("\n invalid choice try again");
	} 
}while(choice!=5);
}
