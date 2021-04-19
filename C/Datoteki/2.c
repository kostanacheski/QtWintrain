/*
2. Да се напише програма која служи како генератор на телефонски броеви. Знаеме дека полесно се паметат поими од броеви, 
па така некои од компаниите имаат телефонски броеви кои ја означуваат дејноста или името на компанијата.
Нека ни се подредени буквите на следниот начин:

а) За даден седумбуквен стринг да се изгенерира бројот на телефон. Пример: “TELEKOM” = 8353566
б) За даден седмоцифрен број да се изгенерираат што поголем број на стрингови. Да се внимава дека 0 има само две букви.

*/
#include <stdio.h>

void generator( int broj[]);


int main(void){
int tel_broj[7]={0};

printf("Vnesi telefonski broj cifra po cifra");
puts("cifri od 2 do 9");

for(int i=0;i<=6;i++){
    printf("? ");
    scanf("%d",&tel_broj[i]);

while (tel_broj[i]<2 || tel_broj[i]>9)
{
    printf("\n Nevaliden broj");
    scanf("%d",&tel_broj[i]);
}
}

generator(tel_broj);



    return 0;
}
void generator( int broj[]){
    FILE *fPtr;
    char *bukvi[10]={"", "ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX","YZ"};

    if((fPtr=fopen("telnum.dat","w"))==NULL){
        printf("Datotekata ne mozhe da se otvori.\n");
    }
    else{
        for(int i1=0;i1<=2;++i1){
            for(int i2=0;i2<=2;++i2){
                for(int i3=0;i3<=2;++i3){
                    for(int i4=0;i4<=2;++i4){
                        for(int i5=0;i5<=2;++i5){
                            for(int i6=0;i6<=2;++i6){
                                for(int i7=0;i7<=2;++i7){
                                    fprintf(fPtr,"%c%c%c%c%c%c%c\n",bukvi[broj[0]][i1],bukvi[broj[1]][i2],bukvi[broj[2]][i3],
                                    bukvi[broj[3]][i4],bukvi[broj[4]][i5],bukvi[broj[5]][i6],bukvi[broj[6]][i7]);
                                }
                            }
                        }
                    }
                }
            }
        }
fputs("\nTelefonskiot broj e ",fPtr);
for(int i=0;i<=6;+i)
fprintf(fPtr,"%d",broj[i]);
    }
fclose(fPtr);
}
