//multipliation of matrix
#include<iostream>
using namespace std;
int main()
{
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2]= {0};

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    cout << "Array is: ";
    for (int i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            cout << C [i][j] << " ";
        }
        cout << endl;
    }
    
}