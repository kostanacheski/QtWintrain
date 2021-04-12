/*4.Напиши програма која за внесен цел број кој може да е најмногу  четири цифрен го испечатува неговиот еквивалент во римски броеви.
*/

#include <stdio.h>


int main(void){
int broj;
printf("Vnesi broj:");
scanf("%d",&broj);

printf("Negoviot ekvivalent vo rimski broevi: ");
if(broj>0 && broj<9999){
while (broj != 0)
{
    if(broj>=1000){
        printf("M");
        broj-=1000;
    }
    else if(broj>=900){
        printf("CM");
        broj-=900;
    }
    else if(broj>=500){
        printf("D");
        broj-=500;
    }
    else if(broj>=400){
        printf("CD");
        broj-=400;
    }
    else if(broj>=100){
        printf("C");
        broj-=100;
    }
    else if(broj>=90){
        printf("XC");
        broj-=90;
    }
    else if(broj>=50){
        printf("L");
        broj-=50;
    }
    else if(broj>=40){
        printf("XL");
        broj-=40;
    }
    else if(broj>=10){
        printf("X");
        broj-=10;
    }
    else if(broj>=9){
        printf("IX");
        broj-=9;
    }
    else if (broj>=5){
        printf("V");
        broj-=5;

    }
    else if(broj>=4){
        printf("IV");
        broj-=4;
    }
    else if(broj>=1){
        printf("I");
        broj-=1;
    }
}


}
else
printf("Greshen broj");


    return 0;
}