//Calculate the average of elements in an array.
#include<iostream>
using namespace std;

int main()
{
     int arr2D[3][3] = {
    {4, 8, 6},
    {3, 9, 1},
    {7, 2, 5}
};
    int sum =0,average = 0;

for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
          sum +=arr2D[i][j];
          average = sum /9;
        }
    }

    cout << "Average is: " << average << endl;
}