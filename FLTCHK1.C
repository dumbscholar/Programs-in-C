#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 float b;
 clrscr();
 printf("enter a no.\n");
 scanf("%f",&b);
 if(floor(b)==b)
 printf("not a floating point");
 else printf("a floating point");
 getch();
}
