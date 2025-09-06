//bubble sorting
#include<iostream>
using namespace std;

int main()
{
    int arr [] = {12,45,34,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "origanal array : ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;

   for (size_t i = 0; i < n-1; i++)
   {
    cout <<  i << "itterration of outer loop that control the passes of n-1" << endl;
        cout << endl;
    for (size_t j = 0; j < n-1-i; j++)
    {
        cout << j << "itteration inner loop " <<  "j= " << j << endl;
            cout << endl;
        cout << " in " << j << "itteration the value of j= " <<  arr[j] << "and j+1 = " <<  arr[j+1] << endl;
        if (arr[j] >  arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
        cout <<  "updated aray after the inner loop " << j << "itteration" << endl;
        
        for (size_t k = 0; k < n; k++)
        {
            cout << arr[k] << " " <<endl;
        }
        cout << endl;
    }
   }
   
   cout <<  endl;
   cout << "sorted array: ";
   for (size_t i = 0; i < n; i++)
   {
    cout << arr[i] <<" ";
   }
   
    
}