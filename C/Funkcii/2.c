/*2.      Напиши програма која на функцијата vreme и доделува три целобројни аргументи, час, минута и секунда и
 како резултат го враќа бројот на секунди до 12 часот.
 Имено, ако е 11 часот 59 минути и 58 секунди, тогаш има уште 2 секунди до 12 часот.
 */

#include <stdio.h>


int vreme(int hour,int minutes,int seconds){
    int h=12-hour-1;
    int m =60-minutes-1;
    int s=60-seconds;
    return 3600*h+60*m+s; 
}
int main(void){

int cas,minuti,sekundi;
printf("Vnesi vreme: \n");

scanf("%d%d%d",&cas,&minuti,&sekundi);

printf("Ima ushte %d sekundi do 12 chasot",vreme(cas,minuti,sekundi));

    return 0;
}