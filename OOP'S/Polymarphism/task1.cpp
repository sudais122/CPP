#include<iostream>
using namespace std;

class Complex
{
    int real_part;
    int imaginary_part;
public:
    Complex(int real_part,int imaginary_part)
    {
        this -> real_part = real_part;
        this -> imaginary_part = imaginary_part;
    }

    Complex operator+(Complex c)
    {
        return Complex(real_part + c.real_part,imaginary_part+c.imaginary_part);
    }

    void display()
    {
        cout << real_part << " " << "+" << " " <<imaginary_part<< "i\n";
    }
};
int main()
{
    Complex c1(3,2);
    Complex c2(1,7);
    Complex c3 = c1 + c2;
    c3.display();
return 0;
}