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
 unsigned int i,inext=1;
 long int prmcnt;
 double x,compln;
 clrscr();
 printf("\nenter the bound power of 10: ");
 scanf("%u",&i);
 for(x=2;x<=pow(10,i);x++)
 {
  if(isprime(x)) prmcnt++; //{printf(" %.0lf ",x);}
  compln=100*x/pow(10,inext);
  //if(isint(compln/2)) printf("|",compln);
  if(isint(x/pow(10,inext-1))) {printf("\n1-%.0lf\t\t%ld",x,prmcnt);if(isint(log10(x))) inext++;}
 }
 getch();
}
