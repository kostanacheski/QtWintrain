/*1.      Напиши програм кој вчитува вредности за температури за секој ден од месецот и наоѓа средна месечна температура.
 Да се земе предвид дека различни месеци имаат различен број на денови.
 */


#include <stdio.h>



int main(void){
int n;
float temperatura[50];
float sum,avg;
printf("Vnesi broj na denovi na mesecot:\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%f",&temperatura[i]);
    sum+=temperatura[i];
}

avg=sum/n;
printf("Srednata mesechna temperatura e: %.2f",avg);





    return 0;
}