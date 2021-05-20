#include<stdio.h>
#include<malloc.h>
struct ArrayQueue
{
	int rear,front;
	int capacity;
	int *array;
};
struct ArrayQueue* createQueue(int capacity)
{
	struct ArrayQueue *q;
	q=malloc(sizeof(struct ArrayQueue));
	if(!q)
	return(NULL);
	q->capacity=capacity;
	q->front=q->rear=-1;
	q->array=(int*)malloc(q->capacity*sizeof(int));
	if(!q->array)
	return(NULL);
	return(q);
}
int isemptyQueue(struct ArrayQueue *q)
{
	if(q->front==-1)
	return 1;
	else 
	return 0;
}
int isfullQueue(struct ArrayQueue *q)
{
	return((q->rear+1)%q->capacity==q->front);
}
int Queuesize(struct ArrayQueue *q)
{
	return((q->capacity-q->front+q->rear+1)%q->capacity);
}
void enQueue(struct ArrayQueue *q, int data)
{
	if(q->capacity==0)
	printf("\nqueue is not created first call the create function");
	else if(isfullQueue(q))
	printf("\n                          overflow");
	else
	{
		q->rear=(q->rear+1)%q->capacity;
		q->array[q->rear]=data;
		if(q->front==-1)
		q->front=q->rear;
	}
}
int deQueue(struct ArrayQueue *q) 
{
	int v;
	if(isemptyQueue(q))
	{
		printf("queue is empty");
		return(0);
	}
	else
	{
		v=q->array[q->front];
		if(q->front==q->rear)
		{
			q->front=q->rear=-1;
		}
		else
		q->front=(q->front+1)%q->capacity;
	}
	return(v);
}
void deleteQueue(struct ArrayQueue *q)
{
	if(q)
	{
		if(q->array)
		{
			free(q->array);
		}
		free(q);
}
}
void display(struct ArrayQueue *q)
{
	int i;	
	printf("\nelement in queue are:");
	for(i=0;i<q->capacity;i++)
	{
	 printf("\t%d",q->array[i]);
	}
}
int main()
{
	struct ArrayQueue *q;
	int k,choice;
//	q=createQueue(4);
	do{
		printf("\n1.create queue\n2.enqueue\n3.isfull queue\n4.is empty queue\n5.delete\n6.delete queue\n7.dispaly queue element\n8.queusize");
		printf("\n\n                              enter your choice:  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nenter the capacity of the queue you want to create");
				scanf("%d",&k);
				q=createQueue(k);
				break;
			case 2:
				
					if(q->capacity==0)
					printf("\nqueue is not created first call the create function");
					printf("\nenter the element you want add in queue");
					scanf("%d",&k);
					enQueue(q,k);
					break;
			case 3:
				if(isfullQueue(q))
				printf("\nqueue is full");
				else
				printf("\nnot full");
				break;
			case 4:
				if(isemptyQueue(q))
				printf("\nqueue is empty");
				else
				printf("\nnot empty");
				break;
			case 5:
				deQueue(q);
				printf("\nthe deleted element is   %d",deQueue(q));
				break;
			case 6:
				deleteQueue(q);
				break;
			case 7:
				display(q);
				break;
			case 8:
				printf("\nthe number of element store in queue is \t%d ",Queuesize(q));
				break;
			default:
				printf("\n    invalid choice try again.........");
		}
	}while(choice!=9);
}

