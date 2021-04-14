/* 6.6.	Да се најдат природните броеви помали од n, чиј збир на кубовите на цифри-те е еднаков на самиот број. */


#include <stdio.h>


int main(void){

int n;
printf("Vnesi broj : \n");
scanf("%d",&n);
int sum=0;
int cifra1,cifra2,cifra3;
int i=001;
while (i<=n)
{
    cifra1=i-((i/10)*10);
    cifra2=(i/10)-((i/100)*10);
    cifra3=(i/100)-((i/1000)*10);
    sum=(cifra1*cifra1*cifra1)+(cifra2*cifra2*cifra2)+(cifra3*cifra3*cifra3);
    if(sum==i){
        printf("%d ",sum);
    }
    i++;
}






    return 0;
}