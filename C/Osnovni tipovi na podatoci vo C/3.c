/* 3. Обидете се со спецификаторот за конверзија %d да испечатите букви на следниот начин:
printf(“%d”, ‘A’) /* karakteri se koristat vo edinecni navodnici */
//Што се случува кога се печатат следните карактери: b  c  0  1  2  $  *  +  / и празно место?

#include <stdio.h>

int main(void){


    printf("%d",'A'); //65
    //Ja pechati ASCII vrednosta na karakterot ,vo ovoj sluchaj karaktero A ,ke ima vrednost 65 .
    printf("%d",'c');//99
    //c ima vrednost 99,golemo C bi imalo vrednost 67 i taka natamu.
    return 0;
}