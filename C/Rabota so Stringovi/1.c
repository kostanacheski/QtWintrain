/*
1. Напиши програм кој внесува телефонски број како стринг во облик (333) 333-3333.
 Програмот треба со користење на наредбата strtok да го извлече кодот на државата како едно делче,
  а потоа да го спои целиот телефонски број во друг стринг без -.
   Програмот треба да го конвертира бројот на државата во int, а седмоцифрениот телефонски број во long. 
   Двата бројат треба да бидат испечатени.
*/
#include <stdio.h>
#include <string.h>

int main(){
char string[20];
char *tokenPtr;
char country[4]={0};
char number[9]={0};
printf("Vnesi telefonski broj vo format (333) 333 -3333 :\n");
gets(string);

tokenPtr = strtok(string,"()-");

if(tokenPtr !=NULL){
    strncat(country,tokenPtr,sizeof country-1);
}
tokenPtr=strtok(NULL,"()-");
if(tokenPtr !=NULL){
    strncat(number,tokenPtr,sizeof number-1);
}
tokenPtr=strtok(NULL,"()-");
if(tokenPtr != NULL){
    strncat(number,tokenPtr,sizeof number-1);
}
puts(country);
puts(number);
int c;
c=atoi(country);
printf("Brojot na drzhavata e %d \n",c);

char *remainderPtr;
long n;
n=strtol(number,&remainderPtr,0);
printf("Brojot e %ld",n);
    return 0;
}