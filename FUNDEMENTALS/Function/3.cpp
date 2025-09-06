#include<iostream>
using namespace std;

void power()
{
    int base,power,result=1;

    cout << "enter base";
    cin >> base;

    cout << "enter power";
    cin >> power;

    for (int i = 1; i <= power; i++)
    {
        result =  result * base;
    }
    cout << "result: " <<  result <<endl;
}
int main()
{
    power();
}