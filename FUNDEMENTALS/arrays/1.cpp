//Find the maximum and minimum element in a 1D array.
#include<iostream>
using namespace  std;

int main()
{
    int arr2D[3][3] = {
    {4, 8, 6},
    {3, 9, 1},
    {7, 2, 5}
};


    int max = arr2D[0][0];
    int min =  arr2D[0][0];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr2D[i][j] >  max)
            {
                max =  arr2D[i][j];
            }
        }
    }
    cout << "max is " << max <<endl;

    //find min
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr2D[i][j] <  min)
            {
                min =  arr2D[i][j];
            }
        }
    }
     cout << "max is " << min <<endl;

}