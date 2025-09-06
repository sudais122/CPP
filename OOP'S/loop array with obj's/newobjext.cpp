#include<iostream>
using namespace std;

class student{
    int age;
    int rollno;
public:
    void setdata(int age,int rollno)
    {
        this -> age = age;
        this -> rollno = rollno;
    }
    void printdata()
    {
        cout << "Age: "<<" " <<age <<endl;
        cout << "Rollno: "<<" " <<rollno <<endl;
    }
};
int main() {
    student *ptr = new student;

    ptr ->setdata(34,5);
    ptr ->printdata();
    return 0;
}