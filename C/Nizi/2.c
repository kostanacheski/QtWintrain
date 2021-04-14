/*2.      Прости броеви се броеви кои се деливи само со себе си и со бројот 1.
 Напиши програм кој внесува n елементи во низа. Да се овозможи функционалност да имаме променлив број на елементи во низата.
  Во почетокот сите елементи да се иницијализираат на 1.
   Потоа да се напише функција prosti која секој елемент од низата чиј индекс е прост број, го поставува на 0. 
   На крај од така добиената низа да се најде начин да се испечатат простите броеви до n.  */


#include <stdio.h>
#include <math.h>
int main(void){

int n;
printf("Vnesi golemina na nizata:\n");
scanf("%d",&n);

int array[n];

for(int i=0;i<n;i++){
    array[i]=1;
}

prosti(array,n);

for(int i=0;i<n;i++){
    if(array[i]==0){
        printf("%d ",i);
    }
}
printf("\n");
    return 0;
}

void prosti(int array[],int n){

int prime=0;
for(int i=2;i<n;i++){
    array[i]=0;
for(int j=2;j<=(int) sqrt(i);j++){
if(i%j==0){
    array[i]=1;
    break;
}

}
}

}