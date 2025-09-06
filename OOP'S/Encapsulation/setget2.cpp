// private: int age

// public:

// setAge(int) → age must be 0 to 150

// getAge() →
// Show:

// <18 → Minor

// >=18 and <60 → Adult

// >=60 → Senior Citizen
#include<iostream>
using namespace std;

class student {
private: 
    int age;       
public:
    void setage(int a){
        age = a;
    }
    int getage(){
        if (age <= 18)
        {
            cout << "You are minor" <<endl;
        }
        else if (age >= 18 && age  < 60)
        {
            cout << "you are adult" <<endl;
        }
        else
        {
            cout << "senier citizen" <<endl;
        }
        return age;
    }                
                
};
int main() {
    student s1;
    s1.setage(78);
    int h = s1.getage();
    cout << h;
    return 0;
}