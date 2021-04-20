/*1. Да се формира класа Квадар (скриени елементи: должина, ширина и висина; јавни функции: плоштина, волумен).
 Од неа да се имплементира поле од објекти. Да се најде оној кој има најмала плоштина, а не е коцка. Да се креира мени:
a)	Креирај нов објект
b)	Постави ги димензиите
c)	Печати ги димензиите на сите објекти
d)	Печати ги димензиите за поедин објект
e)	Печати ги оние кои го задоволуваат условот
*/

#include <iostream>
using namespace std;

class Kvadar{
    private:
    int dolzhina;
    int shirina;
    int visina;
    public:
    int getDolzhina(){return dolzhina;}
    int getShirina(){return shirina;}
    int getVisina(){return visina;}
    void set();
    int Ploshtina();
    int Volumen();
    void Kopiraj(Kvadar &);
};
void Kvadar::set(){
    cout<<"dolzhina: ";
    cin>>dolzhina;
    cout<<"shirina: ";cin>>shirina;
    cout<<"visina: ";cin>>visina;
}
int Kvadar::Ploshtina(){
return (2*dolzhina*shirina)+(2*shirina*visina)+(2*dolzhina*visina);
}
int Kvadar:: Volumen(){
    return dolzhina*visina*shirina;
}
void Kvadar::Kopiraj(Kvadar &Izvoriste){
    dolzhina=Izvoriste.dolzhina;
    shirina=Izvoriste.shirina;
    visina=Izvoriste.visina;
}
int main(){
Kvadar k[3];
cout<<"Kreiraj nov objekt"<<endl;
Kvadar *kv;
for(int i=0;i<3;i++){
    k[i].set();
    cout<<"Stranite na kvadarot se: "<<endl;
    cout<<k[i].getDolzhina()<<" "<<k[i].getShirina()<<" "<<k[i].getVisina();

}
kv=new Kvadar;
kv->set();
cout<<"Za noviot objekt";
cout<<kv->getDolzhina()<<" "<<kv->getShirina()<<" "<<kv->getVisina();
cout<<"Ploshtina :"<<kv->Ploshtina();
cout<<"Volument :"<<kv->Volumen();
delete kv;
cout<<"Ploshtinite koi go zadovoluvaat uslovot : "<<endl;
for(int i=0;i<3;i++){
    if(k[i].getDolzhina()==k[i].getShirina() && k[i].getShirina()==k[i].getVisina()){
       continue;
    }
    cout<<"Plosthina: "<<k[i].Ploshtina();
    cout<<"Volumen: "<<k[i].Volumen();
}

cout<<"Najmalata ploshtina e: ";
Kvadar min;
 min.Kopiraj(k[0]);
for(int i=0;i<3;i++){
    if(k[i].getDolzhina()==k[i].getShirina() && k[i].getShirina()==k[i].getVisina())
    if(min.Ploshtina()>k[i].Ploshtina()){
        min.Kopiraj(k[i]);
    }
}
cout<<"Ploshtina : "<<min.Ploshtina()<<"So strani : "<<min.getDolzhina()<<" "<<min.getShirina()<<" "<<min.getVisina();
    return 0;
}