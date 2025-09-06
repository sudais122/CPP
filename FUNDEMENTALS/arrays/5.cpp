//Reverse the array (e.g., [1, 2, 3] → [3, 2, 1]).
#include<iostream>
using namespace std;

int main()
{
     int arr2D[3][3] = {
    {4, 8, 6},
    {3, 9, 1},
    {7, 2, 5}
};

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
         cout << arr2D[j][i] << " ";
    }
    cout << endl;   
}
}