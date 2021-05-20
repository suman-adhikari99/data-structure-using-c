#include<stdio.h>
int min(int A[],int k,int n)
{
	int MIN,loc,i;
	MIN=A[k];
	loc=k;
	for(i=k+1;i<n;i++)
	{
		if(MIN>A[i])
		{
			MIN=A[i];
			loc=i;
		}
	}
	return loc;
}
int main()
{
	int a[]={33,4,5,22,4,55,33,66,89};
	int k,temp,loc;
	for(k=0;k<9-1;k++)
	{
		loc=min(a,k,9);
		temp=a[k];
		a[k]=a[loc];
		a[loc]=temp;
	}
	for(k=0;k<9;k++)
	printf("  %d",a[k]);
}
