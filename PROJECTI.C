#include<stdio.h>
#include<math.h>
#define PI 3.1416
int main()
{
 int i,n;
 float h,t,tf,g=9.8,x,y,v,vx,vy,theta;
 printf("Enter the initial values of time (sec), x-coordinate (metres) and y-coordinate (metres):\n");
 scanf("%f %f %f",&t,&x,&y);
 printf("Enter the initial values of launch velocity (m/s) and launch angle (in degrees):\n");
 scanf("%f %f",&v,&theta);
 printf("Enter the number of intervals: ");
 scanf("%d",&n);
 tf=2*v*sin(theta*PI/180)/g;
 h=(tf-t)/n;
 //printf("%f %f",tf,h);
 vx=v*cos(theta*PI/180);
 vy=v*sin(theta*PI/180);
 printf("\n\t\t\t\tPROJECTILE MOTION\n");
 printf("\ntime (s)\tx-coordinate (m)\ty-coordinate (m)\tvertical velocity (m/s)\n");
 printf("%.2f\t\t%.3f\t\t\t%.3f\t\t\t%.2f\n",t,x,y,vy);
 for(i=1;i<=n;i++)
 {
  x+=h*vx;
  y+=h*(vy+vy-h*g)/2;
  vy-=h*g;
  t+=h;
  printf("%.2f\t\t%.3f\t\t\t%.3f\t\t\t%.2f\n",t,x,y,vy);
 }
 //printf("\n\At time, t = %.2f s, position, y= %.3f m and velocity, v = %.2f m/s",t,y,v);
 return 0;
}
