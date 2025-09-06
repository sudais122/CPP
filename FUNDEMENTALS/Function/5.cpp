#include<iostream>
using namespace std;

// Function to check if a number is prime
bool isprime(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;  
    }

    return true;  
}

// Function to print all prime numbers from 1 to n
void printprime()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime numbers from 1 to " << n << " are: ";
    for (int i = 2; i <= n; i++)
    {
        if (isprime(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    printprime();
    return 0;
}
