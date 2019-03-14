#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#define PI 3.1416
int main()
{
 int n,i,gd=DETECT,gm,midx,midy,xpix,ypix;
 float theta,vy,vx,g=9.8,t=0,x,y,v,tf,h,scalex,scaley,scale,H;
 char buffer[10];
 printf("enter the launch angle (in degrees) and launch velocity: ");
 scanf("%f %f",&theta,&v);
 printf("enter the no. of intervals: ");
 scanf("%d",&n);
 H=pow((v*sin(theta*PI/180)),2)/(2*g);
 tf=2*sqrt(2*H/g);
 h=(tf-t)/n;
 x=0;y=0;
 vx=v*cos(theta*PI/180);
 vy=v*sin(theta*PI/180);
 printf("\n\tPROJECTILE\n");
 printf("\nt\tx\ty\tvx\tvy");
 printf("\n%.2f\t%.3f\t%.3f\t%.2f\t%.3f",t,x,y,vx,vy);
 for(i=1;i<=n;i++)
 {
  x+=h*vx;
  y+=h*vy;
  vy-=h*g;
  t+=h;
  if(i%10==0) printf("\n%.2f\t%.3f\t%.3f\t%.2f\t%.3f",t,x,y,vx,vy);
 }
 //getch();
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 cleardevice();
 midx=getmaxx()/2;
 midy=getmaxy()/2;
 settextstyle(0,HORIZ_DIR,2);
 outtextxy(60,30,"HORIZONTAL PROJECTILE");
 rectangle(midx-260,midy-170,midx+260,midy+170);
 settextstyle(0,HORIZ_DIR,1);
 outtextxy(260,midy+180,"distance (m)");
 outtextxy(50,midy+180,"0");
 settextstyle(0,VERT_DIR,1);
 outtextxy(40,260,"height (m)");
 x=0;y=0;t=0;
 vx=v*cos(theta*PI/180);
 vy=v*sin(theta*PI/180);
 scalex=520/(vx*tf);
 scaley=340/H;
 if(scalex<=scaley)
 {
  scale=scalex;
  sprintf(buffer,"%.2f",vx*tf);
  settextstyle(0,HORIZ_DIR,1);
  outtextxy(midx+250,midy+180,buffer);
  sprintf(buffer,"%.2f",vx*tf*340/520);
  settextstyle(0,VERT_DIR,1);
  outtextxy(40,midy-150,buffer);
 }
 else
 {
  scale=scaley;
  sprintf(buffer,"%.2f",H);
  settextstyle(0,VERT_DIR,1);
  outtextxy(40,midy-150,buffer);
  sprintf(buffer,"%.2f",H*520/340);
  settextstyle(0,HORIZ_DIR,1);
  outtextxy(midx+250,midy+180,buffer);
 }
 for(i=1;i<=n;i++)
 {
  xpix=60+x*scale;
  ypix=410-y*scale;
  delay(1000*h);
  putpixel(xpix,ypix,WHITE);
  x+=h*vx;
  vy-=h*g;
  y+=h*vy;
  t+=h;
 }
 getch();
 closegraph();
 return 0;
}
