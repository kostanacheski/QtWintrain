/*2.	Напиши програма која вчитува датуми во облик gg/mm/dd, gg-mm-dd и gg+mm+dd и 
ги испечаува така да наместо бројот на месецот се испечати имато на месецот.
Пример:
Vnesi datum: 2005+06+01
Vneseniot datum e 1 juni 2005 godina.
*/

#include <stdio.h>

int main(void){

int den,mesec,godina;
printf( "Vnesi data vo oblik gg/mm/dd ili gg-mm-dd ili gg+mm+dd: " );
scanf("%4d%*c%02d%*c%02d%*c",&godina,&mesec,&den);
if (mesec==1){
    printf("%d januari %d godina\n",den,godina);
}
else if(mesec==2){
    printf("%d fevruari %d godina\n",den,godina);
}

else if(mesec==3){
    printf("%d mart %d godina\n",den,godina);
}

else if(mesec==4){
    printf("%d april %d godina\n",den,godina);
}

else if(mesec==5){
    printf("%d maj %d godina\n",den,godina);
}

else if(mesec==6){
    printf("%d juni %d godina\n",den,godina);
}

else if(mesec==7){
    printf("%d juli %d godina\n",den,godina);
}

else if(mesec==8){
    printf("%d avgust %d godina\n",den,godina);
}

else if(mesec==9){
    printf("%d septemvri %d godina\n",den,godina);
}

else if(mesec==10){
    printf("%d oktomvri %d godina\n",den,godina);
}

else if(mesec==11){
    printf("%d noemvri %d godina\n",den,godina);
}

else if(mesec==12){
    printf("%d dekemvri %d godina\n",den,godina);
}

    return 0;
}