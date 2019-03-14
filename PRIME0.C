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
 FILE *fl;
 long int prmcnt=0;
 double x,start,finish;
 clrscr();
 printf("\nenter the range: ");
 scanf("%lf %lf",&start,&finish);
 if(start<2) start=2;
 fl=fopen("prmfnd.txt","w");
 for(x=start;x<=finish;x++)
 if(isprime(x))
 {
  prmcnt++;
  printf("%.0lf ",x);
  fprintf(fl,"%.0lf ",x);
 }
 printf("\nprimecount stands at %ld",prmcnt);
 fprintf(fl,"\nprimecount stands at %ld",prmcnt);
 fclose(fl);
 getch();
}
