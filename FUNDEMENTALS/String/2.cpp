#include<iostream>
#include<string>
using namespace std;

int main()
{
    // string name;

    // cout <<"Enter name";
    // getline(cin , name);

    // string psrt1 = name.substr(0 , 5);
    // cout  << "isr 5 character: " <<  psrt1 <<endl;

    // string lastFour = name.substr(name.length() - 4, 4);
    // cout  << "last 4 character: " <<  lastFour <<endl;


// string s1;
// string s2;

// cout << "ist string";
// cin >>  s1;
// cout << "second string";
// cin >> s2;

// s2.append(s1,0,4);

// cout << s1;

string s1,s2,s3,sentence;

    cout << "ist string";
        cin >>  s1;

    cout << "second string";
        cin >>  s2;

    cout << "3rd string";
        cin >>  s3;

        sentence.append(s1);
        sentence.append(" ");
        sentence.append(s2);
        sentence.append(" ");
        sentence.append(s3);

        cout << sentence <<endl;    
    }