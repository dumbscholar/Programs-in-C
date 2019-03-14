#include<stdio.h>
#include<conio.h>
void main()
{
 int a[20][20],i,j,n;
 clrscr();
 printf("enter no. of rows\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  for(j=1;j<=(n-i);j++)
  printf(" ");
  a[i][0]=1;a[i][i+1]=0;
  for(j=0;j<=i;j++)
  {
   if(i!=0&&j!=0)
   a[i][j]=a[i-1][j-1]+a[i-1][j];
   printf("%d ",a[i][j]);
  }
  printf("\n");
 }
 getch();
}
