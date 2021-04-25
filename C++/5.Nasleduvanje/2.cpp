/* 
Во една продавница се води евиденција за артиклите кои се продаваат во неа: пантолони и кошули. Користејќи ги концептите на ООП да се моделираат соодветни класи според спецификациите дадени на сликата. Пратката на пантолони доаѓа секој месец, а нарачки на кошули се прават по потреба. Во main() функцијата да се конструира низа од долунаведените класи (пантолони, кошули) и да се имплементира кориснички посредник преку мени со следните опции:
1.      Додавање на артикл во листата
2.      Прикажување на артикли од дадена група
3.      Прикажување на целата листа (со вкупна цена)
4.      Прикажување на сите артикли кои треба да се набават во рок од 1 недела и пари кои треба да се потрошат за да се набават потребните артикли
5.      Излез од менито

*/
#include <iostream>
#include <cassert>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
class Date{
    private:
    int day;
    int month;
    int year;
    public:
    Date();
    Date(int,int,int);
    int getMonth()const;
    int getDay()const;
    int getYear()const;
    Date operator++();
    void display_standard()const;
    void display_byName() const;
    friend istream& operator>>(istream&,Date&);
};
Date::Date(int m,int d,int y){
    month=m;
    day=d;
    year=y;
}
int Date::getMonth()const{
    return month;
}
int Date::getDay()const{
    return day;
}
int Date::getYear()const{
    return year;
}
Date Date::operator++(){
    day++;
    assert(day>=1 && day<=31);
    month++;
    assert(month>=1 && month<=12);

    year++;
    if(month==2 && day==28 || day==29){
        if(year %4 || year %400){
            cout<<"Prestapna godina"<<endl;
            month++;
            day++;
            year++;
            assert(day>=1 && day<=31);
            assert(month>=1 && month <=12);
        }
    }
    return Date(month,day,year);
}

