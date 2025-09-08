#include<iostream>
using namespace std;

void majoreleme()
{
   int arr[] = {2, 2, 1, 3, 2, 1}, n = 6;   

   for (int i = 0; i < n; i++) // loop through all th element of the array
   {
        int count = 1;
        bool visited = false;
        int majorelem;

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
            cout << "Major Element is" << majorelem <<endl;
            break;

        }
   }
   
}
int main() {
    majoreleme();
    return 0;
}