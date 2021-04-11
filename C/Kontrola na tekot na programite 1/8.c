/* .      Една стоковна куќа продава 5 производи чии цени се дадени во долната табела
//Производ број	Цена
1	           50.5
2	           45.6
3	           32.8
4	           65.3
5	           20.0
Да се напише програм кој чита серија од парови броеви за:
а) број на производ
б) количина продадена во текот на денот
Програмот треба да ја користи switch наредбата за да ја одреди цената за секој  производ. 
Програмот треба да ја пресмета и испечати вкупната продадена вредност за секој од производите посебно, 
како и вкупната сума за сите производи продадени во текот на денот. */

#include <stdio.h>

int main(void){

int proizvod;
float cena;
float suma;
float suma1,suma2,suma3,suma4,suma5;
int kolichina=0;
while(proizvod!=-1){
printf("Vnesi broj na proizvod: ");
scanf("%d",&proizvod);
switch (proizvod)
{
case 1:
cena=50.5;
suma1=suma1+cena;
break;
case 2:
cena=45.6;
suma2=suma2+cena;
break;
case 3:
cena=32.8;
suma3=suma3+cena;
break;
case 4:
cena=65.3;
suma4=suma4+cena;
break;
case 5:
cena=20.0;
suma5=suma5+cena;
break;
default:
    proizvod=-1;
    break;
}
kolichina++;
}
printf("Kolichina na prodadeni proizvodi %d\n",kolichina-1);
printf("Vkupna prodadena suma za proizvod1 %.2f\n",suma1);
printf("Vkupna prodadena suma za proizvod2 %.2f\n",suma2);
printf("Vkupna prodadena suma za proizvod3 %.2f\n",suma3);
printf("Vkupna prodadena suma za proizvod4 %.2f\n",suma4);
printf("Vkupna prodadena suma za proizvod5 %.2f\n",suma5);
suma=suma1+suma2+suma3+suma4+suma5;
printf("Vkupna suma na prodadeni proizvodi %.2f\n",suma);
    return 0;
}
