#include<iostream>
using namespace std; 
int min()
{
    //As soon as the number -1 is entered, stop the loop and print how many numbers were entered before it.
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];

        if (arr[i] == -1)
        {
            break;
        }
        else
        {
            cout << "user enter the " << i <<  "numbers" << endl;
        }
    }
}