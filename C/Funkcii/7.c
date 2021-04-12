/*7.      Напиши рекурзивна верзија на програма која за внесено n повикува функција dzvezdi со параметар n која во зависност од n 
испечатува ѕвезди на следниот начин:
    Vnesi broj na dzvezdi (n): 5
    Se dobiva:
    * * * * *
    * * * *
    * * *
    * *
    *
*/


#include <stdio.h>

void dzvezdi(int n){
if(n==0)
return;
for(int i=1;i<=n;i++)
printf("* ");
printf("\n");
return dzvezdi(n-1);
}

int main(void){

    int n;
    scanf("%d",&n);
    dzvezdi(n);
    return 0;
}