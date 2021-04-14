/*4.	Да се најдат совршените броеви помали од природниот број n. */


#include <stdio.h>


int main(void){
int n;
printf("Vnesi broj:\n");
scanf("%d",&n);

printf("Site sovrsheni broevi pomegju 1 i %d\n",n);
int sum;
for(int i=1;i<n;i++){
sum=0;

for(int j=1;j<i;j++){
    if(i%j==0){
        sum+=j;
    }
}
if(sum==i){
    printf("%d ",i);
}

}

    return 0;
}