#include<stdio.h>
#include<math.h>
int main()
{
 int i,j,N;
 float L,t,m[101]={0},x[101]={0},v[101]={0},v1,v2,E=0;
 char eq;
 printf("\nTIME EVOLUTION OF A SYSTEM OF FREE PARTICLES INSIDE A ONE DIMENSIONAL BOX (degree of freedom = 1)\n");
 printf("\nLength of the line (in metres): ");
 scanf("%f",&L);
 printf("\nNumber of (point) particles: ");
 scanf("%d",&N);
 printf("\nPopulation density (number of particles per unit length) is %.2f per metre\n",N/L);
 printf("\nAre the particles of equal mass? (Y/N): ");
 getchar();
 eq=getchar();
 if(!(eq=='Y'||eq=='y'||eq=='N'||eq=='n'))
 {
  printf("Please type 'Y' for Yes or 'N' for No as your answer. Type 'Q' to Quit.\n");
  getchar();
  eq=getchar();
 }
 if(eq=='Q'||eq=='q') return 0;
 printf("\nEnter the mass of each particle in SI unit:\n");
 if(eq=='N'||eq=='n')
 for(i=1;i<=N;i++)
 {
  printf("Mass of particle %d : ",i);
  scanf("%f",&m[i]);
  m[0]+=m[i];
 }
 if(eq=='Y'||eq=='y')
 {
  scanf("%f",&m[0]);
  for(i=0;i<=N;i++)
  m[i]=m[0];
  m[0]*=N;
 }
 printf("\nMass of the system of %d particles is %.2f\n",N,m[0]);
 printf("\nAssuming origin to be at the left end of the line, enter the initial values for position and velocity in SI units.\n");
 for(i=1;i<=N;i++)
 {
  position: printf("\nPosition of particle %d at t=0 : ",i);
  scanf("%f",&x[i]);
  if(x[i]<0||x[i]>L)
  {
   printf("Position invalid, must lie in the range 0 to %f",L);
   goto position;
  }
  printf("Velocity of particle %d at t=0 : ",i);
  scanf("%f",&v[i]);
 }
 for(i=1;i<=N;i++)
 {
  x[0]+=m[i]*x[i];
  v[0]+=m[i]*v[i];
  printf("\nMomentum of particle %d at t=0 is %.2f",i,m[i]*v[i]);
  printf("\nKinetic Energy of particle %d at t=0 is %.2f\n",i,0.5*m[i]*v[i]*v[i]);
  E+=0.5*m[i]*v[i]*v[i];
 }
 x[0]/=m[0];
 printf("\nPosition of Center of Mass of the system at t=0 is %.2f",x[0]);
 printf("\nTotal Linear Momentum of the system is %.2f",v[0]);
 v[0]/=m[0];
 printf("\nVelocity of Center of Mass of the system at t=0 is %.2f",v[0]);
 printf("\nTotal Kinetic Energy of the system is %.2f",E);
 printf("\nKinetic Energy of Center of Mass of the system at t=0 is %.2f",0.5*m[0]*v[0]*v[0]);
 //QUANTISATION or SAMPLING of POSITION and VELOCITY
 printf("\n\ndiscretized position coordinates are:\n\n");
 for(i=1;i<=N;i++)
 {
  x[i]=round(x[i]*100)/100;
  printf("%f ",x[i]);
 }
 printf("\n\ndiscretized velocity coordinates are:\n\n");
 for(i=1;i<=N;i++)
 {
  v[i]=round(v[i]);
  printf("%f ",v[i]);
 }
 //MOTION AND COLLISION (only in between neighbouring particles)
 printf("\n\ntime (s)\tparticle\tposition (m)\tvelocity (v)\n");
 for(t=0;t<=10;t+=0.01)
 {
  printf("\n%.2f",t);
  for(i=1;i<=N;i++) printf("\t%d\t%.2f\t%.2f\n",i,x[i],v[i]);
  for(i=1;i<=N;i++)
  {
   for(j=i+1;j<=N;j++)
   {
    //printf(" %f ",fabs(x[i]-x[j]));
    if(fabs(x[i]-x[j])<0.001)
    {
     //printf("ok");
     printf("particle %d and %d collided with each other\n",i,j);
     v1=v[i];
     v2=v[j];
     v[i]=((m[i]-m[j])*v1+2*m[j]*v2)/(m[i]+m[j]);
     v[j]=(2*m[i]*v1+(m[j]-m[i])*v2)/(m[i]+m[j]);
     v[i]=round(v[i]);
     v[j]=round(v[j]);
    }
   }
   for(i=1;i<=N;i++)
   {
    if((fabs(x[i]-0)<0.001)&&v[i]<0) printf("particle %d collided with left wall\n",i);
    if((fabs(x[i]-L)<0.001)&&v[i]>0) printf("particle %d collided with right wall\n",i);
    if(((fabs(x[i]-0)<0.001)&&v[i]<0)||((fabs(x[i]-L)<0.001)&&v[i]>0)) v[i]=-v[i];
    x[i]+=v[i]*0.01;
   }
  }
 }
 //printf("\nAssumptions: Free Point particles, Perfectly Elastic Collisions, Minimum Time = 0.01 s, Minimum Length = 0.01 m, Minimum Speed = 1 m/s")
 return 0;
} // 10 2 1 2 3 2 7 -1
