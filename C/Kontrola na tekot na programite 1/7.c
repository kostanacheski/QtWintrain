/*7.      Напиши програма која пресметува сума на внесени броеви од тастатура се додека не се внесе карактер ‘n’.
Пример:
          Vnesi broj: 6
          Ushte? (d/n): d
          Vnesi broj: 7
          Ushte? (d/n): d
          Vnesi broj: 3
          Ushte? (d/n): n
                  Sumata e 16
*/

#include <stdio.h>

int main(void){

int broj;
int sum=0;

char check='d';
while(check){
if (check=='d'){
printf("Vnesi broj: \n");
scanf("%d",&broj);
sum=sum+broj;
}
printf("Ushte? (d/n):\n");
scanf("%c",&check);
if(check == 'n')
break;
}
printf("Sumata e %d",sum);

    return 0;
}