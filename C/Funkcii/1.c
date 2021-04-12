/*1.      Напиши програма која внесува 10 цели броеви и и ги доделува на функцијата paren
 која враќа 1 ако бројот е парен и 0 ако бројот не е парен. */


 #include <stdio.h>


 int paren(int x){
     if(x%2==0){return 1;}
     else{return 0;}
 }
 int main(void){

     int i=0;
    int x;
     while (i<10)
     {
         printf("\nVnesi broj:\n");
        scanf("%d",&x);

        printf("Brojot %d e %s\n",x,paren(x)==1 ? "paren" : "neparen");
        i++;
     }
     




     return 0;
 }