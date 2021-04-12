/*5.      Напиши итеративна верзија на функцијата за фибоначиеви броеви. */

#include <stdio.h>



int main(void){
int b1=0,b2=1,b3,limit;

printf("Vnesi limit: \n");

scanf("%d",&limit);
printf("\n%d %d",b1,b2);

for(int i=2;i<limit;++i){
    b3=b1+b2;
    printf(" %d",b3);
    b1=b2;
    b2=b3;
}



    return 0;
}