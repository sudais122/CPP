#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class student {
protected:
    int rollno;
    string name;
    float marks[3];
    int average;
    float percentage;
    int sum = 0;

public:
    void input() {
        cout << "Enter Rollno: ";
        cin >> rollno;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        for (int i = 0; i < 3; i++) {
            cout << "Enter Marks of subject " << i + 1 << ": ";
            cin >> marks[i];
            sum += marks[i];
        }

        average = sum / 3.0;
        percentage = (sum / 300.0) * 100;
    }

    void show() {
        ofstream write("record.txt", ios::app);
        if (write.is_open()) {
            cout << fixed << setprecision(2);
            write << fixed << setprecision(2);

            cout << "Roll No: " << rollno << endl;
            cout << "Name: " << name << endl;
            cout << "Total Marks: " << sum << endl;
            cout << "Average: " << average << endl;
            cout << "Percentage: " << percentage << "%" << endl;

            write << "Roll No:" << rollno << endl;
            write << "Name: " << name << endl;
            write << "Total Marks: " << sum << endl;
            write << "Average: " << average << endl;
            write << "Percentage: " << percentage << "%" << endl;

            if (percentage >= 90) {
                cout << "Grade: A\n";
                write << "Grade: A\n";
            } else if (percentage >= 80) {
                cout << "Grade: B\n";
                write << "Grade: B\n";
            } else if (percentage >= 70) {
                cout << "Grade: C\n";
                write << "Grade: C\n";
            } else if (percentage >= 60) {
                cout << "Grade: D\n";
                write << "Grade: D\n";
            } else {
                cout << "Fail\n";
                write << "Fail\n";
            }

            write << "--------------------\n";
            write.close();
        } else {
            cout << "Error writing to file.\n";
        }
    }
};

class display : public student {
public:
    void diaplay() {
        ifstream read("record.txt");
        string line;

        if (read.is_open()) {
            cout << "\nAll Student Records:\n";
            cout << "-----------------------------\n";
            while (getline(read, line)) {
                cout << line << endl;
            }
        } else {
            cout << "File opening error.\n";
        }
    }
};

class Search : public student 
{
   string search;
    string line;
public:
    void searchdata() {   
        cout << "Enter Roll-no: ";
        cin >> search;

        ifstream searchrollno("record.txt");

        if (searchrollno.is_open()) {
            bool found = false;
            string matchline = "Roll No:" + search;

            while (getline(searchrollno, line)) {
                if (line == matchline) {
                    found = true;
                    cout << "Data found\n";
                    cout << "-------------\n";
                    cout << line << endl;

                    for (int i = 0; i < 5; i++) {
                        getline(searchrollno, line);
                        cout << line << endl;
                    }

                    break; 
                }
            }

            if (!found) {
                cout << "Data not found\n";
            }
        }
    }

};

class deletedata : public student {
public:
void delet()
{ 
    int rollno;
    string line;
    bool deleted = false;
    cout << "Enter Rollno: ";
    cin >> rollno;

    ifstream read ("record.txt");
    ofstream write ("temp.txt");
    string mline = "Roll No:" + to_string(rollno);

    while (getline(read,line))
    {
        if (line == mline)
        {
            deleted = true;
            for (int i = 0; i < 6; i++)
            {
                getline(read,line);
                continue;
            }
        }
        else
        {
            write << line <<endl;
        }
    }
    read.close();
    write.close();
    
    remove("record.txt");
    rename("temp.txt","record.txt");

    if (deleted)
    {
        cout << "Deleted Sucessfully\n";    
    }

};
};
int main() {
    int choice;
    student s;
    display d;
    Search S;
    deletedata del;
    cout << "\nSTUDENT RECORD SYSTEM\n";
    cout << "------------------------\n";
    cout << "1. Add New Student\n";
    cout << "2. Display All Data\n";
    cout << "3. Search by Roll No\n";
    cout << "4. Delete Record\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            s.input();
            s.show();
            break;
        case 2:
            d.diaplay();
            break;
        case 3:
            S.searchdata();
            break;
        case 4:
            del.delet();
        default:
            cout << "Invalid choice.\n";
            break;
    }
}
