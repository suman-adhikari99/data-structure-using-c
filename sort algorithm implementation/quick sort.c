#include<stdio.h>
#include<conio.h>
/*list ko pahilo value lai tesko sahi position ma laane.ava pahilo value sahi position ma puge paxi tesko reference ma dui ota sublist banx tesko laagi pani feri 
same procedure laagaune yesto gardai jaada sub list yeti dherai xoto hunx ki yesko sublist ma dui ota vanda pani kam element hunx.
yedi sublist ma eutai matra element x tesma further kaam garn parne jarurat xoin kinki tyo aaphai ma solved x. */
void quick(int A[],int N,int BEG,int END,int *LOCPTR)//quick procedure
{
	int left,right,temp;
	left=BEG;
	right=END;
	*LOCPTR=BEG;
	step2:
		while(A[*LOCPTR]<A[right]&&*LOCPTR!=right)
		right--;
		if(*LOCPTR==right)
		return;
		if(A[*LOCPTR]>A[right])
		{
		temp=A[*LOCPTR];
		A[*LOCPTR]=A[right];
		A[right]=temp;
		*LOCPTR=right;	
		}
		goto step3;
		step3:
			while(A[*LOCPTR]>=A[left]&&left!=*LOCPTR)
			left++;
			if(left==*LOCPTR)
			return;
			if(A[*LOCPTR]<A[left])
			{
				temp=A[*LOCPTR];
				A[*LOCPTR]=A[left];
				A[left]=temp;
				*LOCPTR=left;
			}
			goto step2;
}
void quick_sort(int A[],int N)//quick algorithm
{
	int BEG,END,top=-1;
	int LOC;
	int lower[N],upper[N];
	if(N>1)
	{
		top++;
		lower[top]=0;
		upper[top]=N-1;
	}
	while(top!=-1)
	{
		BEG=lower[top];
		END=upper[top];
		top--;
		quick(A,N,BEG,END,&LOC);
		if(BEG<LOC-1)
		{
			top++;
			lower[top]=BEG;
			upper[top]=LOC-1;
		}
		if(LOC+1<END)
		{
			top++;
			lower[top]=LOC+1;
			upper[top]=END;
		}	
	}
}
int main()
{
	int A[]={12,4,54,54,33,5,66,77,33,445,32};
	int i;
	quick_sort(A,11);
	for(i=0;i<11;i++)
	printf("  %d",A[i]);
	getch();
}
