#include<iostream>
using namespace std;

void sumofdigit()
{
    int num,sum =0;
    cout << "enter num " ;
    cin >> num;

    while (num !=0)
    {
        int lastdigit =  num %10;
        sum += lastdigit;
        num =  num/10;
    }
    cout<<sum;
}

int main()
{
    sumofdigit();
    return 0;
}
