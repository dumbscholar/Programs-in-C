#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 //FRONT WHEEL WITH TYRE, PIVOT AND ROD
 circle(200,300,50);
 circle(200,300,55);
 floodfill(252,300,WHITE);
 circle(200,300,10);
 circle(200,300,2);
 floodfill(200,300,WHITE);
 line(200,300,238,205);
 //MUDGUARD
 arc(200,300,0,90,60);
 line(200,300,256,284);
 //REAR WHEEL WITH TYRE, PIVOT, SMALL GEAR AND ROD
 circle(400,300,50);
 circle(400,300,55);
 floodfill(452,300,WHITE);
 circle(400,300,10);
 circle(400,300,2);
 floodfill(400,300,WHITE);
 line(400,300,348,205);
 //MUDGUARD
 arc(400,300,0,135,60);
 line(400,300,456,284);
 //BIG GEAR
 circle(320,300,20);
 circle(320,300,3);
 floodfill(320,300,WHITE);
 //CENTRAL STRUCTURE OF THREE RODS
 line(320,300,348,205);
 line(320,300,235,215);
 line(238,205,348,205);
 //TWO PEDALS
 line(320,280,400,290);
 line(320,320,400,310);
 line(320,280,320,275);
 rectangle(315,275,325,270);
 floodfill(320,273,WHITE);
 line(320,300,320,325);
 rectangle(315,325,325,330);
 floodfill(320,327,WHITE);
 //SEAT ATOP AN EXTENSION ROD
 line(348,205,353,190);
 rectangle(328,190,363,180);
 floodfill(343,185,WHITE);
 //HANDLE ATOP AN EXTENSION ROD
 line(238,205,246,185);
 circle(248,180,5);
 floodfill(248,180,WHITE);
 circle(238,180,3);
 floodfill(238,180,WHITE);
 line(248,180,238,180);
 //CARRIER
 line(363,230,433,230);
 line(400,300,420,230);
 //HEADLIGHT
 arc(230,207,260,100,7);
 arc(240,207,150,210,14);
 floodfill(235,207,WHITE);
 //BELL
 rectangle(243,185,253,187);
 floodfill(252,186,WHITE);
 floodfill(244,186,WHITE);
 getch();
 closegraph();
 return 0;
}