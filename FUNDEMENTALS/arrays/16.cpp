//array ,ultiplication
#include<iostream>
using namespace std;
int main()
{
int A[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int B[3][2] = {
    {1, 0},
    {0, 1},
    {1, 1}
};

int c[3][2] = {0};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                c[i][j] += A[i][k]*B[k][j];
            }
            
        }
        
    }
    

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            cout <<  c[i][j] << " ";
        }
        cout << endl;
    }
    
}