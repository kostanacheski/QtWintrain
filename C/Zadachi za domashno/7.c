/*7.	Да се најдат природните броеви во интервалот [n1,n2], кои се деливи со сво-јот спротивен број. */

#include <stdio.h>

int main(void){


int start;
int end;
printf("Vnesi interval: ");
scanf("%d %d",&start,&end);

int tmp;
for(int i=start;i<=end;i++){
    int j=i;
    tmp=0;
    while(j>0){
    tmp*=10;
    tmp+=(j%10);
    j/=10;
} 
if(i%tmp==0){
    printf("%d ",i);
}
}




    return 0;
}