#include<iostream>
using namespace std;

class Marks {
    int marks[5];
    int sum = 0;
    int average;
public:
    void input(){
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks of student:"<< i+1<<" ";
            cin >> marks[i];
        }
    }

    void display()
    {
        cout <<"----DMC----\n";
        for (int  i = 0; i < 5; i++)
        {
            cout << "Marks of Student"<<i+1<<": "<<marks[i]<<"\n";
            sum +=marks[i];
        }
    }

    void averagecal(){
        average = sum/5;
        cout << "Average: "<<" "<< average <<endl;
    };
};
int main() {
    
    Marks m;
    m.input();
    m.display();
    m.averagecal();
    
    return 0;
}