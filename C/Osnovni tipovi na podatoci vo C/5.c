/*5. Напиши програма која внесува радиус на круг и испечатува негова плоштина и периметар. За вредност на пи да се земе 3.14.*/

#include <stdio.h>
#include <math.h>
int main(void)
{
    float radius;
    printf("Vnesi radius na krug");

    scanf("%f",&radius);

    printf("Ploshtinata na krugot e %.2f\n",(radius*radius*M_PI));
    printf("Perimetar na krugot e %.2f\n",(2*radius*M_PI));

    return 0;
}