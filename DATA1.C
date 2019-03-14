#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 int i,n;
 float sum1=0,sum2=0,a[50];
 clrscr();
 printf("enter the no. of observations\n");
 scanf("%d",&n);
 printf("enter the observations\n");
 for(i=0;i<n;i++)
 scanf("%f",&a[i]);
 printf("\nthe observations are:\n\n");
 for(i=0;i<n;i++)
 {
  printf("%5.2f ",a[i]);
  sum1+=a[i];
 }
 printf("\nthe mean of the observations is %5.2f",sum1/n);
 for(i=0;i<n;i++)
 sum2+=pow((sum1/n-a[i]),2);
 printf("\nthe standard deviation of the observatons is %5.2f",sqrt(sum2/n));
 getch();
}






































