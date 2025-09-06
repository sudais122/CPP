#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string space = "               ";
    string space2 = "          ";

    cout << "-------------------------------------------------------------\n";
    cout << space << "STUDENT MARKS REPORT\n";
    cout << "-------------------------------------------------------------\n";

    string name;
    int rollno, grade;

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter Rollno: ";
    cin >> rollno;

    cout << "Enter Class: ";
    cin >> grade;

    int DLDmarks, PFmarks, idealogymarks, calculas, engmarks, total = 100;

    cout << "Enter DLD marks: ";
    cin >> DLDmarks;
    cout << "Enter PF marks: ";
    cin >> PFmarks;
    cout << "Enter Idealogy marks: ";
    cin >> idealogymarks;
    cout << "Enter Calculas marks: ";
    cin >> calculas;
    cout << "Enter English marks: ";
    cin >> engmarks;

    int obtain = DLDmarks + PFmarks + idealogymarks + calculas + engmarks;

    cout << "-------------------------------------------------------------\n";
    cout << "SUBJECT" << space2 << "MARKS OBTAINED" << space2 << "TOTAL MARKS\n";
    cout << "-------------------------------------------------------------\n";

    cout << "DLD:" << space2 << DLDmarks << space2 << total << endl;
    cout << "Programming:" << space2 << PFmarks << space2 << total << endl;
    cout << "Idealogy:" << space2 << idealogymarks << space2 << total << endl;
    cout << "Calculas:" << space2 << calculas << space2 << total << endl;
    cout << "English:" << space2 << engmarks << space2 << total << endl;


    float percentage = (obtain / 500.0) * 100;
    char grade1;

    if (percentage >= 90)
        grade1 = 'A';
    else if (percentage >= 80)
        grade1 = 'B';
    else if (percentage >= 70)
        grade1 = 'C';
    else if (percentage >= 60)
        grade1 = 'D';
    else
        grade1 = 'F';

    string result;
    if (percentage >= 60)
        result = "PASS";
    else
        result = "FAIL";

    int totalmark = 500;
    cout << "-------------------------------------------------------------\n";
    cout << "Total Marks Obtained: " << space2 << obtain << endl;
    cout << "Total Marks: " << space2 << totalmark << endl;
    cout << "Percentage: " << space2 << fixed << setprecision(2) << percentage << "%" << endl;
    cout << "Grade: " << space2 << grade1 << endl;
    cout << "Result: " << space2 << result << endl;

    return 0;
}
