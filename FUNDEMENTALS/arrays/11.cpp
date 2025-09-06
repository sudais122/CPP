//delet elment from the array
#include<iostream>
using namespace std;
int main()
{
    int num[5] = {1,2,3,4,5};

    int pos,size;
    size = 5;

    cout << "enter the position";
    cin >> pos;

    for (size_t i = pos; i < size-1; i++)
    {
        num[i] = num[i+1];
    }

    size--;

    for (int i = 0; i < size; i++)
    {
        cout << num[i] << " " ;
    }
    
    
    
}