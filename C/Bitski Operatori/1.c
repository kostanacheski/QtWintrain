/*1. Само со користење на операторот за шифтирање да се напише функција mnoziSoStepenOdDva која зема два целобројни аргументи: 
broj и stepen и ја пресметува следната вредност:
broj * 2^stepen;
*/

void prikazhiBitovi(unsigned vrednost);
void mnoziSoStepenOdDva(unsigned broj,unsigned stepen);

int main(){
unsigned number;
unsigned stepen;
printf("Vnesi broj : \n");
scanf("%u",&number);
printf("Vnesi stepen: \n");
scanf("%u",&stepen);
printf("Vneseniot broj prikazhan vo bitovi\n");
prikazhiBitovi(number);
printf("Vneseniot stepen prikazhan vo bitovi:\n");
prikazhiBitovi(stepen);
printf("Rzultatot od %u na stepen %u e: \n",number,stepen);
mnoziSoStepenOdDva(number,stepen);
    return 0;
}


void prikazhiBitovi(unsigned vrednost){

    unsigned c;
    unsigned pechatiMaska=1 << 31;
    printf("%10u=",vrednost);

    for(c=1;c<=32;c++){
        putchar(vrednost & pechatiMaska ? '1':'0');
        vrednost<<=1;

        if(c%8==0){
            putchar(' ');
        }
    }
    putchar('\n');
}

void mnoziSoStepenOdDva(unsigned broj,unsigned stepen){
    prikazhiBitovi(broj<<stepen);
}