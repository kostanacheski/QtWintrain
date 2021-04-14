/*5.      Да се напише програма која симулира селекциско сортирање.
 Селекциското сортирање го бара најмалиот елемент во низата и го заменува со првиот елемент. 
 Сега, на прво место сигурно ни се наоѓа најмалиот елемент во низата.
  Потоа, во остатокот од низата, од вториот до n-тиот елемент, повторно го бараме новиот најмал елемент и му ја заменуваме вредноста 
  со вториот елемент од низата итн. Ова сортирање има слични процесирачки капацитети како сортирање со методот на меурче.
а) Да се напише итеративна верзија на функцијата selekcija која го врши селекциското сортирање.
б) Да се напише рекурзивна верзија на селекциското сортирање.
в) Да се одговори зошто процесирачките капацитети на ова сортирање се слични како оние со методот на меурче.
*/

#include <stdio.h>

int main (void){

int array[100];
int n;
printf("Vnesi broj na elementi vo nizata:\n");
scanf("%d",&n);

printf("Vnesi elementi vo nizata: \n");
for(int i=0;i<n;i++){
    scanf("%d",&array[i]);
}

printf("Sorted: \n");
selekcija(array,n);
for(int i=0;i<n;i++){
    printf("%d ",array[i]);
}

printf("\nSorted: \n");
selektirajRekurzivno(array,n,0);
for(int i=0;i<n;i++){
    printf("%d ",array[i]);
}
    return 0;
}

void selekcija(int array[],int n){
    int position;
    int tmp;
    for(int i=0;i<(n-1);i++){
        position=i;
        for(int j=i+1;j<n;j++){
            if(array[position]>array[j]){
                position=j;
            }
        }
        if(position != i){
            tmp=array[i];
            array[i]=array[position];
            array[position]=tmp;
        }
    }
}

void selektirajRekurzivno(int array[],int n,int index){
int min=index;
for(int j=index+1;j<n;j++){
    if(array[j]<array[min]){
        min=j;
    }
}
int tmp=array[min];
array[min]=array[index];
array[index]=tmp;

if(index+1<n){
    selektirajRekurzivno(array,n,index+1);
}

}

/* Za Selection Sort e potrebno O(n^2) vreme za sortiranje na n elementi vo niza.Najgolemata prednost na Selection Sort e vo toa shto
pravi maximum od n swaps.*/
