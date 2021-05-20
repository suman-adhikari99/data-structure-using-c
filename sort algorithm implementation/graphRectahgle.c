#include<stdio.h>
#include<conio.h>#
#include<graphic.h>
#include<dos.h>
void flood(int,int,int,int);
void main()
{
int gd,gm=DETECT;
clrscr();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"BGI");
rectangle(50,50,100,100);
getch();
}
