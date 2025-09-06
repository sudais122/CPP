#include<iostream>
using namespace std;

class courses{
    string name;
    int duration;
public:
    void setdata(string name,int duration)
    {
        this ->name =name;
        this ->duration = duration;
    }

    void show()
    {
        cout << "Name:"<<" " << name <<endl;
        cout << "Duaration in minutes:" <<" " << duration <<endl;
    }
};
int main() {
    int n;
    string course;
    int duration;
    cout <<"Enter the number of courses:"<<" ";
    cin >> n;

    courses* c = new courses[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter course name";
        cin >> course;
        cout <<"Enter Duration in min";
        cin >> duration;
        c[i].setdata(course,duration);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout <<"__________Details________\n";
        c[i].show();
    }
    
    delete[] c;
    return 0;
}