/* 3. Напиши програм кој ги печати броевите од 1 до 4 на иста линија, при тоа можеш да користиш:
	а) една prinf наредба, без спецификатори за конверзија
	б) една prinf наредба, со 4 спецификатори за конверзија
	в) 4 printf наредби.
*/

#include <stdio.h>

int main(){

printf("1 2 3 4 ");
printf("\n");
for (int i=1;i<=4;i++){
    printf("%d ",i);
}
printf("\n");
int x=1,y=2,z=3,w=4;
printf("%d %d %d %d",x,y,z,w);
printf("\n");
printf("%d ",x);
printf("%d ",y);
printf("%d ",z);
printf("%d",w);


}