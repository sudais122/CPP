// sum of row and colum in matrix
#include<iostream>
using namespace std;
int main()
{
    int arr[3][3] = {
        {12,4,3},
        {34,3,3},
        {34,32,2}
    };

    for (size_t i = 0; i < 3; i++)
    {
        int rowsum = 0;
        for (size_t j = 0; j < 3; j++)
        {
            rowsum += arr[i][j];
        }
        cout << "sum of row" << i << ":" << rowsum << endl;
    }
    
    for (size_t j = 0; j < 3; j++)
    {
        int colsum = 0;
        for (size_t i = 0; i < 3; i++)
        {
            colsum += arr[j][i];
        }
        cout << "sum of colum" << j << ":" << colsum << endl;
    }
}