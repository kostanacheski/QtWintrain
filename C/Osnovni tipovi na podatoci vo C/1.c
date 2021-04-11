/*1. Напиши програм кој како влез зема два цели броја и ги споредува. Потоа го испечатува поголемиот број 
проследен со коментарот e pogolem od и го испечатува и помалиот број.
 Ако броевите се еднакви, програмот треба да испечати Broevite se ednakvi. */

 #include <stdio.h>

 int main(void)
 {
     int x,y;

     printf("Vnesi dva celi broja\n");

     scanf("%d%d",&x,&y);

     if (x>y){
         printf("%d e pogolem od %d",x,y);
     }
    else if (x<y){
        printf("%d e pogolem od %d",y,x);
    }
    else if (x==y){
        printf("Broevite se ednakvi");
    }

     return 0;
 }