/*8. Напиши 4 начини за да ја зголемиш вредноста на променливата x за 1. */


#include <stdio.h>


int main(){
    int x=1;
    x=x+1;
    printf("%d\n",x);
    x+=1;
    printf("%d\n",x);
    printf("%d\n",++x);
    x++;
    printf("%d\n",x);



    return 0;
}