//pritnt the main dignol
#include<iostream>
using namespace std;
int main()
{
   int colum=0,row=0;

   cout << "enter number of colum";
   cin>> colum;

    cout << "enter number of row";
    cin>> row;

    int arr[colum][row];

    cout << "enter row"
     for (int i = 0; i < colum; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> arr[i][j];
        }
        cout << "enter " << i+1 << " row";
    }


    bool isidentitiy = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
        if (i==j && arr[i][j] == 1)
        {
            isidentitiy = true;
        }
        else
        {
            isidentitiy =  false;
        }
        }
    }

    if (isidentitiy)
    {
        cout << "it is identity" ;
    }
    else
    {
        cout << "it is not identitiy";
    }
    
}