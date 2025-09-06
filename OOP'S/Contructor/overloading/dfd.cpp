#include<iostream>
using namespace std;

class Student {
private:
    int age;  

public:
    void  Student1(int a) {   
        age = a;           
    }

    void  getage(){
        if (age < 0)
        {
            cout << "invalid value" <<endl;
            return 0 ;
        }
        if (age > 18)
        {
            cout << "you can vote" << endl;
        }
        else
        {cout << "you can't vote" <<endl;}
        return age;
    }
};

int main() {
    Student s1;
    s1.Student1(34);
    int x = s1.getage();
    cout << "age is :" << x <<" "<<endl;

    s1.Student1(45);
    int y = s1.getage();
    cout << "second age is :" << y <<" "<<endl;

 }