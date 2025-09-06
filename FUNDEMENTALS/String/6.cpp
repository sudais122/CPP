#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name;

    cout <<"Enter name:" << " ";
    getline(cin , name);

    int count = 1;

    for (int c : name)
    {
        if (c == ' ')
        {
            count++;
        }
    }
    cout << "there are" <<" "<< count << "words";
    
}