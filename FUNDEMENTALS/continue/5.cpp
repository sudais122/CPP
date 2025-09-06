#include<iostream>
using namespace std;
int main()
{
    int squar[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++)
    {
        if (squar[i] == 7 || squar[i] == 5)
        {
            continue;
        }
        cout << squar[i]*squar[i] << " ";
    }
    
}