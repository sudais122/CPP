#include<iostream>
using namespace std;

class name{
    int age;
public:
    void setdata(int age){
        this->age = age;
        this->show();
    }
    void show(){
        cout << "Age=:"<<" "<<this->age <<endl; 
    }
};
int main() {
    name n;
    n.setdata(4);
    return 0;
}