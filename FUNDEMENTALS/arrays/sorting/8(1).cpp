#include<iostream>
using namespace std;
int main()
{

    int arr[5] = {5,4,3,2,1,0};

for (size_t i = 0; i < 5-1; i++)
{
    int min = i;
    for (size_t j = i+1; j < n; j++)
    {
        if (arr[j] >  arr[j+1] )
        {
            min = j;
        }
        
    }
    
    if (i!= min)
    {
        swap(arr[i] , arr[min]);
    }
    
}

    
    
}