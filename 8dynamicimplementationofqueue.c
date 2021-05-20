#include<stdio.h>
#include<malloc.h>
struct queueAdt
{
	int capacity;
	int rear;
	int front;
	int *array;
};
struct queueAdt* createqueue(int cap)
{
	struct queueAdt *temp;
	temp=(struct queueAdt*)malloc(sizeof(struct queueAdt));
	temp->capacity=cap;
	temp->front=temp->rear=-1;
	temp->array=(int*)malloc(sizeof(int)*temp->capacity);
}
int isemptyqueue(struct queueAdt *q)
{
	if(q->front==-1)
	{
		return 1;
	}
	return 0;
}
int isfullqueue(struct queueAdt *q)
{
	if(q->front==0&&q->rear==q->capacity-1)
	return 1;
	else
	return 0;
}
void halfqueue(struct queueAdt *q)
{
	int *temp;
	int i,j,l;
	l=q->capacity/2;
	temp=(int*)malloc(sizeof(int)*l);
	for(i=0;i<l;i++)
	{
		j=q->front;
		temp[i]=q->array[j];
		if(j==q->capacity-1)
		j=0;
		else
		j++;
	}
	free(q->array);
	q->array=temp;
	q->capacity=q->capacity/2;
	q->rear=l-1;
	q->front=0;
}

void doublequeue(struct queueAdt *q)
{
	int *temp;
	int i,j,l;
	temp=(int*)malloc(sizeof(q->capacity*2));
	l=q->capacity*2;
	for(i=0;i<l;i++)
	{
		j=q->front;
		temp[i]=q->array[j];
		if(j==q->capacity-1&&q->rear!=i)
		{
			j=0;
		}
		else
		j++;
	}
	q->array=temp;
	q->capacity=l;
	q->rear=l/2-1;
	q->front=0;
}
void  enqueue(struct queueAdt *q,int value)
{
		if(q->front==-1&&q->rear==-1)
		{
		q->array[0]=value;
		q->rear=0;
		q->front=0;
		}
		else if(isfullqueue(q))
		{
		doublequeue(q);
		q->rear=q->rear+1;
		q->array[q->rear]=value;
		}
		else
		{
			if(q->rear==q->capacity-1)
			q->rear=-1;
			else
			q->rear=q->rear+1;
			q->array[q->rear]=value;
		}
}
int dequeue(struct queueAdt *q)
{
	int data;
	if(isemptyqueue)
	printf("invalid opreration\nqueue is empty");
	else
	data=q->array[q->front];
	q->front=q->front+1;
	return data;
}
void display(struct queueAdt *q)
{
	int i;
	printf("the data aviable in queue are\n");
	for(i==q->front;i<=q->rear;i++)
	{
		printf("\t%d",q->array[q->front]);
	}
	printf("\ncapacity=%d",q->capacity);
	printf("\nrear=%d\nfront=%d",q->rear,q->front);
}
int main()
{
struct queueAdt *q;
q=createqueue(4);
enqueue(q,5);
display(q);
}

