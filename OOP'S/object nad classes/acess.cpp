// * Defines a class `Student`
// Program* Has the following members:

//   * `private`: `int rollNumber`
//   * `protected`: `float marks`
//   * `public`:

//     * `string name`
//     * A function `setData()` (to set all values)
//     * A function `display()` defined **outside** the class using `::`
// * In `main()`, create **two objects** of `Student`, input values, and display info

// ---
#include<iostream>
using namespace std;

class student{
private:
    int rollno;
protected: 
    float marks;
public:
    string name;

    void setdata(int a,float b,string c){
        rollno = a;
        marks = b;
        name = c;
    }

    void display();
};

void student::display(){
    cout <<"Rollno: " << " " << rollno <<endl;
    cout <<"Marks: " << " " << marks <<endl;
    cout << "Name: " << " " << name <<endl;
 }
int main()
{
    student s1;
        s1.setdata(32,44.4,"sudais");
        s1.display();
}