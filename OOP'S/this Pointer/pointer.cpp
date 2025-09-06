#include <iostream>
using namespace std;

class student {
    int age;

public:
    void show(int a) {
        age = a;
        cout << "Inside show function, this = " << this << endl;
    }

    void print() {
        cout << "Inside print function, this = " << this << endl;
    }
}; 

class A{
    int age;
    int rollno;
public:
    A(int c) : age(c){
        cout <<"code run";
    }
};
int main() {
    student s1, s2;

    cout << "Address of s1: " << &s1 << endl;
    s1.show(54);
    s1.print();

    cout << "\nAddress of s2: " << &s2 << endl;
    s2.show(3);
    s2.print();

    // hence proved &object == this
    return 0;
}
