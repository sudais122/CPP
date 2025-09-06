// 🧱 Class Structure:
// 🔹 Person (Base Class)
// Data Members: name, age

// Member Function: setPersonData(), displayPerson()

// 🔹 Student (Derived from Person)
// Data Members: rollNo, course

// Member Function: setStudentData(), displayStudent()

// 🔹 Result (Derived from Student)
// Data Members: marks1, marks2, marks3

// Member Function: setMarks(), displayResult()

// Bonus: Calculate total and average marks inside displayResult()
#include<iostream>
using namespace std;
//Class A → Class B → Class C

class Person //class base
{
    int age;
    string name;
public:
    void setpersondata(int age,string name)
    {
        this ->age = age;
        this ->name = name;
    }
    void displayPerson()
    {
        cout <<"Age:" <<" " <<age <<endl;
        cout << "Name:" <<" " << name <<endl;
    }
};

class student : public Person // drrived class 1 from teh base class person
{
    int rollno;
    string course;
public:
    void setstudentdata(int rollno, string course)
    {
        this -> rollno = rollno;
        this ->course = course;
    }
    void displaystudentdata()
    {
        cout << "Roll No:" <<" " <<rollno <<endl;
        cout << "Course:" <<" " << course <<endl;
    }
};

class result : public student //derived class 2 inhereted from stident and person class
 {
    int marks1;
    int marks2;
    int marks3;
public:
    void setmarks(int marks1,int marks2,int marks3)
    {
        this -> marks1 = marks1;
        this -> marks2 = marks2;
        this -> marks3 = marks3;
    }

    void displaymarks()
    {
        int total = marks1+marks2+marks3;
        int average =  total/3;
        cout << "Marks:" <<" " <<marks1<<", " <<marks2 <<", " <<marks3 <<endl;
        cout <<"Total:"<<" " << total << endl;
        cout <<"Average:" <<" "<<average <<endl;
    }
};
int main() {
    result r;
    int age1,rollno,marks1,marks2,marks3;
    string name1,course;

    cout << "Enter Age:"<<" ";
    cin >>age1;
    cout << "Enter Name:"<<" ";
    cin >>name1;
    r.setpersondata(age1,name1);

    cout << "Enter Rollno:"<<" ";
    cin >>rollno;
    cout << "Enter Department:"<<" ";
    cin >>course;
    r.setstudentdata(rollno,course);

    cout << "Enter Marks1:"<<" ";
    cin >>marks1;
    cout << "Enter Marks2:"<<" ";
    cin >>marks2;
    cout << "Enter Marks3" <<" ";
    cin >> marks3;
    r.setmarks(marks1,marks2,marks3);

    cout <<"--------------Result Displayed------------\n";
    r.displayPerson();
    r.displaystudentdata();
    r.displaymarks();
      return 0;
}