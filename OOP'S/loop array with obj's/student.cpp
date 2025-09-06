#include<iostream>
using namespace std;

class student{
public:
    string Name;
    int marks;
    void details(string n,int m){
        Name = n;
        marks = m;
    }
    void print() {
        cout << "Name: " << Name << endl;
        cout << "Marks: " << marks << endl;
        cout << "-------------" << endl;
    }
};
int main() {
    
    student s[3];

    string name;
    int marks;

    cout << "Enter the Marsk and Name of 3 Student\n";
    for (int i = 0; i < 3; i++)
    {
        cout <<" Student: " <<" " << i+1 <<endl;
        cout << "Enter Name ";
        cin >> name;
        cout << "Enter Marks:"<<" ";
        cin >> marks;
        cout <<"----------------\n";

        s[i].details(name,marks);
    }
    
    for (int i = 0; i < 3; i++)
    {   
        cout << "Student" << " " << i+1<<endl;
        s[i].print();
    }

    int topscore = 0;

    for (int i = 1; i < 3; i++)
    {
        if (s[i].marks > s[i].marks)
        {
            topscore = i;
        }
    }
    
    cout << "Top scrorer: " <<" " << s[topscore].Name<<" " << "with" << " " << s[topscore].marks <<endl;
}
