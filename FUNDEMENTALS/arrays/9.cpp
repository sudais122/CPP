//insert element in array
#include<iostream>
using namespace std;
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9};

    int pos,num;

    cout << "enter the position";
    cin >> pos;

    cout << "enter the number";
    cin >> num;

    for (int i =8; i >= pos; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos] =  num;
 
    for (size_t i = 0; i < 10; i++)
    {
        cout << arr[i] <<" ";
    }
}