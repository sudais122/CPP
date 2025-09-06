#include<iostream>
using namespace std;

struct student{
    int RollNo;
    string Name;
        struct data{
            int day;
            int month;
            int year;
    }dob;
}s;

int main()
{
    student s[4];
    for (int i = 0; i <4; i++)
    {
        cout << "Enter rollno";
        cin >>s[i].RollNo;
        cout << "Enter name";
        cin >>s[i].Name;

        cout << "Date of Birth";

        cout << "Enter date of birth(day)";
        cin >>s[i].dob.day;
        cout << "Enter date of birth(month)";
        cin >>s[i].dob.month;
        cout << "Enter date of birth(day)";
        cin >>s[i].dob.year;

        cout << "________________________________" <<endl;

    }

        for (int i = 0; i <4; i++)
    {
        cout << " rollno: "<<s[i].RollNo <<endl;
        cout << "Enter name: "<<s[i].Name <<endl;

        cout << "Date of Birth" <<endl;
        
        cout << "Date of Birth (Day): " << s[i].dob.day << endl;
        cout << "Date of Birth (Month): " << s[i].dob.month << endl;
        cout << "Date of Birth (Year): " << s[i].dob.year << endl;
        cout << "________________________________" << endl;

    }
    
}
