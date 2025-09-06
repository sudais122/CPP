#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name;

    cout <<"Enter name";
    getline(cin , name);

    int count = 0;

    for (int c : name)
    {
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
        {
            count++;
        }
    }
    cout << "constants are" <<" "<< count;
    
}