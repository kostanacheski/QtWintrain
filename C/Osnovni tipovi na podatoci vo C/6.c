/*
6. Напишете програма која од стандардниот влез зема 5 букви и ги испечатува по следниот редослед:
 прво петтата, па третата, па втората, па првата, па четвртата буква. Пример:
vnesi pet bukvi
prva bukva: e
vtora bukva: i
treta bukva: b
chetvrta  bukva: n
petta bukva: p
Se dobi: pbien
*/

#include <stdio.h>

int main(void)
{
printf("Vnesi 5 bukvi:\n");
char b1,b2,b3,b4,b5;
scanf("%c%c%c%c%c",&b1,&b2,&b3,&b4,&b5);


printf("%c%c%c%c%c",b5,b3,b2,b1,b4);




    return 0;
}