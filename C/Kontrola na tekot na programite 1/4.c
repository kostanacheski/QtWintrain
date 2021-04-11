/*4.      Напиши програма која ја пресметува сумата на броевите од 1 до десет. */

#include <stdio.h>

int main(void){


int broj=1;
int sum=0;

while (broj<=10)
{
    sum=sum+broj;
    broj++;
}

printf("Sumata na broevite od 1 do 10 e %d",sum);
    return 0;
}