/*3. Напиши програма која на функцијата obratno и доделува цел број. 
Оваа функција го враќа бројот напишан со обратни цифри, т.е. ако сме ја повикале функцијата со параметарот 1243, 
треба да врати 3421.
*/

#include <stdio.h>

int obratno(int number);
int main(void){

int broj;
printf("Vnesi cel broj: \n");
scanf("%d",&broj);

printf("%d\n",obratno(broj));
    return 0;
}
int obratno(int number){
int new;
int temp;
while (number!=0)
{
 temp=number%10;
 new=new*10+temp;
 number/=10;
}
return new;
}