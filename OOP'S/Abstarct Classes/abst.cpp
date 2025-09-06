#include<iostream>
using namespace std;

class base{
public:
    virtual void show(){
        cout << "Base class;\n";
    }
};

class derived : public base{
public:
    void show()override{
        cout << "derived\n";
    }
};
int main() {

    base*ptr;

    derived d;
    ptr = &d;
    ptr->show();
    return 0;
}