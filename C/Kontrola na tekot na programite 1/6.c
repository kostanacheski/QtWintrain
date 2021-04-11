/*6.      Напиши програма која пресметува сума на внесени броеви од тастатура се додека не се внесе -1.*/

#include <stdio.h>

int main(void){


int suma=0;
int broj;

printf("Vnesi broj:\n");
scanf("%d",&broj);

while (broj != -1)
{
    suma=suma+broj;
    printf("Vnesi broj,-1 za kraj:");
    scanf("%d",&broj);
}


printf("Sumata e %d",suma);


    return 0;
}