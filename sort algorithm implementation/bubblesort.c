#include<stdio.h>
int main()
{
	int n;
	int a[]={5,55,44,3,22,4,55,6};
	bubble_sort(a,8);
	for(n=0;n<8;n++)
	printf("   %d",a[n]);
}
	void bubble_sort(int A[],int n)
	{
		int temp,round,i;
		for(round=1;round<n;round++)
		for(i=0;i<=n-1-round;i++)
		if(A[i]>A[i+1])
		{
			temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
		}
	}
	

