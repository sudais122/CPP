#include<iostream>
using namespace std;

class person
{
    string name;
    int age;
    int long CNIC;
public:
    void setPersonData(string name,int age,int long CNIC)
    {
        this ->name = name;
        this ->age = age;
        this ->CNIC = CNIC;
    }
    void displayPersonData()
    {
        cout << "Name:"<<" " <<name <<endl;
        cout << "Age:"<<" " <<age <<endl;
        cout << "CNIC:"<<" " <<CNIC <<endl;
    }
};

class Student : public person
{
    int rollno;
    string department;
public:
    void setstudentdata(int rollno,string departmen)
    {
        this -> rollno = rollno;
        this -> department = departmen;
    }

    void displstudentaydata()
    {
        cout <<"Rollno:"<<" "<<rollno<<endl;
        cout << "Departent:"<<" "<<department<<endl;
    }
};

class Teacher : public person
{
    string subject;
    int empoyeeID;
public:
    void setTeacherData(string subject,int empoyeeID)
    {
        this ->subject = subject;
        this ->empoyeeID = empoyeeID;
    }

    void displayTeacherdata()
    {
        cout <<"Subject:"<<" "<<subject<<endl;
        cout << "Employee ID:"<<" "<<empoyeeID<<endl;
    }
};

class Result : public Student
{
    int marks1,marks2,marks3;
public:
    void setmarks( int marks1,int marks2,int marks3)
    {
        this -> marks1 = marks1;
        this -> marks2= marks2;
        this -> marks3 = marks3;
    }
    void displayresult()
    {
        int total,average;
        total = marks1+marks2+marks3;
        average = total/3;
        cout << "Marks:" << marks1 <<", " <<marks2 <<", " <<marks3 <<endl;
        cout <<"Total:" <<" "<<total <<endl;
        cout <<"Average:" <<" " <<average <<endl;
    }
};

class TA:public Student,public Teacher
{
    int assistantID;
    int hours;
public:
    void setTAdata(int assistantID, int hours)
    {
        this -> assistantID = assistantID;
        this -> hours = hours;
    }
    void displayTAdata()
    {
        cout <<"Assistant ID:" <<" " << assistantID <<endl;
        cout << "Hours:"<<" " <<hours <<endl;
    }
};
int main() {
    cout <<"1.Stiudent info\n";
    cout <<"2.Teacher info\n";
    cout <<"3.Stiudent Result\n";
    cout <<"4.TA info\n";
    cout <<"5.Exit Program\n";

    int choice;
    cout <<"Enter Choice";
    cin >> choice;
    person p;
    Student s;
    Teacher t;
    Result r;
    TA ta;

    int name,age,rollno,id;
    int long cnic;
    string nme,department,subject;

    switch (choice)
    {
    case 1:
        cout <<"Enter Name:"<<" ";
        cin>>nme;
        cout <<"Enter Age:"<<" ";
        cin>>age;
        cout <<"Enter CNIC:"<<" ";
        cin>>cnic;
        cout << "Enter Rollno:"<<" ";
        cin >> rollno;
        cout << "Enter Departmrnt:"<<" ";
        cin >>department;
        p.setPersonData(nme,age,cnic);
        s.setstudentdata(rollno,department);
        cout << "---Student info---\n";

        p.displayPersonData();
        s.displstudentaydata();
    break;
    case 2:
        cout <<"Enter Name:"<<" ";
        cin>>nme;
        cout <<"Enter Age:"<<" ";
        cin>>age;
        cout <<"Enter CNIC:"<<" ";
        cin>>cnic;
        cout <<"Enter Employee ID"<<" ";
        cin >> id;
        cout <<"Enter Subject"<<" ";
        cin >> subject;
        p.setPersonData(nme,age,cnic);
        t.setTeacherData(subject,id);
        cout << "---Teacher info---\n";

        p.displayPersonData();
        t.displayTeacherdata();
    break;
    case 3:
        int marks1,marks2,marks3;
        cout << "Enter marks1: " <<" ";
        cin >> marks1;
        cout << "Enter marks2: " <<" ";
        cin >> marks2;
        cout << "Enter marks3: " <<" ";
        cin >> marks3;

        r.setmarks(marks1,marks2,marks3);
        r.displayresult();
    break;
    case 4:
    int empid,taid,hr;
    string subj;
        cout <<"Enter Name:"<<" ";
        cin>>nme;
        cout <<"Enter Age:"<<" ";
        cin>>age;
        cout <<"Enter CNIC:"<<" ";
        cin>>cnic;
        cout << "Enter Rollno:"<<" ";
        cin >> rollno;
        cout << "Enter Departmrnt:"<<" ";
        cin >>department;
        cout <<"Enter Employee ID:"<<" ";
        cin>>empid;
        cout <<"Enter Subject:"<<" ";
        cin>>subj;
        cout <<"Enter TA ID:"<<" ";
        cin>>taid;
        cout <<"Enter CR Hours:"<<" ";
        cin>>hr;
        p.setPersonData(nme,age,cnic);
        s.setstudentdata(rollno,department);
        t.setTeacherData(subj,empid);
        ta.setTAdata(taid,hr);

        p.displayPersonData();
        s.displstudentaydata();
        t.displayTeacherdata();
        ta.displayTAdata();
    }
    return 0;
}