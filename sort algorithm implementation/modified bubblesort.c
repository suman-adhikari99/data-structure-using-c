#include<stdio.h>
void bubblesort(int A[],int n)
{
	int temp,flag,i,round;
	for(round=1;round<n;round++)
	{
		flag=0;
		for(i=0;i<=n-1-round;i++)
		if(A[i]>A[i+1])
		{
			flag=1;
			temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
		}
		if(flag==0)
		{
			printf("total round=%d",round);
			return;
		}
	}
}
int main()
{
	int j;
	int a[]={22,5,3,44,3,44,5,33,3};
	bubblesort(a,9);
	for(j=0;j<9;j++)
	printf("%d\n	",a[j]);
}
