#include<stdio.h>
#include<conio.h>
void main()
{
 int i,n,product;
 clrscr();
 printf("enter a natural no.\n");
 scanf("%d",&n);
 product=1;
 for(i=1;i<=n;i++)
 {
 product*=i;
 }
 printf("the factorial of %d is %d",n,product);
 getch();
}