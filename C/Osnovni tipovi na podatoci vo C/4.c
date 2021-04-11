/* 4. Во примерот p03_01.c, 
во наредбата printf наместо спецификаторот за конверзија  %f, поставете го спецификаторот %d. Што се случува и зошто?*/


#include <stdio.h>

float result; /* Rezultat od delenje */
int main()
{
result = 7.0 / 22.0;
printf("Rezultatot e %d\n", result);
return (0);
}
/*
Printf ja tretira memorijata shto ja dodavame kako nie posochuvame.Ne se sluchuva konverzija.
Ja tretira memorijata shto e reprezentirana kako float vo int.Bidejki dvete se zachuvuvani vo memorija razlichno se dobiva random number.
Dokolku bi sakale da napravime konverzija vo printf ,vo toj sluchaj bi napishale:
printf("Rezultatot e %d\n",(int)result);
 */