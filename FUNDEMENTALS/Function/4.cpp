#include<iostream>
using namespace std;

void prime()
{
    int num;
    bool isprime = true;



    cout << "enter value";
    cin >> num;

    if (num <=1 )
    {
        isprime = false;
    }
    else
    {
        for (int i = 2; i <= num/2; i++)
        {
            if (num % i == 0)
            {
                isprime = false;
            }
        }
    }

    if (isprime)
    {
        cout << "it is a prime number";
    }
    else
    {
        cout << "it is not a prime number";
    }
    
    
}
int main()
{
    prime();
}