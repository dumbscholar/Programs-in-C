#include<stdio.h>
void main()
{
 int i,a[10];
 char s[10];
 clrscr();
 for(i=0;i<10;i++)
 printf("%d\t%u\n",a[i],&a[i]);
 gets(s);
 printf("%s",s);
 getch();
}