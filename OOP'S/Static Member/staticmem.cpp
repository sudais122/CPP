// Create a class Student that:

// Has a static data member count.

// Increments count every time a Student object is created.

// Prints the current number of students using a static function.

// Bonus: Show the total count in main() after creating multiple objects.
#include<iostream>
using namespace std;

class  student{
    int age;
    int rolno;
    static int count;

public:
    student(int a,int r){
        age = a;
        rolno = r;
        count++;
    }
    void getvalue(){
        cout << "age: " << " "<< age <<endl;
        cout << "Rollno: " << " " << rolno <<endl;
        cout <<"---------------------\n";
    }
    static void print(){
        cout << "COunt:"<<" "<< count <<endl;
  }
};
int student::count = 0;

int main() {
    student s1(45,5);
    s1.getvalue();

    student s2(67,9);
    s2.getvalue();

    student s3(67,9);
    s3.getvalue();
    student::print();
    return 0;
}