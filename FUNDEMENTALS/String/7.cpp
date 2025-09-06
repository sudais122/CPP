#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name ;

    cout << "enter sentece";
    getline(cin,name);

    for(char &c : name)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            c = '#';
        }
    }
    cout << name << endl;
    
}