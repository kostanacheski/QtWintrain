/*
1. Создади класа Dropki која извршува операции со дропки. Напиши „драјвер“ за твојот програм да манипулира со оваа класа.

Користи целоборјни променливи за броител и именител кои мора да се приватни. Обезбеди потребен број на контруктори кои нема да дозволат дефинирање на грешни вредности (со 0 не се дели). По секоја од наредните операции, дропката треба да се зачува во редуцирана форма, т.е дропката 2/4 треба да се зачува како 1/2. Обезбеди ги следните операторски функции членки:
	а) Собирање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма.
	б) Одземање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
	в) Множење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
	г) Делење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
	д) Собирање на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
	ѓ) Одземање на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
	е) Множење на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.
	ж) Делење на објект од  класа Dropki со цел број. Резултатот да се даде во редуцирана форма.

Да се обезбедат и следните функции членки на класата:
	з) Печатење на објектот во форма a/b.
	ѕ) Печатење на објектот во форма на реален број.

*/
#include <iostream>
using namespace std;

class Dropki{
private:
int broitel;
int imenitel;
public:
Dropki(int =0,int=1);
~Dropki();
int getBroitel(){return broitel;}
int getImenitel(){return imenitel;}
void reduction();
void Enter();
void print();
Dropki add(Dropki);
Dropki substract(Dropki);
Dropki multiply(Dropki);
Dropki divide(Dropki);
double decimal();
Dropki operator+(Dropki);
Dropki operator-(Dropki);
Dropki operator*(Dropki);
Dropki operator/(Dropki);
};
Dropki::Dropki(int b,int i){
    if(i==0){
        b=0;
        i=1;
        exit(0);
    }
    else{
        broitel=b;
        imenitel=i;
    }
}
void Dropki::reduction(){
    for(int i=broitel;i>1;i--){
        if(broitel&i==0 && imenitel%i==0){
            broitel/=i;
            imenitel/=i;
        }
    }
}
void Dropki::Enter(){
    cout<<"Vnesi broitel: ";
    cin>>broitel;
    cout<<"Vnesi imenitel: ";
    cin>>imenitel;
    if(imenitel==0){
        cout<<"So nula ne se deli";
        exit(0);
    }
}
void Dropki::print(){
    cout<<broitel<<"/"<<imenitel<<endl;
}

Dropki Dropki::operator+ (Dropki d){
    Dropki temp;
    temp.broitel=broitel*d.imenitel+d.broitel*imenitel;
    temp.imenitel=imenitel*d.imenitel;
    return temp;
}
Dropki Dropki::operator-(Dropki d){
    Dropki temp;
    temp.broitel=broitel*d.imenitel-d.broitel*imenitel;
    temp.imenitel=imenitel*d.imenitel;
    return temp;
}
Dropki Dropki::operator*(Dropki d){
    Dropki temp;
    temp.broitel=broitel*d.broitel;
    temp.imenitel=imenitel*d.imenitel;
    return temp;
}
Dropki Dropki::operator/(Dropki d){
    Dropki temp;
    temp.broitel=broitel*d.imenitel;
    temp.imenitel=imenitel*d.broitel;
    return temp;

}
double Dropki::decimal(){
    return (double)broitel / (double)imenitel;
}
int main(){
    Dropki d1;
    d1.Enter();
    cout<<"Dropka: ";
    d1.reduction();
    d1.print();
    Dropki d2;
    d2.Enter();
    cout<<"Dropki: ";
    d2.reduction();
    d2.print();
    Dropki d3;
    cout<<"Sobiranje: "<<endl;
    d3=d1+d2;
    d3.print();
    cout<<"Vo realen broj: "<<d3.decimal()<<endl;
    Dropki d4;
    cout<<"Odzemanje: "<<endl;
    d4=d1-d2;
    d4.print();
    cout<<"Vo realen broj: "<<d4.decimal()<<endl;
    Dropki d5;
    cout<<"Mnozhenje: "<<endl;
    d5=d1*d2;
    d5.print();
    cout<<"Vo realen broj: "<<d5.decimal()<<endl;
    Dropki d6;
    cout<<"Delenje: "<<endl;
    d6=d1/d2;
    d6.print();
    cout<<"Vo realen broj: "<<d6.decimal()<<endl;
    




    return 0;
}