#include <stdio.h>

void pechati(int size,int a[size][5]);
void max(int size,int a[size][5]);
void min(int size,int a[size][5]);
void avg(int size,int a[size][5]);


int main(){
void (*f[4])(int size,int a[size][5])={pechati,max,min,avg};
int choice;
int a[50][50];
int n;
printf("Vnesi broj na studenti: \n");
scanf("%d",&n);
printf("Vnesi gi ocenite na sekoj student po 5 predmeti: \n");
for(int i=0;i<n;i++){
    for(int j=0;j<5;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("Vnesi izbor:\n"
"0-Pechatenje na nizata so oceni\n"
"1-Maksimalna ocena\n"
"2-Minimalna ocena\n"
"3-Ispechati ja prosechnata ocena za sekoj student\n"
"4-Kraj\n");
scanf("%d",&choice);
while(choice>=0 && choice<4)
{
    (*f[choice])(n,&a);
    printf("\nVnesi izbor: \n");
    scanf("%d",&choice);
}
printf("Kraj\n");

    return 0;
}

void pechati(int size,int a[size][5]){
    printf("Studentite i nivnite oceni: \n");
    for(int i=0;i<size;i++){
        printf("\nStudent %d\n",i+1);
        for(int j=0;j<5;j++){
            printf(" ocena: %d\n",a[i][j]);
        }
    }
}
void max(int size,int a[size][5]){
int max=0;
for(int i=0;i<size;i++){
    for(int j=0;j<5;j++){
        if(max<a[i][j]){
            max=a[i][j];
        }
    }
}
printf("Najvisokata ocena e: %d",max);
}
void min(int size,int a[size][5]){
    int min=1;
    for(int i=0;i<size;i++){
        for(int j=0;j<5;j++){
            if(min>a[i][j]){
                min=a[i][j];
            }
        }
    }
    printf("Minimalnata ocena e: %d ",min);
}
void avg(int size,int a[size][5]){
    int sum=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<5;j++){
            sum+=a[i][j];
        }
        printf("Avg za student %d e %.2f",i,(float)sum/5);
        sum=0;
    }
}