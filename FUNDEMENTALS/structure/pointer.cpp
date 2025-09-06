//function that return array using  pointer
#include <iostream>
using namespace std;

void printarray(int(*arr)[4],int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}
int main() {
 int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printarray(arr,4);
   
}
