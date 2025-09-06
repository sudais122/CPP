#include<iostream>
using namespace std;

class constant3{
    const int a;
    const string b;
public:
    constant3(int c, string d):a(c),b(d){
        cout << "Code run sucessfuly\n";
    }
    void display(){
        cout << "a=:"<<a<<endl;
        cout << "b=:"<<b<<endl;
    }
}; 
int main() {
    constant3 c1(23,"khan");
    c1.display();

        constant3 c2(27,"khan");
        c2.display();

    return 0;
}