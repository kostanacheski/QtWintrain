/*Да се модифицира програмот за делење карти така да по мешањето подели 5 карти од рака за покер. Да се одреди дали раката содржи:
а) пар.
б) два пара
в) трилинг (пр. три десетки)
г) четири карти од ист број (пр. четири асови)
д) боја (сите пет карти да се од иста боја, на пр, детелина)
ѓ) кента (5 подредени карти од иста боја, пр. 3,4,5,6,7 срце)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void meshaj(int wDeck[][13]);
void deli(const int wDeck[][13],const char *wFace[],const char *wSuit[]);
void par(int arr[],const char *wFace[]);
void dvapara(int arr[],const char *wFace[]);
void triling(int arr[],const char *wFace[]);
void chetiri_isti(int arr[],const char *wFace[]);
void flush(int arr[],const char *wSuit[]);
void poker(int arr[],const char *wFace[],const char *wSuit[]);


int main(){
const char *boja[4]={"Srce","Karo","List","Detelina"};

const char *brojka[13]={"As","Dva","Tri","Chetiri","Pet","Shest","Sedum","Osum","Devet","Deset","Dzandar","Dama","Pop"};

int spil[4][13]={0};

srand(time(0));

meshaj(spil);
deli(spil,brojka,boja);
    return 0;
}
void meshaj(int wDeck[][13]){

    int row;
    int column;
    int card;

    for (card=1;card<=52;card++){
        do{
            row=rand()%4;
            column=rand() %13;
        }while (wDeck[row][column]!=0);
        
        wDeck[row][column]=card;
    }
}

/*void deli(const int wDeck[][13],const char *wFace[],const char *wSuit[]){

    int card;
    int row;
    int column;

    for(card=1;card<=52;card++){
        for(row=0;row<=3;row++){
            for(column=0;column<=12;column++){
                if(wDeck[row][column]==card){
                    printf("%8s %-8s%c",wFace[column],wSuit[row],card%2==0?'\n':'\t');
                }
            }
        }
    }
}
*/
void deli(const int wDeck[][13],const char *wFace[],const char *wSuit[]){
    int card;
    int row;
    int column;
    int arr[6];
    const char *boja[4]={"Srce","Karo","List","Detelina"};
    const char *brojka[13]={"As","Dva","Tri","Chetiri","Pet","Shest","Sedum","Osum","Devet","Deset","Dzandar","Dama","Pop"};
    for(card=1;card<=5;card++){
        for(row=0;row<=3;row++){
            for(column=0;column<=12;column++){
                if(wDeck[row][column]==card){
            
                    printf("%5s %-8s\n",wFace[column],wSuit[row]);
                    arr[card]=(column+1)+(row*13);
                }
            }
        }
    }
par(arr,brojka);
dvapara(arr,brojka);
triling(arr,brojka);
chetiri_isti(arr,brojka);
flush(arr,boja);
poker(arr,brojka,boja);
}
void par(int arr[],const char *wFace[]){
    int count[13]={0};
    int card;
    int hold;

    for(card=1;card<=5;++card){
        hold=arr[card]%13;
        count[hold]=count[hold]+1;
    }
    printf(" ");
    for(card=0;card<=12;++card){
        if(count[card]==2){
            printf("Imash par od %-8s\n",wFace[card-1]);
        }
    }
}
void dvapara(int arr[],const char *wFace[]){
    int count[13]={0};
    int card;
    int hold;
    int count1=0;

    for(card=1;card<=5;++card){
        hold=arr[card] %13;
        count[hold]=count[hold]+1;
    }
    printf(" ");

    for(card=0;card<=12;++card){
        if(count[card]==2){
            count1++;
        }
        if(count1==2){
            printf("Imash dva para\n");
            break;
        }
    }
}
void triling(int arr[],const char *wFace[]){
    int count[13]={0};
    int card;
    int hold;

    for(card=1;card<=5;++card){
        hold=arr[card] % 13;
        count[hold]=count[hold]+1;
    }
    printf(" ");

    for (card=0;card<=12;++card){
        if(count[card]==3){
            printf("Imash three of a kind of %-s\n",wFace[card]);
        }
    }

}

void chetiri_isti(int arr[],const char *wFace[]){
    int count[13]={0};
    int card;
    int hold;
    for(card=1;card<=5;++card){
        hold=arr[card]%13;
        count[hold]=count[hold]+1;
    }
    printf(" ");
    for(card=0;card<=12;++card){
        if(count[card]==4){
            printf("Imash four of a kind of %-8s\n",wFace[card]);
        }
    }
}
void flush(int arr[],const char *wSuit[]){
    int count[4]={0};
    int card;
    int hold;
    for(card=1;card<=5;++card){
        hold=arr[card]%4;
        count[hold]=count[hold]+1;
    }
    printf(" ");
    for(card=0;card<=3;++card){
        if(count[card]==5){
            printf("imash flush od %-8s\n",wSuit[card]);
        }
    }
}
void poker(int arr[],const char *wFace[],const char *wSuit[]){
int count1[13]={0};
int count2[4]={0};
int card;
int hold;
for(card=1;card<=5;++card){
    hold=arr[card]%13;
    count1[hold]=count1[hold]+1;
}
for(card=1;card<=5;++card){
    hold=arr[card]%4;
    count2[hold]=count2[hold]+1;
}
printf(" ");
for(card=0;card<=5;++card){

    if(count2[card]==5 && count1[card]==4){
        printf("Poker of %5s of %-8s\n", wFace[card],wSuit[card]);
    }
}
}