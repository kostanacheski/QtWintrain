/*1. Нека е дадена класата Complex со кодовите презентирани подолу (дефиниција на класа, дефиниција на функции цхленки и драјвер за 
класатa Complex). 
Оваа класа овозможува операции со комплексни броеви. Тоа се броеви од облик realenDel + imaginarenDel * i, каде i има вредност √1

а) да се модифицира класата така да овозможи влез и излез на комплексни броеви преку преклопување на операторите << и >>.
 Ова треба да ја замени функцијата print() од класата, која во вашето решение не треба да постои.
б) да се преклопи оператор за множење кој ќе овозможи множење на: два комплексни броја, комплексен со цел број и цел број со 
комплексен број.
в) да се преклопат операорите == и != кои ќе овозможат споредување на два комплексни броја.
г) да се преклопат операторите +=, -= и *= со помош на ваќе направените функции за преклопување на +, - и *.
*/
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::setw;
class Complex {
public:
   Complex( double = 0.0, double = 0.0 );       
   void getRI(double &r,double &i){real=r;imaginary=i;}
   Complex operator+( const Complex & ) const;  
   Complex operator-( const Complex & ) const;  
   Complex operator*(const Complex &) const;
   Complex operator*(int i);
   int operator==(Complex &);
   int operator&& (Complex &);
   int operator!=(Complex &);
   const Complex &operator=( const Complex & ); 
   friend ostream &operator<<(ostream&,const Complex &);
   friend istream &operator>>(istream&,Complex &);          
   Complex& operator+=(const Complex &);
   Complex& operator-=(const Complex &);
   Complex& operator*=(const Complex &);
private:
   double real;       
   double imaginary;  
}; 
Complex::Complex( double r, double i ) : real( r ), imaginary( i ) { }
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real,imaginary + operand2.imaginary );
}
Complex Complex::operator*(const Complex &operand2)const{
    Complex result=*this;
    result.real=real*operand2.real-imaginary*operand2.imaginary;
    result.imaginary=(real*operand2.imaginary)+(operand2.real*imaginary);
    return result;

}
Complex Complex::operator*(int i){
    Complex tmp;
    tmp.real*=i;
    tmp.imaginary*=i;
    return tmp;
}
Complex Complex::operator-( const Complex &operand2 ) const{
   return Complex(real - operand2.real,imaginary - operand2.imaginary );
}
const Complex& Complex::operator=( const Complex &right )
{
   real = right.real;
   imaginary = right.imaginary;
   return *this;  
}

int Complex::operator==(Complex &operand2){
    if(real==operand2.real && imaginary==operand2.imaginary) return 1;
    else return 0;
}
int Complex::operator!=(Complex &operand2){
    if (real!=operand2.real && imaginary!=operand2.imaginary) return 1;
    else return 0;
}
int Complex::operator&&(Complex &operand2){
    return ((real&&operand2.real) && (imaginary&&operand2.imaginary));
}
ostream &operator<<(ostream &output,const Complex &c){
    output<<"("<<c.real<<", "<<c.imaginary<<"i)";
    return output;
}
istream &operator>>(istream &input,Complex &c){
    input>>c.real>>c.imaginary;
    return input;
}
Complex& Complex::operator+=(const Complex& operand2){
    this->real+=operand2.real;
    this->imaginary=operand2.imaginary;
    return *this;
}
Complex& Complex::operator-=(const Complex& operand2){
    this->real-=operand2.real;
    this->imaginary=operand2.imaginary;
    return *this;
}
Complex& Complex::operator*=(const Complex& operand2){
    this->real*=operand2.real;
    this->imaginary=operand2.imaginary;
    return *this;
}
int main()
{
   Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 );

   cout << "x: ";
   cin>>x;
   cout<<x;
   cout << "\ny: ";
   cout<<y;
   cout << "\nz: ";
   cout<<z;

   x = y + z;
   cout << "\n\nx = y + z:\n";
   cout<<x;
   cout << " = ";
   cout<<y;
   cout << " + ";
   cout<<z<<endl;

   x = y - z;
   cout << "\n\nx = y - z:\n";
   cout<<x;
   cout << " = ";
   cout<<y;
   cout << " - ";
   cout<<z;
   cout << endl;
    x = y * z;
   cout << "\n\nx = y * z:\n";
   cout<<x;
   cout << " = ";
   cout<<y;
   cout << " * ";
   cout<<z<<endl;
    int i = y == z;
   cout << "\n\nx = y == z:\n";
   cout<<i;
   cout << " = ";
   cout<<y;
   cout << " + ";
   cout<<z<<endl;
   int j= y!=z;
   cout << "\n\n y != z:\n";
   cout<<j;
   cout << " = ";
   cout<<y;
   cout << " + ";
   cout<<z<<endl;



   return 0;
} 


