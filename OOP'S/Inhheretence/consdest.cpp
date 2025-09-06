#include<iostream>
using namespace std;

class base
{
public:
    base()
    {
        cout << "base constructor\n";
    }
    ~base()
    {
        cout << "base destructor called\n";
    }
};

class derived : public base
{
public:
    derived()
    {
        cout << "derived constructor\n";
    }
    ~derived()
    {
        cout << "derived destructor called\n";
    }
};
int main() {
    derived d; // constructor call Top to Bottam
    /*base constructor
    derived constructor
    
    Destructor call from bottam to top
    derived destructor called
    base destructor called*/
    return 0;
}