#include<iostream>
using namespace std;

void arrfun(int arr[3][4],int rows,int coloms)
{
    int sum =0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < coloms; j++)
        {
            cin >>arr[i][j] ;
        }
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < coloms; j++)
        {
            cout << arr[i][j]<< " ";
        }
        cout<<endl;
    }

    cout <<"sum is: " << sum <<endl;
}
int main()
{
    int row=3,colom=4;

    int array[3][4];

    arrfun(array,row,colom);
}