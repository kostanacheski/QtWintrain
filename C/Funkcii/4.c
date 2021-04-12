/* 4.Напиши програма во која дефинираш функција nzd за пресметување на најголемиот заеднички делител на два броја.
*/

#include <stdio.h>

int nzd(int x,int y){
    int nzd;
    for(int i=1;i<=x && i<=y;++i){
        if(x%i==0 && y%i==0){
        nzd=i;
        }
    }
    return nzd;
}

int main(void){

int x,y;
printf("Vnesi dva broja: \n");
scanf("%d%d",&x,&y);

printf("Najgolemiot zaednichki delitel na broevite %d i %d e %d",x,y,nzd(x,y));

    return 0;
}