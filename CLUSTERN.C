#include<stdio.h>
#include<math.h>
void main()
{
 FILE *cp;
 double n=100,i,x,xmin=-100,xmax=200,step=.01,v,d=1;
 clrscr();
 cp=fopen("clusterpotential.txt","w");
 if(step==0) exit();
 //for(n=10000;n<=100000;n+=1000)
 {
 //x=n/2-.5;
 for(x=xmin;x<=xmax;x+=step)
 {
  v=0;
  for(i=0;i<n*d;i+=d)
  v+=pow(-1,i)*(1/fabs(x-i));
  fprintf(cp,"%lf_%lf\n",x,v);
 }
 }
 fclose(cp);
 getch();
}