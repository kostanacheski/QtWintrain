/*3.	Да се најде спротивен број на природниот број n. 
(Тоа е природниот број што ги има истите цифри со n, напишани во спротивен редослед.)*/

#include <stdio.h>

int main(void)
{

int n;
printf("Vnesi broj:\n");
scanf("%d",&n);

int tmp;
while(n>0){
    tmp*=10;
    tmp+=(n%10);

    n/=10;
}
printf("Sprotivniot broj e: %d",tmp);

    return 0;
}