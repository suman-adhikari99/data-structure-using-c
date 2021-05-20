#include<stdio.h>
void insertion_sort(int A[],int N)
{
	int i,j,temp;
	for(i=1;i<N;i++)
	{
		temp=A[i];
		for(j=i-1;j>=0&&temp<A[j];j--)
		{
			A[j+1]=A[j];
			A[j]=temp;
		}
	}
}
int main()
{
	int A[]={33,5,4,2,11,23,4,55,63,3};
	int i;
	insertion_sort(A,10);
	for(i=0;i<10;i++)
	printf("   %d",A[i]);
}
