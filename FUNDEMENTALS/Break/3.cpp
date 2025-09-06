// Keep asking the user to enter numbers.
// Add all the numbers together.
// Stop asking if the user enters -1.
// Then print the total sum (excluding -1).

#include<iostream>
using namespace std;

int main()
{
    int sum = 0,num;
    
    while (true)
    {
        cin >> num;

        if (num == -1)
        {
            break;
        }
          sum +=num;
    }
    cout << sum;
    
 

}