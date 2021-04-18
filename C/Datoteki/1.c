/*1. Вие сте сопственик на продавница за компјутерска опрема. 
Треба да си направите апликација која ќе се грижи за хардверот што го имате на располагање,
 количината на секој од деловите во продавницата и цените на деловите. 
 Напишете програма која иницијализира датотека “hardware.dat”, 
 ви овозможува да внесете податоци за секој дел, да ги излистате податоците за специфичен дел,
  да дадете комплетен листинг на состојбата во вашата продавница,
   да избришете податоци за даден дел ако тој веќе го немате на лагер, да ажурирате податоци за даден дел и да правите продажба.
    Под продажба се подразбира намалување на бројот на потребни делови од датотеката, доколку има толку делови, колку што бара купецот.
     Да претпоставиме дека имаме оптички читач на касата и дека секој дел се вчитува со негов код. 
*/
#include <stdio.h>

struct hardwareStore
{
    int kod;
    char ime[20];
    int kolichina;
    double cena;
};


int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main(){
FILE *cfPtr;
int choice;
if((cfPtr=fopen("hardware.dat","rb+")) == NULL){
    printf("Datotekata ne mozhe da se otvori.\n" );
}
else{
    while ((choice=enterChoice())!=5)
    {
        switch(choice){
            case 1:
            textFile(cfPtr);
            break;
            case 2:
            updateRecord(cfPtr);
            break;
            case 3:
            newRecord(cfPtr);
            break;
            case 4:
            deleteRecord(cfPtr);
            break;
            default:
            printf("Greshen Izbor\n");
            break;
        }
    }
    fclose(cfPtr);
}
return 0;
}

void textFile(FILE *readPtr){
    FILE *writePtr;
    struct hardwareStore hardware={0,"",0,0.0};

    if((writePtr=fopen("hardware.txt","w"))==NULL){
        printf("Datotekata ne mozhe da se otvori.\n");
    }
    else{
        rewind(readPtr);
        fprintf(writePtr, "%-6s%-16s%-11s%-10s\n","Kod","Ime na Del","Kolichina","Cena");
        while (!feof(readPtr))
        {
            fread(&hardware,sizeof(struct hardwareStore),1,readPtr);
            if(hardware.kod !=0){
                fprintf(writePtr, "%-6d%-16s%-11d%10lf\n",hardware.kod,hardware.ime,hardware.kolichina,hardware.cena);
            }
        }
        fclose(writePtr);
    }
}


void updateRecord(FILE *fPtr){
    int kod;
    struct hardwareStore hardware={0,"",0,0.0};

    printf("Vnesi kod za deden del (1-100): ");
    scanf("%d",&kod);

    fseek(fPtr,(kod-1)*sizeof(struct hardwareStore),SEEK_SET);
    fread(&hardware,sizeof(struct hardwareStore),1,fPtr);//  fread(&kod,sizeof(struct hardwareStore),1,fPtr);
    if(hardware.kod==0){
        printf("Kodot #%d nema informacii.\n");
    }
    else{
        printf("Vnesi novo ime na del,kolichina i cena\n?");
        scanf("%s%d%lf",hardware.ime,&hardware.kolichina,&hardware.cena);

        fseek(fPtr,(kod-1)*sizeof(struct hardwareStore),SEEK_SET);
        fwrite(&hardware,sizeof(struct hardwareStore),1,fPtr);
    }
}

void deleteRecord(FILE *fPtr){
    struct hardwareStore hardware;
    struct hardwareStore blankRecord={0,"",0,0.0};
    int kodNum;

    printf("Vnesi broj na kod za brishenje (1-100): ");
    scanf("%d",&kodNum);

    fseek(fPtr,(kodNum-1)*sizeof(struct hardwareStore),SEEK_SET);
    fread(&hardware,sizeof(struct hardwareStore),1,fPtr);

    if(hardware.kod ==0){
        printf("Kodot %d ne postoi.\n",kodNum);
    }
    else{
         fseek( fPtr, ( kodNum - 1 ) * sizeof( struct hardwareStore ), SEEK_SET );
        fwrite( &blankRecord, sizeof( struct hardwareStore ), 1, fPtr );

    }
}
void newRecord(FILE *fPtr){
    struct hardwareStore hardware={0,"",0,0.0};
    int kodnew;
    printf("Vnesi kod na del (1-100): ");
    scanf("%d",&kodnew);

    fseek(fPtr,(kodnew-1)*sizeof(struct hardwareStore),SEEK_SET);
    fread(&hardware,sizeof(struct hardwareStore),1,fPtr);

    if(hardware.kod !=0){
        printf("Kodot #%d e vekje sozdaden.\n",hardware.kod);
    }
    else{
        printf("Vnesi ime na del,kolichina,cena\n?");
        scanf("%s%d%lf",hardware.ime,&hardware.kolichina,&hardware.cena);
        hardware.kod=kodnew;
        fseek(fPtr,(hardware.kod-1)*sizeof(struct hardwareStore),SEEK_SET);
        fwrite(&hardware,sizeof(struct hardwareStore),1,fPtr);
    }
}

int enterChoice(void){
      int menuChoice;
    printf( "\nEnter your choice\n"
            "1 -Izlistaj podatoci za delovi\n"
            "2 - Azhuriraj postoechki del\n"
            "3 - Dodadi nov del\n"
            "4 - Izbrishi del\n"
            "5 - Kraj\n? " );
    scanf( "%d", &menuChoice );
    return menuChoice;

}