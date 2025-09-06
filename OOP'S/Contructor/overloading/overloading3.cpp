#include<iostream>
using namespace std;

class student{
private:
    int rollNo;
    string name;
    float percentage;
public:
    student(){
        rollNo = 0;
        name = "Unknown";
        percentage = 0.0;
    }
    student(int r){
        rollNo = r;
        name = "Unknown";
        percentage = 0.0;
    }
    student(int r,string n){
        rollNo = r;
        name = n;
        percentage = 0.0;
    }
    student(int r,string n,float p){
        rollNo = r;
        name = n;
        percentage = p;
    }
    void display();
};

void student :: display(){
        cout << "Roll-No: "<< "  " << rollNo << endl;
        cout << "Name: "<< "  " << name << endl;
        cout << "Percantage: "<< "  " << percentage<< endl;
        cout << "----------------------------\n";
    }
int main(){
    student s1;
    s1.display();

    student s2(15);
    s2.display();

    student s3(19,"sudias");
    s3.display();

    student s4(10,"Akbae",91.86);
    s4.display();
}