//merge 2 array without making new array
#include<iostream>
using namespace std;

void sortedarray()
{
    int num[] = {1,2,3,0,0,0};
    int num1[] = {10,7,8};

   int n = 3;
   int m = 3;

    for (int i = 0; i < m; i++)
    {
        num[n+i] = num1[i];
    }
    
    for (int k = 0; k < n+m; k++)
    {
        cout << num[k] <<" ";
    }
    
}
int main() {
    sortedarray();
    return 0;
}