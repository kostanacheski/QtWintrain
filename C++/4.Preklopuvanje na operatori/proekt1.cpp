/*Проект 1:
Да се направи класа Matrica која работи со дводимензионална низа од цели броеви. 
Да се преклопат  оператори за влез и екстракција на потоци, индексен оператор, 
оператор за собирање, одземање и множење (низа со низа, низа со цел број и цел број со низа).
 Да се преклопат оператори за еднаквост и нееднаквост на низа, копирачки конструктор, конверзиски конструктор.
  Да се постави кориснички изборник за опции во главната програма. Може да се користат колку сакаме други помошни функции.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::setw;


class Matrica{
private:
 int row;
 int col;
 int **ptr;
 public:
friend ostream &operator<<(ostream &,const Matrica &);
friend istream &operator>>(istream &,Matrica &);
 Matrica(int =4,int =4);
 Matrica(const Matrica &);
 ~Matrica();
 void setValue(int ,int ,int);
 int getValue(int ,int);
Matrica operator=(const Matrica &);
Matrica operator+(int );
Matrica operator+(const Matrica &);
Matrica operator-(const Matrica &);
Matrica operator-(int x);
Matrica operator*(const Matrica &);
Matrica operator*(int);
bool operator==(const Matrica&)const;
bool operator!=(const Matrica&)const;
int* & operator[](const int &index) const ;

};  


Matrica::Matrica(int r,int c){
    row=r;
    col=c;
    ptr=new int*[row];

    for(int i=0;i<row;i++){
        ptr[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ptr[i][j]=0;
        }
    }
}
Matrica::Matrica(const Matrica& m):row(m.row),col(m.col){
   ptr = new int*[row];
   for(int i=0;i<row;i++){
       ptr[i]=new int[col];
   }
   for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
           ptr[i][j]=m.ptr[i][j];
       }
   }
}
Matrica::~Matrica(){
    for(int i=0;i<row;i++){
        delete [] ptr[i];
    }
    delete[] ptr;
}
void Matrica::setValue(int r,int c,int i){
    ptr[r][c]=i;
}
int Matrica::getValue(int r,int c){
    return ptr[r][c];
}
Matrica Matrica::operator=(const Matrica& m){
    Matrica tmp(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            tmp.ptr[i][j]=m.ptr[i][j];
        }
    }
    return tmp;
}
Matrica Matrica::operator+(const Matrica& m){
    if(row !=m.row || col !=m.col){
        return (*this);
    }
    Matrica tmp(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            tmp.ptr[i][j]=ptr[i][j]+m.ptr[i][j];
        }
    }
    return tmp;
}
Matrica Matrica::operator-(const Matrica& m){
    if(row !=m.row || col !=m.col){
        return (*this);
    }
    Matrica tmp(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            tmp.ptr[i][j]=ptr[i][j]-m.ptr[i][j];
        }
    }
    return tmp;
}
Matrica Matrica::operator*(const Matrica& m){
    Matrica tmp(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            for(int k=0;k<col;++k){
            tmp.ptr[i][j]+=ptr[i][k]*m.ptr[k][j];
            }
        }
    }
    return tmp;
}

istream &operator>>(istream &input,Matrica &m){
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.col;j++)
            input>>m.ptr[i][j];
    }
    return input;
}
ostream &operator<<(ostream &output,const Matrica &m){
    
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.col;j++){
            output<<setw(12)<<m.ptr[i][j];
        }
    output<<endl;
    }
    return output;
}
Matrica Matrica::operator+(int x){
    Matrica tmp;
    for(int i=0;i<tmp.row;i++){
        for (int j=0;j<tmp.col;j++){
            tmp.ptr[i][j]+=x;
        }
    }
    return tmp;
}
Matrica Matrica::operator-(int x){
    Matrica tmp;
    for(int i=0;i<tmp.row;i++){
        for (int j=0;j<tmp.col;j++){
            tmp.ptr[i][j]-=x;
        }
    }
    return tmp;
}
Matrica Matrica::operator*(int x){
    Matrica tmp;
    for(int i=0;i<tmp.row;i++){
        for (int j=0;j<tmp.col;j++){
            tmp.ptr[i][j]*=x;
        }
    }
    return tmp;
}
bool Matrica::operator==(const Matrica &m)const{
if(row !=m.row && col !=m.col)
return false;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(ptr[i][j] != m.ptr[i][j])
        return false;
    }
}
return true;
}
bool Matrica::operator!=(const Matrica &m)const{
    if(row !=m.row && col !=m.col)
return true;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(ptr[i][j] != m.ptr[i][j])
        return true;
    }
}
return false;
}
int* & Matrica::operator [](const int &index) const {
  return  ptr [index];
}
