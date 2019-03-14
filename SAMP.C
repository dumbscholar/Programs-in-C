#include<stdio.h>
void swap(a,m,n)
int a[],m,n;
{
 int temp;
 temp=a[m];
 a[m]=a[n];
 a[n]=temp;
}
void square(int x)
{
 x=x*x;
}
void main()
{
 int a[5],m,n,i;
 clrscr();
 for(i=0;i<=4;i++)
 scanf("%d",&a[i]);
 scanf("%d %d",&m,&n);
 swap(a,m,n);
 //square(m);
 for(i=0;i<=4;i++)
 printf("%d",a[i]);
 getch();
}


