// Write a program with a class Rectangle:

// Private: length, width

// Public: A setter to set values

// Friend function calculateArea() that prints the area of the rectangle.
// #include<iostream>
// using namespace std;

// class student {
// private: 
//     int length;
//     int width;            
// public:
//     void setvalue(int l,int w){
//         length = l;
//         width = w;
//     }
//     friend void area(student s);          
// };
// void area(student s){
//     int areaofrec = s.length*s.width;
//     cout << "Area = " <<" " << areaofrec <<endl; 
// }
// int main() {
//     student s1;
//     s1.setvalue(2,3);
//     area(s1);
//     return 0;
// }
#include<iostream>
using namespace std;
class Alpha;

class Beta {
    int b;
public:
    void setB(int val) { b = val; }
    friend void displaySum(Alpha a, Beta b);
};

class Alpha {
    int a;
public:
    void setA(int val) { a = val; }
    friend void displaySum(Alpha, Beta);
};

    void displaySum(Alpha a1, Beta b1){
    int sum =  a1.a+ b1.b;
    cout << "sum is " << sum <<endl;
   }
int main() {    
    Alpha a;
    Beta b;

    a.setA(5);
    b.setB(15);

    displaySum(a,b);
    return 0;
}