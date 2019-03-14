#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
int main()
{
 int n,i,gd=DETECT,gm,midx,midy,xpix,ypix;
 float H,vy,vx,g=9.8,t=0,x,y,v,tf,h,scalex,scaley;
 printf("enter the height and horizontal launch velocity: ");
 scanf("%f %f",&H,&v);
 printf("enter the no. of intervals: ");
 scanf("%d",&n);
 tf=sqrt(2*H/g);
 h=(tf-t)/n;
 x=0;y=H;vx=v;vy=0;
 printf("\n\tHORIZONTAL PROJECTILE\n");
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
 outtextxy(260,430,"distance (m)");
 settextstyle(0,VERT_DIR,1);
 outtextxy(40,260,"height (m)");
 x=0;y=H;vy=0;vx=v;t=0;
 scalex=520/(vx*tf);
 scaley=340/H;
 for(i=1;i<=n;i++)
 {
  xpix=60+x*scalex;
  ypix=410-y*scaley;
  delay(1000*h);
  putpixel(xpix,ypix,WHITE);
  x+=h*vx;
  y+=h*vy;
  vy-=h*g;
  t+=h;
 }
 getch();
 closegraph();
 return 0;
}
