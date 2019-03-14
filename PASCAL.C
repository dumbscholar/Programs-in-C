#include<stdio.h>
#include<conio.h>
void main()
{
 int n,arr[17][17]={1},fld[5]={1,5,9,13,16},i,j,k,w;
 clrscr();
 printf("type the no. rows to be displayed: ");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(k=1;k<=5;k++)
  {
   if(n>fld[k-1])
   w=k;
  }
  for(k=(n-1-i);k>0;k--)
  printf("%*c",w,' ');
  arr[i][0]=1;arr[i][i+1]=0;
  for(j=1;j<=i;j++)
  {
   if(i!=0&&j!=0)
   arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
   printf("%*d",w,arr[i][j]);
   printf("%*c",w,' ');
  }
  printf("\n\n");
 }
 getch();
}