/* 1.1.	Напиши С++ програм кој користи inline функција circleArea која бара влез од корисникот за радиус на круг, 
ја пресметува и ја печати површината на кругот.
*/

#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

inline double circleArea(double radius){
    return M_PI*radius;
}

int main (){

double r;

cout<<"Vnesi radius na krug: "<<endl;
cin>>r;
cout<<"Ploshtina na krug so radius "<<r<<" e "<<circleArea(r)<<endl;
    return 0;
}