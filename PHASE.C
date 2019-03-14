#include<stdio.h>
void main()
{
 long double J,n,i;
 clrscr();
 printf("J = ");scanf("%Lf",&J);
 printf("n = ");scanf("%Lf",&n);
 for(i=1;i<21;i++)
 printf("\n%.0Lf\t%Lf",i,(J*i-1)/n);
 getch();
}

