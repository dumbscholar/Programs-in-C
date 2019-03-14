#include<stdio.h>
int main()
{
 int n;
 float h,t,tf,g=9.8,y,v;
 printf("Enter the initial values of time (sec), position (metres) and velocity (m/s):\n");
 scanf("%f %f %f",&t,&y,&v);
 printf("Enter the final time (sec): ");
 scanf("%f",&tf);
 printf("Enter the number of intervals: ");
 scanf("%d",&n);
 h=(tf-t)/n;
 printf("\n\tFREE FALL\n");
 printf("\ntime (s)\tposition (m)\tvelocity (m/s)\n");
 printf("%.2f\t\t%.3f\t\t%.2f\n",t,y,v);
 while(t<=tf)
 {
  y+=h*(v+v+h*g)/2;
  v+=h*g;
  t+=h;
  printf("%.2f\t\t%.3f\t\t%.2f\n",t,y,v);
 }
 printf("\n\At time, t = %.2f s, position, y= %.3f m and velocity, v = %.2f m/s",t,y,v);
 return 0;
}
