/*1. Во една зоолошка градина се води евиденција за различни типови животни кои се чуваат во неа: птици, влекачи, цицачи.... 
Користејќи ги концептите на ООП да се моделира класа според спецификациите дадени на слика 5.1. 
Цицачите се вакцинираат секоја година, птиците на секои 6 месеци, а влекачите на секои 8 месеци. 
Датумите да се дефинираат во посебна класа Datum со приватни податочни членки den, mesec и godina.
 Да се имплементира кориснички посредник преку мени со следните опции:
1.	Додавање на животно во зоолошка градина
2.	Прикажување на бројна состојба
3.	Прикажување на животни од дадена група (тип: c- цицачи, v-влекачи, p-птици)
4.	Прикажување на целата листа
5.	Прикажување на сите животни кои треба да се вакцинираат во рок од 1 недела
6.	Излез од менито

*/
#include <iostream>
#include <cstring>
using namespace std;

class Datum{
    private:
    int den;
    int mesec;
    int godina;
    int checkDay(int);
    public:
    int getGodina()const{return godina;}
    int getMesec() const{return mesec;}
    Datum(int =1,int =1,int =2007);
    void print() const;
    ~Datum();
};

Datum::Datum(int mn,int dy,int yr){
    if(mn>0 && mn<=12) mesec=mn;
    else{
        mesec=1;
        cout<<"Mesec "<<mn<<" ne postoi.Postavi go month na 1.\n";
    }
    godina=yr;
    den=checkDay(dy);
    cout<<"Konstruktorot za objekt od klasata Date: ";
    print();
    cout<<endl;
}
void Datum::print() const{
    cout<<mesec<<'/'<<den<<'/'<<godina;
}
Datum::~Datum(){
    cout<<"Destruktorot na klasata Date ";
    print();
    cout<<endl;
}
int Datum::checkDay(int testDay){
    static const int daysPerMonth[ 13 ] = 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

if(testDay>0 && testDay<=daysPerMonth[mesec]) return testDay;

if(mesec==2 && testDay==29 &&(godina%400 ==0 || (godina%4==0 && godina%100!=0)))
return testDay;

cout<<"Denot "<<testDay<<" e greshen.Postavi vrednost za day na 1.\n";
return 1;
}

class Zivotno{
private:
const Datum datum_na_ragjanje;
const Datum datum_na_donesuvanje;
char tip;//c-cicachi,v-vlekachi,p-ptici
char Pol;//m/z
char ime[25];
const Datum posledna_vakcinacija;
public:
Zivotno(int,int,int,int,int,int,char,char,char *,int,int,int);
~Zivotno();
void Prikazi_Podatoci();
int Presmetaj_vakcinacija();

};

Zivotno::Zivotno(int bmonth,int bday,int byear,int dmonth,int dday,int dyear,char t,char p,char *name,int vmonth,int vday,int vyear):
datum_na_ragjanje(bmonth,bday,byear),datum_na_donesuvanje(dmonth,dday,dyear),posledna_vakcinacija(vmonth,vday,vyear){
int lenght=strlen(ime);
lenght=(lenght<25 ? lenght:24);
strncpy(ime,name,lenght);
ime[lenght]='\0';
tip=t;
Pol=p;
}
void Zivotno:: Prikazi_Podatoci(){
cout<<"Zivotno: "<<ime<<" Tip: "<<tip<<" Pol "<<Pol<<endl;
datum_na_ragjanje.print();
cout<<"Datum na donesuvanje vo zoo: \n";
datum_na_donesuvanje.print();
cout<<"Posledna vakcinacija: \n";
posledna_vakcinacija.print();
}
int Zivotno::Presmetaj_vakcinacija(){
    int count;
    if(tip=='c'){
        int y1=datum_na_donesuvanje.getGodina();
        int y2=posledna_vakcinacija.getGodina();
        int razlika=y2-y1;
        return razlika;

    }
    else if(tip=='p'){
        int temp=0;
        
        int y1=datum_na_donesuvanje.getGodina();
        int y2=posledna_vakcinacija.getGodina();
        int m1=datum_na_donesuvanje.getMesec();
        int m2=posledna_vakcinacija.getMesec();
        if(y1==y2){
            return 1;
        }
        else{
            temp=y2-y1;
            count=temp*12+((-1)*(m2-m1));
            return count/6;
        }
    }
        else if(tip=='v'){
            int temp=0;
        int y1=datum_na_donesuvanje.getGodina();
        int y2=posledna_vakcinacija.getGodina();
 int m1=datum_na_donesuvanje.getMesec();
        int m2=posledna_vakcinacija.getMesec();
        if(y1==y2){
            return 1;
        }
        else{
            temp=y2-y1;
            count=temp*12+((-1)*(m2-m1));
            return count/8;
        }
        }
}






int main(){


    int choice;
    while(choice!=6){
        cout<<"1. Dodavanje na zhivotno vo zooloshka gradina\n";
        cout<<"2.Prikazhuvanje na brojna sostojba\n";
        cout<<"3. Prikazhuvanje na zhivotni od dadena grupa(c-cicachi,v-vlekachi,p-ptici)\n";
        cout<<"4.Prikazhuvanje na celata lista\n";
        cout<<"5.Prikazhuvanje na site zhivotni koi treba da se vakciniraat vo rok od 1 nedela\n";
        cout<<"6.Izlez od menito";
        cin>>choice;
        switch(choice){
        case 1:

        case 2:
        case 3:
        case 4:
        case 5:
        default:


        }
    }
    cout<<"Kraj.\n";
}