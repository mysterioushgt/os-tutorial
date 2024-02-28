#include <stdio.h>
int p[5];
int ch[5];
int signal(int z)
{
int j=(z+1)%5;
p[z]=0;
ch[z]=0;
ch[j]=0;
}
void wait(int y)
{
int r=(y+1)%5;
if((ch[y]==0) &&(ch[y+1]==0))
{
p[y]=1;
ch[y]=1;
ch[r]=1;
}
else if(p[y]==1)
{
int w;
printf("do you want the philosopher %d to stop eating",y);
scanf("%d",&w);
if(w==1)
signal(y);
}
else
{
printf("chopstick %d %d are busy \n",y,r);
printf("philosopher %d has to wait \n",y);
}
}
int main()
{
     printf("\nSaloni garg");
    printf("\n0905CS211149");
int i,u;
for(i=0;i<5;i++)
{
p[i]=0;
ch[i]=0;
}
do
{
for(i=0;i<5;i++)
{
if(p[i]==0)
{
printf("\nphiloshpher %d is thinking ",i);
// printf("\n");
}
else
{
printf("philoshpher %d is eating ",i);
 //printf("\n");
}
}
int s;
printf("\nwhich philosopher wants to eat");
scanf("%d",&s);
wait(s);
printf("do you want to continue press 1\n");
scanf("%d",&u);
}while(u==1);
return 0;
}