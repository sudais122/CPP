#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name;

    cout <<"Enter name";
    getline(cin , name);

    if (name.length() <= 5)
    {
        cout << name << endl;
        cout << "to short";
    }
    else if (name.length() > 5 && name.length() <= 15)
    {
         cout << name << endl;
        cout << "perfect lenght";
    }
    else
    {
         cout << name << endl;
        cout << "to long";
    }
}