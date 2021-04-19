/* 2. 2Нaпиши С++ програм со две посебни функции кои едноставно ја триплираат вредноста на променливата count дефинирана во main. 
Овие функции се:
a.	Функцијата tripleCallByValue која предава копија од count, ја триплира нејзината вредност и ја враќа новата вредност
b.	Функцијата tripleCallByReference која ja предава count како референцен параметар,
 ја триплира самата променлива и ја враќа новата вредност на count
*/
#include <iostream>
using std::cout;
using std::endl;

int tripleCallByValue(int c){
    return 3*c;
}
void tripleCallBYReference(int &c){
   c*=3;
}

int main(){
int count=1;

cout<<"Po kopija "<<tripleCallByValue(count)<<endl;
tripleCallBYReference(count);
cout<<"Po Referenca "<<count<<endl;

}