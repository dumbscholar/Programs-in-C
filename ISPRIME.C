#include<stdio.h>
#include<math.h>
void isprime(long double n)
{
 long double i;
 for(i=2;i<=sqrtl(n);i++)
 if((n/i)==floorl(n/i)) {printf("%.0Lf",i);return;}
 printf("prime");
}
void main()
{
 long double n;
 clrscr();
 printf("enter number: ");
 scanf("%Lf",&n);
 //n=pow(2,n)-1;
 //printf("%.0Lf\n",n);
 isprime(n);
 getch();
}
