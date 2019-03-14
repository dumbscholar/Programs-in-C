#include<stdio.h>
#include<conio.h>
void main()
{
 float x;
 clrscr();
 scanf("%f",&x);
 printf("|%*.2f|",6,x);
 getch();
}