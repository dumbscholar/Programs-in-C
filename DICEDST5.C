#include<stdio.h>
#include<math.h>
#define t 5
#define size 5*t+1
float mean(x,f,s)
int x[],f[],s;
{
 float sum=0,mean;
 int i;
 long int sumf=0;
 for(i=0;i<s;i++) {sum+=f[i]*(float)x[i];sumf+=f[i];}
 //printf("%f %ld",sum,sumf);
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
int mcnt(i,j,k,p,q)
int i,j,k,p,q;
{
 int e[t],f[t],n,cubesum=0;
 for(n=0;n<t;n++) f[n]=0;
 e[0]=i;e[1]=j;e[2]=k;e[3]=p;e[4]=q;
 for(n=0;n<t;n++)
 {
  if(e[n]==i) f[0]++;
  else if(e[n]==j) f[1]++;
  else if(e[n]==k) f[2]++;
  else if(e[n]==p) f[3]++;
  else if(e[n]==q) f[4]++;
 }
 for(n=0;n<t;n++)
 cubesum+=f[n]*f[n]*f[n];
 if(cubesum==5) return 120;
 if(cubesum==11) return 60;
 if(cubesum==17) return 30;
 if(cubesum==29) return 20;
 if(cubesum==35) return 10;
 if(cubesum==54) return 20;
 if(cubesum==65) return 5;
 if(cubesum==125) return 1;
}
void main()
{
 FILE *d;
 int i,j,k,p,q,l,a[size],mcn,sum;
 static int Ma[size],ma[size],Msum,cnt;
 static long int msum;
 clrscr();
 d=fopen("dice.txt","w");
 for(i=1;i<=6;i++)
 for(j=i;j<=6;j++)
 for(k=j;k<=6;k++)
 for(p=k;p<=6;p++)
 for(q=p;q<=6;q++)
 {
  sum=i+j+k+p+q;fprintf(d,"%d %d %d %d %d\t%d\n",i,j,k,p,q,sum);cnt++;
  for(l=0;l<Msum;l++) if(sum==a[l])
  {
   Ma[l]++;
   mcn=mcnt(i,j,k,p,q);ma[l]+=mcn;msum+=mcn;
   break;
  }
  if(l==Msum)
  {
   a[Msum]=sum;Ma[Msum++]++;
   mcn=mcnt(i,j,k,p,q);ma[l]+=mcn;msum+=mcn;
  }
 }
 fprintf(d,"\nno. of macrostates = %d\n",cnt);
 fprintf(d,"\nno. of microstates = %ld\n",msum);
 for(l=0;l<Msum;l++) fprintf(d,"\n%d\t%d %d",a[l],Ma[l],ma[l]);
 fprintf(d,"\nmean score = %.2f\n",mean(a,ma,Msum));
 printf("ok");
 fprintf(d,"\nstandard deviation = %.2f\n",stdev(a,ma,Msum));
 fclose(d);
 getch();
}

