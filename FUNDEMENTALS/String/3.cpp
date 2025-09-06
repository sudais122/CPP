#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name;

    cout <<"Enter name";
    getline(cin , name);

    int point = name.find('@');

    string username = name.substr(0,point);
    cout << "usernmae: " << username <<endl; 
    
}