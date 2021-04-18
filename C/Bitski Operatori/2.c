/*2. Напиши програм кој го превртува редоследот на битовите на целобројна unsigned вредност.
 Програмот треба да вчита вредност од корисникот и да ја повика функцијата prevtriBitovi 
 за да се испечатат битовите во обратен редослед. Вредностите на битовите да се испечатат и пред и после превртувањето.
 */

#include <stdio.h>
void prikazhiBitovi(unsigned vrednost);
unsigned int prevrtiBitovi(unsigned int num);
int main(){
unsigned broj;
printf("Enter a number: \n");
scanf("%u",&broj);
printf("The entered number represented in bits is: \n");
prikazhiBitovi(broj);
printf("The reverse number: \n");
prikazhiBitovi(prevrtiBitovi(broj));
    return 0;
}
void prikazhiBitovi(unsigned vrednost){

    unsigned c;
    unsigned pechatiMaska=1 << 31;
    printf("%10u=",vrednost);

    for(c=1;c<=32;c++){
        putchar(vrednost & pechatiMaska ? '1':'0');
        vrednost<<=1;

        if(c%8==0){
            putchar(' ');
        }
    }
    putchar('\n');
}

unsigned int prevrtiBitovi(unsigned int num)
{
    unsigned int  len = sizeof(num) * 8;
    unsigned int reverse = 0;
    int i;
    for (i = 0; i <len; i++)
    {
        if((num & (1 << i)))
           reverse |= 1 << ((len - 1) - i);  
   }
    return reverse;
}