#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
 int n,j;
 float L,C,q,i,f,T,t,tf,h,LC,E,k1,k2,k3,k4,s1,s2,s3,s4;
 printf("Enter the values of L, C, q (initial), i (initial), t (initial time) and tf (final time): ");
 scanf("%f %f %f %f %f %f",&L,&C,&q,&i,&t,&tf);
 printf("Enter the number of intervals: ");
 scanf("%d",&n);
 h=(tf-t)/n;
 LC=-L*C;
 f=1/(2*3.1416*sqrt(L*C));
 T=1/f;
 E=(q*q)/(2*C)+(L*i*i/2);
 printf("\n\t\t\t\tLC circuit\n");
 printf("\nt (s)   q (C)    i (A)   E (J)   k1    s1    k2    s2    k3    s3    k4    s4\n");
 for(j=1;j<=n;j++)
 {
  k1=i;
  s1=q/LC;
  k2=i+(s1*h)/2;
  s2=(q+k1*h/2)/LC;
  k3=i+(s2*h)/2;
  s3=(q+k2*h/2)/LC;
  k4=i+s3*h;
  s4=(q+k3*h)/LC;
  if(j%2!=0) printf("%5.2f  %7.4f  %7.4f  %.2f  %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f\n",t,q,i,E,k1,s1,k2,s2,k3,s3,k4,s4);
  t=t+h;
  q+=(h/6)*(k1+2*k2+2*k3+k4);
  i+=(h/6)*(s1+2*s2+2*s3+s4);
  E=(q*q)/(2*C)+(L*i*i/2);
 }
 printf("%5.2f  %7.4f  %7.4f  %.2f\n",t,q,i,E);
 printf("\nAt t = %.2f s, q = %.4f C and i = %.4f A",t,q,i);
 printf("\nFrequency of the LC oscillator is %.4f Hz",f);
 printf("\nTime period of the LC oscillator is %.4f s",T);
 return 0;
}


