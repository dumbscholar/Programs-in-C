#include<stdio.h>
#include<conio.h>
void main()
{
 int i,j,n,count=1;
 printf("Enter no. of rows of Floyd's triangle to be shown: ");
 scanf("%d",&n);
 printf("\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=i;j++) printf("%d\t",count++);
  printf("\n");
 }
 getch();
}