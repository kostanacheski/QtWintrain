/*3.      Палиндроми се низи од букви што се читаат исто и оддесно на лево и одлево на десно. На пример зборот “radar” е палиндром. 
Да се напише програм во кој внесуваме низа од карактери. 
Треба да имаме функција palindrom која враќа вредност 1 ако стрингот е палиндром или 0 инаку. */

#include <stdio.h>
#include <string.h>
int main(void){

char niza[50];
printf("Vnesi zbor:\n");
scanf("%s",niza);

int check=palindrom(niza);

if(check==1){
    printf("Zborot %s e palindrom",niza);
}
else{
    printf("Zborot %s ne e palindrom",niza);
}
    return 0;
}

int palindrom(char array[]){
int n=strlen(array);
int counter=0;
for(int i=0;i<n/2;i++){
    if(array[i]==array[n-i-1]){
        counter++;
    }
}
if (counter==n/2){
    return 1;
}
else{
    return 0;
}

}