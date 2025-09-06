#include<iostream>
using namespace std;

// 📘 Student class definition
class student {
    string name;
    int rollno;
    float CGPA;

public:
    // 🎯 Parameterized constructor to initialize student details
    student(string name, int rollno, float CGPA) {
        this->name = name;
        this->rollno = rollno;
        this->CGPA = CGPA;
    }

    // 🔁 Copy constructor that modifies name and CGPA slightly
    student(const student& student2) {
        name = "Copy of " + student2.name;     // Add prefix to copied name
        rollno = student2.rollno;              // Copy roll number as-is
        CGPA = student2.CGPA + 0.02;           // Add bonus to CGPA
    }

    // 📋 Display function to print student details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "CGPA: " << CGPA << endl;
    }
};

int main() {
    // 👨‍🎓 Original student object
    student original("Sudais", 34, 3.69);
    cout << "📚 Original Student:\n";
    original.display();

    // 🧾 Copied student object using copy constructor
    student copied = original;
    cout << "\n📋 Copied Student:\n";
    copied.display();

    return 0;
}
