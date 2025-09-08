#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 3, 4, 3, 5, 3, 3};
    int n = 7;
    int majorelem;  

    for (int i = 0; i < n; i++) // loop through all th element of the array
    {
        int count = 1;
        bool visited = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j]) // if the element is already visited or count it skip it 
            {
                visited = true;
                break;
            }
        }

        if(visited) continue;  // if the element is already count then skip it 

        for (int k = i+1; k < n; k++) // it compare the urrent element to all the lement if the.
        {
            if (arr[i] == arr[k])
            {
                count++;
            }
        }

        if (count > n/2)
        {
            majorelem = arr[i];
            cout << "Major Element is " << majorelem << endl;
            break;
        }
    }
}
