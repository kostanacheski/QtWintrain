/*6.      Напиши рекурзивна верзија на функцијата за пресметување најголем заеднички делител. */


#include <stdio.h>
int nzd(int x,int y){
    if(y!=0)
    return nzd(y,x%y);
    else
    return x;
}

int main(void){
int x,y;
printf("Vnesi dva celi broja:\n");
scanf("%d%d",&x,&y);


printf("Najgolem zaednichki delitel na broevite %d i %d e %d",x,y,nzd(x,y));


    return 0;
}