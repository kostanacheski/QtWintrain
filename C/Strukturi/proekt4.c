#include <stdio.h>

struct vraboten{
int ID;
char ime[30];
char prezime[30];
int vozrast;
char pol;
char brachna_sostojba[10];
int kredibilnost;
char adresa[50];
double tekovna_plata;
double poraneshna_plata;
};
typedef struct vraboten emp;
void sort(emp e[],int n);
void koregiraj_kredibilnost(emp e[],int n);
void koregiraj_vraboten(emp * const v);
int main(){
int n;
printf("Vnesi broj na vraboteni:\n");
scanf("%d",&n);

struct vraboten emp[n];
for(int i=0;i<n;i++){
printf("Vnesi podatoci: \n");
printf("ID?:"); scanf("%d",&emp[i].ID);
printf("Ime?: "); gets(emp[i].ime);
printf("Prezime?; "); gets(emp[i].prezime);
printf("Vozrast?: "); scanf("%d",&emp[i].vozrast);
printf("Pol?: "); scanf("%c",&emp[i].pol);
printf("Brachna Sostojba? :"); gets(emp[i].brachna_sostojba);
printf("Kredibilnost?: "); scanf("%d",&emp[i].kredibilnost);
printf("Adresa?: "); gets(emp[i].adresa);
printf("Tekovna Plata?: "); scanf("%f",&emp[i].tekovna_plata);
printf("Poraneshna Plata?: "); scanf("%f",&emp[i].poraneshna_plata);
}
sort(emp,n);

for(int i=0;i<n;i++){
    printf("ID: %d\n",emp[i].ID);
    printf("Ime: %s\t Prezime: %s\t Vozrast: %d \t Pol: %c \t Brachna sostojba: %s\t Kedibilnost:%d\t "
  "Adresa:%s\t Tekovna Plata:%.2f\t Poraneshna Plata:%.2f",emp[i].ime,emp[i].prezime,emp[i].vozrast,emp[i].pol,
  emp[i].brachna_sostojba,emp[i].kredibilnost,emp[i].adresa,emp[i].tekovna_plata,emp[i].poraneshna_plata);
}
koregiraj_kredibilnost(emp,n);
for(int i=0;i<n;i++){
    printf("ID: %d\n",emp[i].ID);
    printf("Ime: %s\t Prezime: %s\t Vozrast: %d \t Pol: %c \t Brachna sostojba: %s\t Kedibilnost:%d\t "
  "Adresa:%s\t Tekovna Plata:%.2f\t Poraneshna Plata:%.2f",emp[i].ime,emp[i].prezime,emp[i].vozrast,emp[i].pol,
  emp[i].brachna_sostojba,emp[i].kredibilnost,emp[i].adresa,emp[i].tekovna_plata,emp[i].poraneshna_plata);
}
    return 0;
}

void sort(emp e[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(e[j].kredibilnost<e[j+1].kredibilnost){
                emp temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(e[j].tekovna_plata<e[j+1].tekovna_plata){
                emp temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(e[j].poraneshna_plata<e[j+1].poraneshna_plata){
                emp temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
}
void koregiraj_kredibilnost(emp e[],int n){
    for(int i=0;i<n;i++){
        if(e[i].tekovna_plata>e[i].poraneshna_plata){
            e[i].kredibilnost+=3;
            e[i].tekovna_plata=e[i].poraneshna_plata;
        }
        else if(e[i].tekovna_plata<e[i].poraneshna_plata){
            e[i].kredibilnost-=3;
            e[i].tekovna_plata=e[i].poraneshna_plata;
        }
    }
}