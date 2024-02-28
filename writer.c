#include <stdio.h>
int wrt,mutex,rc;
void signal()
{
 wrt=1;
 mutex=1;

}
void write()
{
 if(wrt==1)
 {
 printf("writing\n");
 wrt=0;
 mutex=0;
 }else if(rc>0)
 {
 char t='n';
 printf("someone is reading,do you want to stop them y|n \n");
 scanf(" %c",&t);
 if(t=='y')
 signal();
 }
 else
 {
 char t;
 printf("someone is writing,do you want to stop them y|n \n");
 scanf(" %c",&t);
 if(t=='n')
 signal();
 }
}
void read()
{
 wrt=0;
 if(mutex==1)
 {
 rc++;
 printf("%d reading",rc);
 printf("\n");
 }
 else
 {
 printf("writing \n");

 }
}
int main() {
    printf("\nSaloni garg");
    printf("\n0905CS211149");
 wrt=1;
 mutex=1;
 rc=0;
 int s;
 do
 {
 printf("\nselect an option\n");
 printf("1.write\n");
 printf("2. read\n");

 scanf("%d",&s);
 switch(s)
 {
 case 1:
 {
 write();
 break;
 }
 case 2:
 {
 read();
 break;
 }

 }
 }while(s<3);
 return 0;
}