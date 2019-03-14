#include<stdio.h>
int swap(int a,int b)
{
 a=a+b;
 b=a-b;
 a=a-b;
 return 1;
}
void main()
{
 int a,b,c;
 clrscr();
 scanf("%d %d",&a,&b);
 swap(a,b);
 printf("\n%d %d %d\n",a,b,c);
 getch();
}