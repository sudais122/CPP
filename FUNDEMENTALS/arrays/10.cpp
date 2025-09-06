//replace value in 2d array
#include<iostream>
using namespace std;

int main()
{
   int arr[4][4] = {
                    {1,2,3,4},
                    {4,5,6,3},
                    {7,8,9,43},
                    {10,11,12,3}
   };

   int row,col,num;
      cout << "enter the position";
      cin >> row >>  col ; 

      cout << "enter  value";
      cin >> num ;
      if (row >= 0 && row <= 4 && col >= 0 && col <= 4)
      {
         arr[row][col] = num;
      }
      
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            cout << arr[i][j] <<" ";
         }
         cout << endl;
      }
      
   }
