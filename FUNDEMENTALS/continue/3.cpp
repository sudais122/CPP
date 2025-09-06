#include<iostream>
using namespace std;
int main()
{
    int i=0;
    int num[5];

    while (i < 5)
    {
        cin >> num[i];
            if (num[i] < 0)
            {
                continue;
            }
        i++;
    }

    for (int j = 0; j < 5; j++)
    {
        cout << num[j] << " ";
    }
    
    
}