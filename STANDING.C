#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<alloc.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1416
void main()
{
int n,i,gd=DETECT,gm,scalex,scaley,midx,midy;
float A,h,T,amp,lam,tf,y,vel,ti=0,len,t;
clrscr();
printf("\nEnter amplitude and wavelength and velocity and length: ");
scanf("%f%f%f%f",&amp,&lam,&vel,&len);
printf("\nEnter no. of time cycles: ");
scanf("%d",&n);
t=ti;
T=lam/vel;
tf=n*T;
h=T/10;
printf("\nepoch\tamplitude\n");
printf("\n%0.2f\t%0.4f",t,A);
while(t<=tf)
{
A=0;
t=t+h;
for(i=1;i<100;i++)
{
y=amp*sin(2*PI*(i*(len/100)-vel*t)/lam)+amp*sin(2*PI*(i*(len/100)+vel*t)/lam);
if(fabs(y)>A) A=fabs(y);
}
printf("\n%0.2f\t%0.4f",t,A);
}
getch();
initgraph(&gd,&gm,"C:\\TC\\BGI");
midx=getmaxx()/2;
midy=getmaxy()/2;
line(midx-200,midy-20,midx-200,midy+20);
line(midx+200,midy-20,midx+200,midy+20);
scalex=400/len;
scaley=100/amp;
for(i=1;i<400;i++)
putpixel(midx-200+1*i,midy,WHITE);
getch();
t=ti;
T=lam/vel;
tf=n*T;
h=T/10;
while(t<=tf)
{
cleardevice();
line(midx-200,midy-20,midx-200,midy+20);
line(midx+200,midy-20,midx+200,midy+20);
t=t+h;
for(i=1;i<400;i++)
{
y=amp*sin(2*PI*(i*len/400-vel*t)/lam)+amp*sin(2*PI*(i*len/400+vel*t)/lam);
putpixel(midx-200+1*i,midy+y*scaley,GREEN);
}
delay(100*T);
}
getch();
closegraph();
}