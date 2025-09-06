//Count how many even and odd numbers are in the array.
#include<iostream>
using namespace std;

int main()
{
    int arr2D[3][3] = {
    {4, 8, 6},
    {3, 9, 1},
    {7, 2, 5}
};
    int oddcount=0,evencount=0;
 for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr2D[i][j] % 2 == 0)
            {
                evencount++;
            }
            else
            {
                oddcount++;
            }
        }
    }

    cout << "Number of Even in array" << evencount <<  endl;
    cout << "Number of Odd in array" << oddcount <<  endl;

}