/*5.      Напиши програма која за внесени десет броја, го пресметува нивниот производ.*/

#include <stdio.h>

int main(void){

int counter=10;
int proizvod=1;
int broj;
while (counter>0)
{
    printf("Vnesi broj:\n");
    scanf("%d",&broj);
    proizvod=proizvod*broj;
    counter--;
}
printf("Proizvodot e %d",proizvod);
    return 0;
}