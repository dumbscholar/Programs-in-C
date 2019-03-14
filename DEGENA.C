#include<stdio.h>
#include<math.h>
#define E 499
#define S 1801
#define O 14
void main()
{
 FILE *dgn;
 static int m,M,o[E+1],M1[E+1],s[E+1][O][3],m1[E+1],m2[E+1][O],maxM,maxm;
 int p,q,r,f,e;
 float empty;
 clrscr();
 dgn=fopen("degeneracy.doc","w");
 for(r=1;r<=sqrt(S+E);r++)
 for(p=1;p<=r;p++)
 for(q=p;q<=r;q++)
 {
  e=p*p+q*q+r*r;
  if(e>S&&e<=(S+E)) {
	   ++o[e-S];s[e-S][o[e-S]][0]=p;s[e-S][o[e-S]][1]=q;s[e-S][o[e-S]][2]=r;
	   M1[e-S]++;M++;
	   if(maxM<M1[e-S]) maxM=M1[e-S];
	   if(p==q&&q==r&&r==p) {m2[e-S][o[e-S]]=1; m1[e-S]+=1; m+=1;}
	   else if(p==q||q==r||r==p) {m2[e-S][o[e-S]]=3; m1[e-S]+=3; m+=3;}
	   else if(p!=q&&q!=r&&r!=p) {m2[e-S][o[e-S]]=6; m1[e-S]+=6; m+=6;}
	   if(maxm<m1[e-S]) maxm=m1[e-S];
	   }
 }
 for(e=S;e<=S+E;e++)
 {
  fprintf(dgn,"%6d-",e);
  if(M1[e-S]==0) empty++;
  for(f=1;f<=o[e-S];f++) fprintf(dgn," %2d %2d %2d ",s[e-S][f][0],s[e-S][f][1],s[e-S][f][2]);
  fprintf(dgn,"%*c-%4d-%5d\n",10*(maxM-M1[e-S])+1,' ',M1[e-S],m1[e-S]);
 }
 fprintf(dgn,"\n%*c%4d %5d\n",10*maxM+7,' ',M,m);
 fprintf(dgn,"\n%*c%4d %5d\n",10*maxM+7,' ',maxM,maxm);
 fprintf(dgn,"number of forbidden energy levels = %.0f\n",empty);
 fprintf(dgn,"percentage of energy levels forbidden = %.2f\n",100*empty/E);
 /*
 fprintf(dgn,"\nHISTOGRAM DEPICTING NUMBER OF MACROSTATES CORRESPONDING TO A GIVEN ENERGY\n");
 for(e=S;e<=S+E;e++)
 {
  fprintf(dgn,"%4d",e);
  for(f=1;f<=M1[e];f++)
  fprintf(dgn," | ");
  fprintf(dgn,"\n");
 }
 fprintf(dgn,"\nHISTOGRAM DEPICTING NUMBER OF MICROSTATES CORRESPONDING TO A GIVEN ENERGY\n");
 for(e=S;e<=S+E;e++)
 {
  fprintf(dgn,"%4d",e);
  for(f=1;f<=m1[e];f++)
  fprintf(dgn," | ");
  fprintf(dgn,"\n");
 }
 */
 fclose(dgn);
 getch();
}