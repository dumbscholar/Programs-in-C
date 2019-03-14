#include<stdio.h>
#include<math.h>
int main()
{
	float x,y,z;
	printf("Enter a number: ");
	scanf("%f",&x);
	y=round(x*100)/100;
	z=y+0.01;
	printf("\n%f has been rounded to %f and then to %f",x,y,z);
}
