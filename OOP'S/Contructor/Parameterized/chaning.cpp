#include<iostream>
using namespace std;

class A{
    string name;
    int age;
public:
    A():A(4){
        cout << "Default Constructor"<<endl;
    }
    A(int b):A(34,"sudais"){
        cout << "Parameteried constructor with int" <<endl;
    }
    A(int age1,string  name1){\
        this-> age = age1;
        this-> name =  name1;
        cout <<"Both int and age"<<endl;
    }

    void display(){
        cout << "Name:" <<" " << this-> name<<endl;
        cout <<"Age:" <<" " << this->age <<endl;
    }

    void greet() const{
        cout <<"Hello,\t"<< "my name is\t" <<this->name << " " <<"i nam\t " << this->age <<" " << " years old" <<endl; 
    }
};

int main() {
    A a;
    a.display();
    a.greet();
    return 0;
}