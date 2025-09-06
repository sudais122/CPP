//earch for an element in the array and print its index (if found).
#include<iostream>
using namespace std;

int main()
{
     int arr2D[3][3] = {
    {4, 8, 6},
    {3, 9, 1},
    {7, 2, 5}
};

int found,i,j;

bool isfind=  false;

cout << "enter value";
cin >> found;

for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
         if (found == arr2D[i][j])
         {
            cout << "value found at indec" << i << j <<endl;
            isfind =  true;
            break;
         }
        }
    }
}