#include<stdio.h>
#include<conio.h>
void TOH(int,char,char,char);
void main()
{
	int n;
	printf("enter number of disks");
	scanf("%d",&n);
	TOH(n,'o','d','i');
	getch();
	}
	void TOH(int n,char A,char B,char C)
	{
		if(n>0)
		{
			TOH(n-1,A,C,B);
			printf("move disk %d form %c to %c \n",n,A,B,C);
			TOH(n-1,C,B,A);
		}
	}
