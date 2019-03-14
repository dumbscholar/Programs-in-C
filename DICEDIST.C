#include<stdio.h>
#include<math.h>
#define t 6
#define size 5*t+1
float mean(x,f,s)
int x[],f[],s;
{
 float sum=0,mean;
 int i;
 long int sumf=0;
 for(i=0;i<s;i++) {sum+=f[i]*(float)x[i];sumf+=f[i];}
 mean=sum/sumf;
 return mean;
}
float stdev(x,f,s)
int x[],f[],s;
{
 float sum=0,stdev;
 long int i,sumf=0;
 for(i=0;i<s;i++) {sum+=f[i]*pow((float)x[i],2);sumf+=f[i];}
 stdev=sqrt(sum/sumf-pow(mean(x,f,s),2));
 return stdev;
}
int mcnt(i,j,k,p,q,r)
int i,j,k,p,q,r;
{
 int e[t],f[t],n,cubesum=0;
 for(n=0;n<t;n++) f[n]=0;
 e[0]=i;e[1]=j;e[2]=k;e[3]=p;e[4]=q;e[5]=r;
 for(n=0;n<t;n++)
 {
  if(e[n]==i) f[0]++;
  else if(e[n]==j) f[1]++;
  else if(e[n]==k) f[2]++;
  else if(e[n]==p) f[3]++;
  else if(e[n]==q) f[4]++;
  else if(e[n]==r) f[5]++;
 }
 for(n=0;n<t;n++)
 cubesum+=f[n]*f[n]*f[n];
 if(cubesum==6) return 720;
 if(cubesum==12) return 360;
 if(cubesum==18) return 180;
 if(cubesum==24) return 90;
 if(cubesum==30) return 120;
 if(cubesum==36) return 60;
 if(cubesum==54) return 20;
 if(cubesum==66) return 30;
 if(cubesum==72) return 15;
 if(cubesum==126) return 6;
 if(cubesum==216) return 1;
}
void main()
{
 FILE *d;
 int i,j,k,p,q,r,l,a[size],mcn,sum;
 static int Ma[size],ma[size],Msum,cnt;
 static long int msum;
 clrscr();
 d=fopen("dice.txt","w");
 for(i=1;i<=6;i++)
 for(j=i;j<=6;j++)
 for(k=j;k<=6;k++)
 for(p=k;p<=6;p++)
 for(q=p;q<=6;q++)
 for(r=q;r<=6;r++)
 {
  sum=i+j+k+p+q+r;fprintf(d,"%d %d %d %d %d %d\t%d\n",i,j,k,p,q,r,sum);cnt++;
  for(l=0;l<Msum;l++) if(sum==a[l])
  {
   Ma[l]++;
   mcn=mcnt(i,j,k,p,q,r);ma[l]+=mcn;msum+=mcn;
   break;
  }
  if(l==Msum)
  {
   a[Msum]=sum;Ma[Msum++]++;
   mcn=mcnt(i,j,k,p,q,r);ma[l]+=mcn;msum+=mcn;
  }
 }
 fprintf(d,"\nno. of macrostates = %d\n",cnt);
 fprintf(d,"\nno. of microstates = %ld\n",msum);
 for(l=0;l<Msum;l++) fprintf(d,"\n%d\t%d %d",a[l],Ma[l],ma[l]);
 fprintf(d,"\nmean score = %.2f\n",mean(a,ma,Msum));
 fprintf(d,"\nstandard deviation = %.2f\n",stdev(a,ma,Msum));
 printf("ok");
 fclose(d);
 getch();
}

