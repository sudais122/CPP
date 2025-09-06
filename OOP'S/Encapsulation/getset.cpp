// ✅ Task 1: Employee Salary Manager
// Create a class Employee with:

// private: int salary

// public:

// setSalary(int) → setter

// getSalary() → getter

// Logic: if salary is negative, don't allow it and show
#include<iostream>
using namespace std;

class student {
private: 
    int sallary;               
public:
    void sersalary(int s){
        sallary = s;
    }

    int show(){
        if (sallary < 0)
        {
            cout << "salary is negative" <<endl;
            return 0;
        }
        else{
        cout <<"salary is\n";
        }
        return sallary; 
    }                
};
int main() {
    student s1;
    s1.sersalary(-34);
    int x = s1.show();
    cout << x <<endl;
    return 0;
}