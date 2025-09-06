//pritnt the main dignol
#include<iostream>
using namespace std;
int main()
{
    int arr[3][3] = {
        {1,23,3},
        {03,3,3},
        {02,03,1}
    };
    int sum =0,diagnol=0;

     cout <<  " diagnol element are: "<<endl ;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i==j)
            {
                cout << arr[i][j] <<" ";
                sum += arr[i][j];
            }
            
        }
    }
    cout <<  "sum of diagnol: " << sum <<endl;

    
}