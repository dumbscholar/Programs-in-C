#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm,midx,maxx,size,ypix,n;
float t,y,v,h,tf,g=9.8;
void *buff;
char buffer[50];
clrscr();
printf("enter initial time, position and velocity: ");
scanf("%f %f %f",&t,&y,&v);
printf("enter final time: ");
scanf("%f",&tf);
printf("enter the no. of intervals: ");
scanf("%d",&n);
h=(tf-t)/n;
getch();
initgraph(&gd,&gm,"C:\\tc\\bgi");
maxx=getmaxx();
midx=maxx/2;
circle(midx,80,20);
floodfill(midx,80,WHITE);
size=imagesize(midx-20,60,midx+20,100);
buff=malloc(size);
getimage(midx-20,60,midx+20,100,buff);
getch();
line(midx-50,100,midx+50,100);
while(t<=tf)
{
cleardevice();
ypix=y*50+80;
outtextxy(midx-150,20,"BALL FREELY FALLING UNDER GRAVITY");
line(midx-50,100,midx+50,100);
putimage(midx-20,ypix,buff,XOR_PUT);
y=y+h*v;
v=v+h*g;
t=t+h;
sprintf(buffer,"t = %.2f, y = %.2f, v = %.2f ",t,y,v);
outtextxy(midx+70,ypix,buffer);
delay(h*3000);
}
getch();
closegraph();
}


