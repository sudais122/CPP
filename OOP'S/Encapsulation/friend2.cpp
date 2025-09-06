// Create two classes: ClassA and ClassB.

// Both have private int members.

// Make a friend function sum() that takes objects of both classes and prints the sum of 
// their private members.
#include<iostream>
using namespace std;

class B;
class A{
    int num;
public:
    void setvalues(int n){
        num = n;
    }
    friend void sum(A a,B b);
};

class B{
    int num2;
public:
    void setvalues(int s){
        num2 = s;
    }
    friend void sum(A a,B b);
};

void sum(A a,B b){
    int add = a.num +  b.num2;
    cout << "SUM is: " <<" " << add <<endl;
}
int main() {
    A a1;
    a1.setvalues(5);
    B b1;
    b1.setvalues(5);
    sum(a1,b1);
    return 0;
}