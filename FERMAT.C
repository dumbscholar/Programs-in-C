#include<stdio.h>
#include<math.h>
void isprime(double x)
{
 double i;
 for(i=2;i<=sqrt(x);i++)
 if(isint(x/i)) {printf("%.0lf\n",i);return;break;}
 printf("prime\n");return;
}
int isint(double x)
{
 if(x==floor(x)) return(1);
 else return(0);
}
void main()
{
 unsigned int i;
 double x;
 clrscr();
 printf("\nenter a number: ");
 scanf("%lf",&x);
 //for(i=0;i<=8;i++)
 {
  x=pow(2,x)-1;
  //printf("%u %.0lf ",i,x);
  isprime(x);
 }
 getch();
}
