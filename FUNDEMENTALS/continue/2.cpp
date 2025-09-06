#include<iostream>
using namespace std;
int main()
{
    int arr[7] = {12, 134, 45, 6, 145, 67, 3};

    for (int i = 0; i < 7; i++)
    {
        if (arr[i] > 100)
        {
            continue;
        }
        cout << arr[i] << " ";
    }
    
}