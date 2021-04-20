/*  
1. Создади класа Dropki која извршува операции со дропки. Напиши „драјвер“ за твојот програм да манипулира со оваа класа.

Користи целоборјни променливи за броител и именител кои мора да се приватни.
 Обезбеди потребен број на контруктори кои нема да дозволат дефинирање на грешни вредности (со 0 не се дели!). 
 По секоја од наредните операции, дропката треба да се зачува во редуцирана форма, т.е дропката 2/4 треба да се зачува како 1/2. 
 Обезбеди ги следните јавни функции членки:
	а) Собирање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма.
	б) Одземање на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
	в) Множење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
	г) Делење на два објекти од класа Dropki. Резултатот да се даде во редуцирана форма
	д) Печатење на објектот во форма a/b.
	ѓ) Печатење на објектот во форма на реален број.



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

Dropki Dropki::add(Dropki d){
    int broitel_nov=broitel*d.imenitel+d.broitel*imenitel;
    int imenitel_nov=imenitel*d.imenitel;
    return Dropki(broitel_nov,imenitel_nov);
}
Dropki Dropki::substract(Dropki d){
    int broitel_nov=broitel*d.imenitel-d.broitel*imenitel;
    int imenitel_nov=imenitel*d.imenitel;
    return Dropki(broitel_nov,imenitel_nov);
}
Dropki Dropki::multiply(Dropki d){
    int broitel_nov=broitel*d.broitel;
    int imenitel_nov=imenitel*d.imenitel;
    return Dropki(broitel_nov,imenitel_nov);
}
Dropki Dropki::divide(Dropki d){
    int broitel_nov=broitel*d.imenitel;
    int imenitel_nov=imenitel*d.broitel;
    return Dropki(broitel_nov,imenitel_nov);

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
    Dropki d3=d1;
    cout<<"Sobiranje: "<<endl;
    d3.add(d2);
    d3.print();
    cout<<"Vo realen broj: "<<d3.decimal()<<endl;
    Dropki d4=d1;
    cout<<"Odzemanje: "<<endl;
    d4.substract(d2);
    d4.print();
    cout<<"Vo realen broj: "<<d4.decimal()<<endl;
    Dropki d5=d1;
    cout<<"Mnozhenje: "<<endl;
    d5.multiply(d2);
    d5.print();
    cout<<"Vo realen broj: "<<d5.decimal()<<endl;
    Dropki d6=d1;
    cout<<"Delenje: "<<endl;
    d6.add(d2);
    d6.print();
    cout<<"Vo realen broj: "<<d6.decimal()<<endl;
    




    return 0;
}