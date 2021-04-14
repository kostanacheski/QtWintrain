/*
 
4.Да се напише програма која во главната функција внесува број на редици и колони на дводимензионална матрица.
 Во функцијата vnesiMatrica внесува елементи, а преку функцијата pechatiMatrica ги печати елементите во табеларна форма.
а) Да се напишат итеративни верзии на двете функции.
б) Да се напишат рекурзивни верзии на двете функции.

*/

#include <stdio.h>

void vnesiMatrica(int n,int m, int matrica[n][m]);
void pechatiMatrica(int n,int m, int matrica[n][m]);
void vnesiMatricaRekurzivno(int n,int m,int matrica[n][m],int curr_row,int curr_col);
void pechatiMatricaRekurzivno(int n,int m,int matrica[n][m],int curr_row,int curr_col);

int main(void){
int n,m;
printf("Vnesi broj na redici:\n");
scanf("%d",&n);
printf("Vnesi broj na koloni:\n");
scanf("%d",&m);

int matrix[n][m];

vnesiMatrica(n,m,matrix);
pechatiMatrica(n,m,matrix);
printf("\n\n");
vnesiMatricaRekurzivno(n,m,matrix,0,0);
pechatiMatricaRekurzivno(n,m,matrix,0,0);
    return 0;
}

void vnesiMatrica(int n,int m,int matrica[n][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&matrica[i][j]);
        }
    }
}
void pechatiMatrica(int n,int m,int matrica[n][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",matrica[i][j]);
        }
        printf("\n");
    }
}

void vnesiMatricaRekurzivno(int n,int m,int matrica[n][m],int curr_row,int curr_col){
    if(curr_col>=m) return vnesiMatricaRekurzivno(n,m,matrica,curr_row+1,0);
    if(curr_row>=n) return ;

    scanf("%d",&matrica[curr_row][curr_col]);

vnesiMatricaRekurzivno(n,m,matrica,curr_row,curr_col+1);
}
void pechatiMatricaRekurzivno(int n,int m,int matrica[n][m],int curr_row,int curr_col){
 if(curr_col>=m){
    printf("\n");
     return pechatiMatricaRekurzivno(n,m,matrica,curr_row+1,0);
 }
    if(curr_row>=n) return ;

printf("%d ",matrica[curr_row][curr_col]);

pechatiMatricaRekurzivno(n,m,matrica,curr_row,curr_col+1);
}