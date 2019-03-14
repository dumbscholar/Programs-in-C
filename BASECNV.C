#include<stdio.h>
#include<conio.h>
void main()
{
 char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
 char s[16];
 int cnt=0,n,b,k,i;
 clrscr();
 printf("enter the decimal positive integer\n");
 scanf("%d",&n);
 printf("enter the base\n");
 scanf("%d",&b);
 while(n!=0)
 {
  k=n%b;
  s[cnt]=a[k];
  n/=b;
  cnt++;
 }
 printf("the no. in new system is");
 for(i=cnt;i>=0;i--)
 printf("%c",s[i]);
 getch();
}

