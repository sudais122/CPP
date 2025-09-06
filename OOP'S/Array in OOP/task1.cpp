#include<iostream>
using namespace std;

class studentname
{
    string name[5];
public:
    void input(){
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter name: ";
        cin >> name[i];
    }
}


void show(){
     cout <<"----Details----\n";
    for (int i = 0; i < 5; i++)
    {
        cout << i+1<<"."<<"Student Name: " << name[i]<<"\n";
    }
}
};
int main() {
    studentname s;
    s.input();
    s.show();
    return 0;
}