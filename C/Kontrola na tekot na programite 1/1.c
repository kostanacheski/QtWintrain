/*1.      Модифицирај го програмот p04_01.c така да ги испуштиш break наредбите. Што се случува? Покажи пример.*/

/* Program: p04_01.c
   Demonstracija na case
   Dava broj na denovi vo mesec */
#include <stdio.h>
 
/* pocnuva izvrshuvanjeto */
int main()
{
   int mesec;              /* definiraj promenliva za mesec*/
 
   printf("Vnesi go mesecot so negoviot reden broj: ");
   scanf("%d", &mesec);
 
   /* vo zavisnost od vneseniot mesec najdi kolku dena ima */
   switch (mesec) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
                printf("Ima 31 den\n");
                
    case 4:
    case 6:
    case 9:
    case 11:
                printf("Ima 30 dena\n");
                
    case 2:
                printf("Vo prestapni godini ima 29, a vo obichni 28 dena\n");
                
    default:
                printf("Greshen broj na mesec!\n");
   } /* kraj na switch (mesec) */
 
   return 0; /* uspeshen kraj na programot */
                            
} /* kraj na fukncijata main */
/*break naredbata signalizira kraj na funkcijata,vo sluchajot kraj na switch.Koga nekoj case se izvrshuva doagja do break i izleguva od switch.
Dokolku break naredbata se izostavi programot nema da odi nadvor od switchot tuku ke prodolzhi so cases podolu od nego.
Ako na primer vneseme dva ,ke ispechati   printf("Vo prestapni godini ima 29, a vo obichni 28 dena\n"); a potoa i default 
Ili dokolku vneseme 5 ,ke go izvrshu case 5,pa potoa ke gi izveshi site drugi printf komandi podolu.*/