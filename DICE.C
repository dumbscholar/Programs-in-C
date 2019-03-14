#include<stdio.h>
void main()
{
 FILE *d;
 int i,j,k,p,l,a[21],sum;
 static int Ma[21],ma[21],Msum,cnt;
 clrscr();
 d=fopen("dice.txt","w");
 for(i=1;i<=6;i++)
 for(j=i;j<=6;j++)
 for(k=j;k<=6;k++)
 for(p=k;p<=6;p++)
 {
  sum=i+j+k+p;fprintf(d,"%d %d %d %d\t%d\n",i,j,k,p,sum);cnt++;
  for(l=0;l<Msum;l++) if(sum==a[l])
  {
   Ma[l]++;
   if(i==j&&j==k&&k==p) ma[l]+=1;
   else if((i==j&&j==k)||(i==j&&j==p)||(i==k&&k==p)||(j==k&&k==p)) ma[l]+=4;
   else if((i==j&&k!=p)||(j==k&&i!=p)||(i==k&&j!=p)||(i==p&&j!=k)||(j==p&&i!=k)||(k==p&&i!=j)) ma[l]+=12;
   else if(i==j||j==k||i==k||i==p||j==p||k==p) ma[l]+=6;
   else ma[l]+=24;
   break;
  }
  if(l==Msum)
  {
   a[Msum]=sum;Ma[Msum++]++;
   if(i==j&&j==k&&k==p) ma[l]+=1;
   else if((i==j&&j==k)||(i==j&&j==p)||(i==k&&k==p)||(j==k&&k==p)) ma[l]+=4;
   else if((i==j&&k!=p)||(j==k&&i!=p)||(i==k&&j!=p)||(i==p&&j!=k)||(j==p&&i!=k)||(k==p&&i!=j)) ma[l]+=12;
   else if(i==j||j==k||i==k||i==p||j==p||k==p) ma[l]+=6;
   else ma[l]+=24;
  }
 }
 fprintf(d,"\nno. of macrostates = %d\n",cnt);
 for(l=0;l<Msum;l++) fprintf(d,"\n%d\t%d %d",a[l],Ma[l],ma[l]);
 fclose(d);
 getch();
}

