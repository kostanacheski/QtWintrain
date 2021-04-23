/*Вежби:
Користејќи ги концептите на ООП да се моделираат соодветни класи според спецификациите дадени на слика 1, 
а потоа во функцијата main() да се констуира низа со објекти од долунаведените класи (професор, асистент, демонстратор) 
и имплементира кориснички посредник преку мени со следните опции: 
 
1.    Додавање на нов вработен во листата
2.    Прикажување на листата 
3.    Крај
*/
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class vraboten{
private:
char *ime;
char *prezime;
int godina;
public:
vraboten(char *,char*,int);
void postavi_ime(char *ime);
void postavi_prezime(char *prezime);
void postavi_godina(int godina);
void prikazi_podatoci(){
    cout<<"Vreboten :\n";
    cout<<"Ime: "<<ime<<" Prezime "<<prezime<<" Godina na vrabotuvanje "<<godina<<endl;
}
};
vraboten::vraboten(char *i,char *p,int g){
    ime=new char[strlen(i)+1];
    strcpy(ime,i);
    prezime=new char[strlen(i)+1];
    strcpy(prezime,p);
    godina=g;
}
void vraboten::postavi_ime(char *ime){
   strcpy(this->ime,ime);
}
void vraboten::postavi_prezime(char *prezime){
    strcpy(this->prezime,prezime);
}
void vraboten::postavi_godina(int godina){
    this->godina=godina;
}
class profesor:public vraboten{
private:
char *zvanje;
char *oblast;
int br_predmeti;
public:
profesor(char *ime,char *prezime, int godina,char *zvanje,char *oblast,int br_predmeti):vraboten(ime,prezime,godina){
vraboten(ime,prezime,godina);
this->zvanje=new char[strlen(zvanje)+1];
strcpy(this->zvanje,zvanje);
this->oblast=new char[strlen(oblast)+1];
strcpy(this->oblast,oblast);
this->br_predmeti=br_predmeti;
}
void postavi_zvanje(char *zvanje){strcpy(this->zvanje,zvanje);}
void postavi_oblast(char *oblast){strcpy(this->oblast,oblast);}
void postavi_predmeti(int br){br_predmeti=br;}
void prikazhi(){
    cout<<"Profesor: \n";
    prikazi_podatoci();
    cout<<"Zvanje "<<zvanje <<" Oblast "<<oblast<<" Broj na predmeti "<<br_predmeti<<endl;
}   
};
class assistent:public vraboten{
    private:
    char *zvanje;
    char *mentor;
    int br_predmeti;
    public:
    assistent(char *ime,char *prezime,int godina,char *zvanje,char *mentor,int br_predmeti):vraboten(ime,prezime,godina){
        vraboten(ime,prezime,godina);
        this->zvanje=new char[strlen(zvanje)+1];
        strcpy(this->zvanje,zvanje);
        this->mentor=new char[strlen(mentor)+1];
        strcpy(this->mentor,mentor);
        this->br_predmeti=br_predmeti;
    }
    void postavi_zvanje(char *zvanje){strcpy(this->zvanje,zvanje);}
    void postavi_mentor(char *mentor){this->mentor=mentor;}
    void postavi_predmeti(int br){br_predmeti=br;}
    void prikazi(){
        cout<<"Assistent\n";
        prikazi_podatoci();
        cout<<"Zvanje "<<zvanje<<" Mentor "<<mentor<<" Broj na predmeti "<<br_predmeti<<endl;
            }
};

class demonstrator:public vraboten{
    private:
    char *rabotno_vreme;
    public:
    demonstrator( char *ime, char *prezime,int godina,const char *rabotno_vreme):vraboten(ime,prezime,godina){
        vraboten(ime,prezime,godina);
        this->rabotno_vreme=new char[strlen(rabotno_vreme)+1];
       strcpy(this->rabotno_vreme,rabotno_vreme);
    }
    void postavi(char *r){strcpy(rabotno_vreme,r);}
    void prikazi(){
        cout<<"Demonstrator\n";
        prikazi_podatoci();
        cout<<"Rabotno vreme od : "<<rabotno_vreme[0]<<"h do: "<<rabotno_vreme[1]<<"h"<<endl;
    }
};
void pechatiVraboteni(vraboten** v,int n){
    for(int i=0;i<n;i++){
        vraboten* tmp=v[i];
        (*tmp).prikazi_podatoci();
    }
}
void dodadiVraboten(vraboten** v,int &n,char tip);
int main(){
vraboten** v=new vraboten*[10];
int brojach=0;
v[brojach++]=new profesor("Mile","Milevski",2001,"PhD", "Computer Science",5);
v[brojach++]=new profesor("Petko","Petkovski",2007,"Docent","web proggramming",3);
v[brojach++]=new profesor("Stanko","Stankovski",2010,"Magister","Data Science",4);
v[brojach++]=new assistent("Ana","Anevska",2016,"Bachelor","Mile",2);
v[brojach++]=new assistent("Mia","Mievska",2020,"Bachelor","Petko",1);
//v[brojach++]=new demonstrator("Panche","Panchov",20121,"9:30-13:00");

int choice=0;
cout<<"Odberete opcija\n";

cin>>choice;
while (choice !=3)
{   
    cout<<"Meni:\n";
    cout<<"1. Dodavanje na nov vraboten vo listata"<<endl;
    cout<<"2.Prikazhuvanje na listata "<<endl;
    cout<<"3.Kraj"<<endl;
    cin>>choice;
switch (choice)
{
case 1:
cout<<"Vnesi tip na vraboten koj sakash da go dodadesh: ";
cout<<"p za profesor ";
cout<<"a za assistent ";
cout<<"d za demonstrator";
char c;
cin>>c;
dodadiVraboten(v,brojach,c);
    break;
case 2:
pechatiVraboteni(v,brojach);
break;
default:
    break;
}
}
cout<<"Vkupno imame: "<<brojach<<" vraboteni na fakultetot."<<endl;
cout<<"Kraj na programata!!!! "<<endl;



}
void dodadiVraboten(vraboten** v,int &n,char tip){
char *ime;
char *prezime;
int godina;
char *zvanje;
char *oblast;
char *mentor;
int br_predmeti;
char *rabotno_vreme;
if(tip=='p'){
    cin>>ime>>prezime>>godina>>zvanje>>oblast>>br_predmeti;
    v[n++]=new profesor(ime,prezime,godina,zvanje,oblast,br_predmeti);
}
else if(tip=='a'){
    cin>>ime>>prezime>>godina>>zvanje>>mentor>>br_predmeti;
    v[n++]=new assistent(ime,prezime,godina,zvanje,mentor,br_predmeti);
}
else if(tip=='d'){
    cin>>ime>>prezime>>godina>>rabotno_vreme;
    v[n++]=new demonstrator(ime,prezime,godina,rabotno_vreme);
}

}