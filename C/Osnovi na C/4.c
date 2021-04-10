/*4. Напиши програм кој вчитува три цели броја и пресметува нивна целобројна средна вредност, сума и производ.*/


#include <stdio.h>

int main(void)
{
int broj1,broj2,broj3;

printf("Vnesi Prv cel broj\n");
scanf("%d",&broj1);
printf("Vnesi vtor cel broj\n");
scanf("%d",&broj2);
printf("Vnesi tret cel broj\n");

scanf("%d",&broj3);

printf("Nivna celobrojna sredna vrednost e %d\n",(broj1+broj2+broj3)/3);
printf("Nivnata suma e %d\n",broj1+broj2+broj3);
printf("Nivniot proizvod e %d \n",broj1*broj2*broj3);



    return 0;
}