#include<stdio.h>
#include<math.h>
#define E 30
#define O 10
void main()
{
 static int o[E+1],M1[E+1],s[E+1][O][3],m,m1[E+1],m2[E+1][O],M,ord;
 int p,q,r,f,e;
 clrscr();
 for(r=1;r<=sqrt(E);r++)
 for(p=1;p<=r;p++)
 for(q=p;q<=r;q++)
 {
  e=p*p+q*q+r*r;
  if(e<=E) {
	   ++o[e];s[e][o[e]][0]=p;s[e][o[e]][1]=q;s[e][o[e]][2]=r;
	   M1[e]++;M++;if(ord<M1[e]) ord=M1[e];
	   if(p==q&&q==r&&r==p) {m2[e][o[e]]=1; m1[e]+=1; m+=1;}
	   else if(p==q||q==r||r==p) {m2[e][o[e]]=3; m1[e]+=3; m+=3;}
	   else if(p!=q&&q!=r&&r!=p) {m2[e][o[e]]=6; m1[e]+=6; m+=6;}
	   }
 //printf("%d %2d %2d %2d\n",e,s[e][o[e]][0],s[e][o[e]][1],s[e][o[e]][2]);
 }
 //printf("\n\n");
 for(e=1;e<=E;e++)
 {
  printf("%3d",e);
  for(f=1;f<=o[e];f++) printf(" %2d %2d %2d ",s[e][f][0],s[e][f][1],s[e][f][2]);
  printf("%*c%3d  %3d\n",10*(ord-M1[e])+1,' ',M1[e],m1[e]);
 }
 printf("\n%*c%3d  %3d\n",10*ord+4,' ',M,m);
 for(e=1;e<=E;e++)
 {
  printf("%3d",e);
  for(f=1;f<=M1[e];f++)
  printf(" _ ");
  printf("\n");
 }
 printf"\n");
 for(e=1;e<=E;e++)
 {
  printf("%3d",e);
  for(f=1;f<=m1[e];f++)
  printf(" _ ");
  printf("\n");
 }
 getch();
}