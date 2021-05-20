#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct arrayAdt
{
	int capacity;
	int lastindex;
	int *ptr;
};
struct arrayAdt* createArray(int capacity)
{
	struct arrayAdt *arr;
	arr=(struct arrayAdt *)malloc(sizeof(struct arrayAdt));
	arr->capacity=capacity;
	arr->lastindex=-1;
	arr->ptr=(int *)malloc(arr->capacity*sizeof(int));
	return(arr);
}
int getItem(struct arrayAdt *arr,int index)
{
	if(arr->lastindex<index||index<0)
	{
		printf("\ninvalid index");
		return(-1);
	}
	else
	{
		return(arr->ptr[index]);
	}
	
}
int setItem(struct arrayAdt *arr, int index,int value)
{
	int i;
	if(arr->lastindex==arr->capacity-1)
	{
		printf("overflow");
		return(0);
	}
	if(index<0||index>arr->lastindex+1)
	{
		printf("invalid index");
		return(0);
	}
	if(index<=arr->lastindex)
	{
		arr->lastindex=arr->lastindex+1;
		i=arr->lastindex;
		while(i!=index)
		{
			arr->ptr[i]=arr->ptr[i-1];
			i--;
		}
		arr->ptr[index]=value;
		return(1);
	}
int editItem(struct arrayAdt *arr,int index,int newvalue)
{
	if(index<0||index>arr->lastindex)
	{
		printf("invalid index");
		return(0);
	}
	else
	{
		arr->ptr[index]=newvalue;
		return(1);
	}
}
int removeItem(struct arrayAdt *arr, int index)
{
	if(index<0||index>arr->lastindex)
	{
		printf("invalid index");
		return(0);
	}
	if(index<arr->lastindex)
	{
		int i;
		i=index;
		while(i<arr->lastindex)	{
			arr->ptr[i]=arr->ptr[i+1];
			i++;
		}
		arr->lastindex=arr->lastindex-1;
		return(1);
	}
	if(index==arr->lastindex)
	{
	 arr->lastindex=arr->lastindex-1;
	 return(1);
	}
	int search(struct arrayAdt *arr,int item)
	{
		int i;
		if(arr->lastindex==-1)
		{
			return(-1);
		}
		for(i=0;i<=arr->lastindex;i++)
		{
			if(arr->ptr[i]==item)
			return(i);
		}
		return(-1);
	}
	void sort(struct arrayAdt *arr)
	{
		int i,r,n,t;
		n=arr->lastindex+1;
		for(r=0;r<n-1;i++)
		{
			if(arr->ptr[i]>arr->ptr[i+1])
			{
			t=arr->ptr[i];
			arr->ptr[i]=arr->ptr[i+1];
			arr->ptr[i+1]=t;
		}
		}
		
	}
	int main()
	{
		int i;
		struct arrayAdt *arr;
		arr=createArray(4);
		setItem(arr,0,10);
		setItem(arr,1,20);
		setItem(arr,2,30);
		for(i=0;i<coutItem(arr);i++)
		{
			printf("%d  ",getItem(arr,i));
		}
		editItem(arr,0,90);
		getch();
		}
	
