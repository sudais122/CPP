#include<iostream>
using namespace std;

void palindrome()
{
    int  num,orignal,reverse;
    cout << "enter num";
    cin >>  num;

    orignal = num;
  
    while (num !=0)
    {
        int lastdigit = num % 10;
        reverse = reverse * 10 +lastdigit;
        num = num / 10;
    }

    if (reverse == orignal)
    {
        cout <<  orignal << " is a palindorme";
    }
    else
    {
        cout <<  orignal << "it is nor palindrome";
    }
    
    
}

int main()
{
    palindrome();
    return 0;
}