void Date::display_standard()const{
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
void Date::display_byName()const{
    switch (month)
    {
    case 1:
    cout<<"January"<<endl;
        break;
    case 2:
    cout<<"February"<<endl;
        break;
    case 3:
    cout<<"March"<<endl;
        break;
    case 4:
    cout<<"April"<<endl;
        break;
    case 5:
    cout<<"May"<<endl;
        break;
        case 6:
    cout<<"June"<<endl;
        break;
    case 7:
    cout<<"July"<<endl;
        break;
    case 8:
    cout<<"August"<<endl;
        break;
    case 9:
    cout<<"September"<<endl;
        break;
    case 10:
    cout<<"October"<<endl;
        break;
    case 11:
    cout<<"November"<<endl;
        break;
    case 12:
    cout<<"December"<<endl;
        break;
    default:
        break;
    }
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
istream& operator>>(istream& input,Date& d){
return input>>d.month>>d.month>>d.year;
}
class Artikl{
    private:
    char *ime_na_artikl;
    int golemina;
    double cena;
    Date donesen_vo_prodavnica;
    public:
    Artikl(char *,int ,double, Date&);
    ~Artikl();
    char* getIme()const;
    int getGolemina()const;
    double getCena()const;
    Date getDonesen()const;
    void prikazi_podatoci()const;
    bool presmetaj_nabavka(Date&);
    char getSign();

};
Artikl::Artikl(char *ime,int g,double c, Date& d){
    strcpy(ime_na_artikl,ime);
    golemina=g;
    cena=cena;
    donesen_vo_prodavnica=d;
}
char* Artikl::getIme()const{
    return ime_na_artikl;
}
int Artikl::getGolemina()const{
    return golemina;
}
double Artikl::getCena()const{
    return cena;
}
Date Artikl::getDonesen()const{
    return donesen_vo_prodavnica;
}

void Artikl::prikazi_podatoci()const{
    cout<<"ime: "<<ime_na_artikl;
    cout<<"\nGolemina: "<<golemina;
    cout<<"\nCena: "<<cena;
    cout<<"\nDonesen vo prodavnica: ";
    donesen_vo_prodavnica.display_standard();
}
bool Artikl::presmetaj_nabavka(Date& d){
    return ((d.getDay()-donesen_vo_prodavnica.getDay())-7<=0);
}

class Pantaloni:public Artikl{
private:
Date datum_na_sledna_nabavka;

public:
Date& getSlednaNabavka();
Pantaloni(char *,int,double,Date&,Date&);
void prikazi_podatoci()const;
char getSign(){return 'p';}


};
Date& Pantaloni::getSlednaNabavka(){
    return datum_na_sledna_nabavka;
}

Pantaloni::Pantaloni(char *ime,int golemina,double cena, Date& donesen,Date& sledna_nabavka):Artikl(ime,golemina,cena,donesen){
    datum_na_sledna_nabavka=sledna_nabavka;
}
void Pantaloni::prikazi_podatoci()const{
    cout<<"ime: "<<getIme();
    cout<<"\nGolemina: "<<getGolemina();
    cout<<"\nCena: "<<getCena();
    cout<<"\nDonesen vo prodavnica: ";
    getDonesen().display_standard();
    cout<<"\n Datum na sledna nabavka: ";
    datum_na_sledna_nabavka.display_standard();
    cout<<endl;
}

class  Kosuli:public Artikl{
    public:
    Kosuli(char *,int,double,Date&);
    char getSign(){return 'k';}
};
Kosuli::Kosuli(char *ime,int golemina,double cena,Date& donesen):Artikl(ime,golemina,cena,donesen){

}

class Store{
    Artikl** a;
    int count;
    public:
    Store();
    void dodavanje_artikl(Artikl*);
    void dodavnje_artikl();
    void prikazi_podatoci();
    void artikl_od_grupa();
    void nabavka_nedela();
};
Store::Store(){
    a=new Artikl*[50];
    count=0;
}
void Store::dodavanje_artikl(Artikl* aa){
a[count++]=aa;
}
void Store::dodavnje_artikl(){
    cout<<"Options: p-pantaloni ,k- kosuli "<<endl;
    char tmp;
    cin>>tmp;
    char* ime_na_artikl;
    int golemina;
    double cena;
    Date donesen_vo_prodavnica;
    Date sledna_nabavka;

    if(tmp=='p'){
    cout<<"Datum na sledna nabavka: \n";
    cout<<"tip: mm dd yy\n";
    cin>>sledna_nabavka;
    dodavnje_artikl(new Pantaloni(ime_na_artikl,golemina,cena,donesen_vo_prodavnica,sledna_nabavka));
    return;
    }
    dodavnje_artikl(new Kosuli(ime_na_artikl,golemina,cena,donesen_vo_prodavnica));
}

void Store::prikazi_podatoci(){
    double vkupno=0.0;
    for(int i=0;i<count;i++){
        a[i]->prikazi_podatoci();
        vkupno+=a[i]->getCena();
    }
    cout<<"Vkupnata cena na celata lista "<<vkupno<<endl;
}
void Store::artikl_od_grupa(){
cout<<"Options: p-pantaloni ,k- kosuli "<<endl;
char tmp;
cin>>tmp;
double vkupno=0.0;
for(int i=0;i<count;i++){
if(a[i]->getSign()==tmp){
a[i]->prikazi_podatoci();
vkupno+=a[i]->getCena();
}   

}
cout<<"Vkupnata cena na celata lista "<<vkupno<<endl;
}
void Store::nabavka_nedela(){
    Date nabavka;
    cout<<"Enter date: \n";
    cout<<"tip mm dd yy:\n";
    cin>>nabavka;
    double vkupno=0.0;
    for(int i=0;i<count;i++){
        if(a[i]->presmetaj_nabavka(nabavka)){
            a[i]->prikazi_podatoci();
            vkupno+=a[i]->getCena();
        }
    }
    cout<<"Vkupnata cena na celata lista "<<vkupno<<endl;
}
int main(){
Store s;

int choice=0;
cout<<"Odberete opcija: \n";
cin>>choice;

while(choice !=5){
    cout<<"Meni:";
    cout<<"\n1.Dodavanje na artikl vo listata";
    cout<<"\n2.Prikazhuvanje na artikli od dadena grupa";
    cout<<"\n3.Prikazhuvanje na celata lista (so vkupna cena)";
    cout<<"\n4.Prikazhuvanje na site artikli koi treba da se nabavat vo rok od 1 nedela i pari koi treba da se potroshat za da se nabavat potrebnite artkili";
    cout<<"\n5.Izlez";
    cin>>choice;
    switch (choice)
    {
    case 1:
    s.dodavnje_artikl();
        break;
    case 2:
    s.artikl_od_grupa();
    break;
    case 3:
    s.prikazi_podatoci();
    break;
    case 4:
    s.nabavka_nedela();
    break;
    default:
        break;
    }
}






    return 0;
}