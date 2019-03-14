#include<stdio.h>
#include<math.h>
int main()
{
 int i,k,s=0;
 float j,m,j1,j2,m1,m2;
 printf("enter the two j values: ");
 scanf("%f %f",&j1,&j2);
 if((j1<0||(round(2*j1)!=(2*j1)))||(j2<0||(round(2*j2)!=(2*j2)))) printf("\nERROR: invalid value(s)\n");
 else
 {
  j=j1+j2;
  i=2*j;
  printf("\n\t\t\t|j, m> = \n\n\t");
  for(i=i;i>=0;i-=2)
  for(k=i;k>=-i;k-=2)
  {
   printf("|%.1f, %.1f>\t",i/2.0,k/2.0);
   s++;
  }
  //printf("\n\nno. of eigenstates is %d.\n",s);
  //printf("\n|m1, m2> = \n\n");
  for(m1=j1;m1>=-j1;m1--)
  for(m2=j2;m2>=-j2;m2--)
  printf("\n|%.1f, %.1f>",m1,m2);
 }
 return 0;
}
