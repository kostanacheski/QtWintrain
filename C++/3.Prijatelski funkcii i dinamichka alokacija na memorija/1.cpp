/*
Вежби:
1. Создади класа Stedac во која ќе користиш статичка податочна членка kamata која ќе ја чува вредноста на годишната камата 
за сите штедачи и статична податочна членка brojStedaci кој во секој момент кажува колку штедачи има во банката.
 Останатите податочни членки се lice, bilans и kredit.
  Името, презимето, адресата и телефонот на секој објeкт од класата Stedac  
  се сместени во приватна податочна членка lice која е од класaта Covek. 
*/
#include <iostream>
#include<cstring>
#include <cassert>
using namespace std;
using std::cout;
using std::endl;
class Covek{
    private:
    char *ime;
    char *prezime;
    char *adresa;
    int telefon;
    public:
    Covek(char *,char *,char * ,int);
    ~Covek();
    void print()const;

};
Covek::Covek(char *i,char *p,char *a,int t){
    ime=new char[strlen(i)+1];
    assert(ime!=0);
    strcpy(ime,i);
    prezime=new char[strlen(p)+1];
    assert(prezime!=0);
    strcpy(prezime,p);
    adresa=new char[strlen(a)+1];
    assert(adresa!=0);
    strcpy(adresa,a);
    telefon=t;
}

void Covek::print()const{
    cout<<"Person: "<<ime<<" "<<prezime<<" so adresa: "
    <<adresa<<" i telefonski broj: "<<telefon<<endl;
}


class Stedac{
private:
//static double kamata;
static int brojStedaci;
Covek *lice;
double bilans;
double kredit;
public:
Stedac(Covek *  ,double,double);
Covek getLice() const;
double getBilans();
double getKredit();
static int getBrojStedaci();
//static double getKamata();
void printStedaci()const;

};
int Stedac::brojStedaci=0;
int Stedac::getBrojStedaci(){return brojStedaci;}
//double Stedac::getKamata(){return kamata;}

Stedac::Stedac(Covek *l,double b,double k){
    this->lice=l;
 this->bilans=b;
 this->kredit=k;   
 ++brojStedaci;
 
}
double Stedac::getBilans(){return bilans;}
double Stedac::getKredit(){return kredit;}

void Stedac::printStedaci()const{
    this->lice->print();
    cout<<"So bilans: "<<bilans<<" i kredit: "<<kredit;
}
int main(){

cout<<"Brojot na stedaci pred instanciranje e: "<<Stedac::getBrojStedaci()<<endl;
Covek *c1Ptr=new Covek("Petko","Petkovski","123NewST.",9999999);
Covek *c2Ptr=new Covek("Ana","Anevska","22-34 Blv NY",777645222);
Covek *c3Ptr=new Covek("Jon","Jonovksi","New unamed street",998765132);
Stedac *s1Ptr=new Stedac(c1Ptr,2650.00,1000.00);
Stedac *s2Ptr=new Stedac(c2Ptr,2650.00,1000.00);
Stedac *s3Ptr=new Stedac(c3Ptr,2650.00,1000.00);

cout<<"Brojot na stedaci po instanciranje e: "<<s1Ptr->getBrojStedaci()<<endl;




    return 0;
}