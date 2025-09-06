/*✅ Task 1: Array of Structures with Input/Output

Problem:
Create a program to store data of 5 students using an array of structures.
Each student has:
Roll number
Name
Marks in 3 subjects
Then:
Calculate and display total marks for each student.
Concepts tested:
✅ Array of structs
✅ Input/Output
✅ Iteration with structs*/
#include<iostream>
using namespace std;

struct student
{
    int rollno;
    string name;

    struct marks
    {
        int DLD;
        int Programing;
        int Calculas;
    }submaks;
    int total;
}data;

int main()
{
   student data[5] = {
    {1, "Sudais", {30, 12, 20},0},
    {2, "Khan",   {15, 7, 19},0},
    {3, "Ahmed",  {5, 3, 20},0},
    {4, "Sara",   {22, 8, 20},0},
    {5, "Zara",   {9, 11, 20},0}
};

for (int i = 0; i < 5; i++)
{
    data[i].total = data[i].submaks.Calculas+ data[i].submaks.DLD+ data[i].submaks.Programing;
}

for (int i = 0; i < 5; i++)
{
    cout << "Roll. no: " << " " << data[i].rollno <<endl;
    cout << "Name: " << " " << data[i].name <<endl;
    cout << "Calculas Marks: " << " " << data[i].submaks.Calculas <<endl;
    cout << "Calculas Marks: " << " " << data[i].submaks.DLD <<endl;
    cout << "Calculas Marks: " << " " << data[i].submaks.Programing <<endl;
    cout << "Total marks: " <<" " << data[i].total <<endl;
    cout <<"------------------------------------------" <<endl;


}

}