//merge 2 array by making new array
#include<iostream>
using namespace std;

void mergearray()
{
    int array[] = {12,423,312,1};
    int array2[] = {23,4,231,124};

    int n =4;
    int m = 4;

    int merged[n + m];
 
    for (int i = 0; i < n; i++)
    {
        merged[i] = array[i];
    }
    
    for (int j = 0; j < m; j++)
    {
        merged[n + j] = array2[j];
    }

    for (int k = 0; k < n + m; k++)
    {
        cout << merged [k] <<" ";
    }
    
}
int main() {
    mergearray();

    return 0;
}