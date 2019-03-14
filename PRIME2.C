#include<stdio.h>
#include<math.h>
int isprime(double x)
{
 long int i;
 for(i=2;i<=sqrt(x);i++)
 if(isint(x/i)) {return(0);break;}
 return(1);
}
int isint(double x)
{
 long int i;
 i=x;
 if(x==i) return(1);
 else return(0);
}
void main()
{
 long int prmcnt=0;
 double a,b,x;
 float compln;
 clrscr();
 printf("\nenter the range: ");
 scanf("%lf %lf",&a,&b);
 for(x=a;x<=b;x++)
 {
  if(isprime(x)) prmcnt++; //{printf(" %.0lf ",x);}
  compln=100*((x-a)/(b-a));
  if(isint(compln/2)) printf("|",compln);
 } //if(isint(log10(x)))
 printf(" %ld\n",prmcnt);
 getch();
}
