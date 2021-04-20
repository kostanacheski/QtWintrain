/* 
2. Да се направи програма која ќе ја користи класата Штедач и ќе овозможи: 
a)	Внесување на нов штедач во системот
b)	Приказ на податоците
c)	Уплата на средства
d)	Исплата на средства (со контрола дали е можна таква исплата)
e)	Приказ на салдото за даден штедач
*/
#include <iostream>
using namespace std;
class Stedac
{
 public:
        void vnesi_podatoci();
        void prikazi_podatoci();
        void uplata(unsigned long i);
        void isplata(unsigned long i);
        long sostojba();

  private:
        int broj;
        char imeprezime[30], adresa[50];
        long saldo;
}; 
void Stedac::vnesi_podatoci(){
    cout<<"Broj: ";cin>>broj;
    cout<<"Ime i prezime:";cin>>imeprezime;
    cout<<"Adresa: "; cin>>adresa;
    cout<<"Saldo: ";cin>>saldo;
}
void Stedac::prikazi_podatoci(){
    cout<<"Broj: "<<broj<<" Ime i prezime: "<<imeprezime<<" Adresa: "<<adresa<<" Saldo "<<saldo;
}
void Stedac::uplata(unsigned long i){
    saldo=saldo+i;
}
void Stedac::isplata(unsigned long i){
    if(i>saldo){cout<<"Ne e vozmozhno da se izvrshi isplata\n";}
    else
    saldo=saldo-i;
}
long Stedac::sostojba(){
    return saldo;
}

int main(){
    int n;
    cout<<"Vnesi broj na shtedachi";
    cin>>n;
    Stedac *s;
    s=new Stedac[n];
    int choice;
    int temp;
    while(choice !=6){
        cout<<"Meni:"<<endl;
        cout<<"1. Vnesi nov shtedach vo sistemot\n";
        cout<<"2. Prikaz na podatocite\n";
        cout<<"3.Uplata na sredstva\n";
        cout<<"4.Isplata na sredstva\n";
        cout<<"5. Prikaz na saldo za daden shtedach\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
        s[temp].vnesi_podatoci();
        temp++;
            break;
        case 2:
        for(int i=0;i<n;i++){
            s[i].prikazi_podatoci();
        }
        s[temp].prikazi_podatoci();
        temp++;
        break;
        case 3:
        int num,suma;
        cout<<"Vnesi broj na shtedach koj saka da izvshi uplata: ";
        cin>>num;
        cout<<"Vnesi iznos na uplatata:";
        cin>>suma;
        s[num].uplata(suma);
        break;
        case 4:
        int num,suma;
        cout<<"Vnesi broj na shtedach koj saka da izvshi isplata: ";
        cin>>num;
        cout<<"Vnesi iznos na isplatata:";
        cin>>suma;
        s[num].isplata(suma);
        break;
        case 5:
        int num;
        cout<<"Vnesi broj na shtedach koj saka da ja proveri svojata sostojba:";
        cin>>num;
        cout<<"Sostojba: "<<s[num].sostojba();
        break;
        default:
            break;
        }
    }
}