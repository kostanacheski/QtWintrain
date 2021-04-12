/*3.      Да се напише програма која ќе пресметува Питагорини броеви до 100. 
Тоа се броеви кои го исполнуваат следниот услов a2+b2=c2. */


#include <stdio.h>
#include <math.h>

int main(void){
int a,b,c;
for(a=1;a<=100;a++)
{
    for(b=a;b<=100;b++)
    for(c=b;c<=100;c++)
    if(c*c==a*a+b*b)//if(pow(c,2)==(pow(a,2)+pow(b,2)))
    { 
        printf("%d^2+%d^2=%d^2\n",a,b,c);
    }
}


    return 0;
}