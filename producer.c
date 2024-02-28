#include<stdio.h>
#include<stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0;
void produce()
{
--mutex;
++full;
--empty;
x++;
printf("\nProducer produces""item %d",x);
++mutex;
}
void consume()
{
--mutex;
--full;
++empty;
printf("\nConsumer consumes ""item %d",x);
x--;
++mutex;
}
int main()
{
    printf("\nsaloni garg");
    printf("\n0905CS211149");
int n, i;
printf("\n1. Press 1 for Producer"
"\n2. Press 2 for Consumer"
"\n3. Press 3 for Exit");
for (i = 1; i > 0; i++)
{
printf("\nEnter your choice:");
scanf("%d", &n);
switch (n)
{
case 1:
if ((mutex == 1)
&& (empty != 0))
{
produce();
}
else
{
printf("Buffer is full!");
}
break;
case 2:
if ((mutex == 1)
&& (full != 0))
{
consume();
}
else
{
printf("Buffer is empty!");
}
break;
case 3:
exit(0);
break;
}
}
}