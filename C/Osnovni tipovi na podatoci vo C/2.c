/* 2. Напиши програм кој вчитува два цели броја и одредува дали се парни или непарни. */

#include <stdio.h>

int main(void){


int broj1,broj2;

printf("Vnesi dva celi broja\n");
scanf("%d%d",&broj1,&broj2);

if(broj1%2==0){
    printf("Brojot %d e paren\n",broj1);
}
else if (broj1 %2==1){
    printf("Brojot %d e neparen\n",broj1);
}

if(broj2%2==0){
    printf("Brojot %d e paren\n",broj2);
}
else if (broj2 %2==1){
    printf("Brojot %d e neparen\n",broj2);
}
    return 0;
}