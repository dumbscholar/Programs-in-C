#include<stdio.h>
#include<conio.h>
void main()
{
    int a[100],b[100],i,j,d;
    clrscr();
    printf("Mention the depth of the Pascal triangle: ");
    scanf("%d",&d);
    printf("\n\n");
    for(i=0;i<=d;i++)
    {
        a[0]=1;a[i]=1;
        for(j=0;j<=i;j++) b[j]=a[j];
        printf("%d\t",a[0]);
        for(j=1;j<=i;j++)
        {
            if(j!=i) a[j]=b[j-1]+b[j];
            printf("%d\t",a[j]);
        }
        printf("\n");
    }
    getch();
}