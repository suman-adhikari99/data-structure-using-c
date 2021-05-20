#include<stdio.h>
void binarysearch(int A[],int N,int item)
{
	int l,u,m;
	l=0;
	u=N-1;
	while(l<=u)
	{
		m=(l+u)/2;
		if(item==A[m])
		{
			printf("searching is successful item found at index=%d",m);
			return;
		}
		else if(item<A[m])
		u=m-1;
		else
		l=m+1;
	}
	printf("search is unsuccessfull");
}
	void sort(int A[],int n)
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
int main()
{
	int A[]={10,31,4,5,61,7,8,9,11};
	sort(A,9);
	binarysearch(A,9,61);
}
