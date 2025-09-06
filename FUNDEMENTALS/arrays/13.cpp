//addition of 2 array
#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
    {1, 2, 3},
    {4, 4, 8},
    {7, 1, 2}
};

int B[3][3] = {
    {9, 8, 7},
    {6, 5, 4},
    {3, 2, 1}
};

int c[3][3];

cout << "sum of a and b are"<< endl;
for (size_t i = 0; i < 3; i++)
{
    for (size_t j = 0; j < 3; j++)
    {
        c[i][j] = A[i][j] - B[i][j] ;
        cout << c[i][j] << " ";
    }
    cout <<  endl;
}

    return 0;
}
