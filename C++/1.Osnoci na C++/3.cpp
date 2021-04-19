/* 1.1.	Напиши програм кој кој користи функциски урнек min за да го определи помалиот од двата аргументи. 
Тестирај го прогамот со цели броеви, реални броеви и карактери. */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T> T minimum(T value1,T value2){
if(value1<value2) return value1;
else if(value1>value2) return value2;
else return value1;
}

int main(){
int broj1,broj2;
cout<<"Vnesi dva broja: ";
cin>>broj1>>broj2;
cout<<"Pomaliot od dvata broja e: "<<minimum(broj1,broj2);

double d1,d2;

cout<<"\nVnesi dva realni broja: ";
cin>>d1>>d2;
cout<<"Pomaliot od dvata realni broja e: "<<minimum(d1,d2);

char karakter1,karakter2;

cout<<"\nVnesi dva karakteri: ";
cin>>karakter1>>karakter2;
cout<<"Pomaliot od dvata karakteri e: "<<minimum(karakter1,karakter2)<<endl;

    return 0;
}