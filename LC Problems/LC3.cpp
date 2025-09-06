#include<iostream>
using namespace std;

void max_sum()
{
    int curr_sum1 = 0,curr_sum2 = 0,max_sum = 0;
    int array[] = {5,-2,3,-1,2};

    for (int i = 0; i < 5; i++)

    for (int j = 1; j < 5; j++)

    curr_sum1 = array[i] + array[j];

    for (int k = 0; k < 5; k++)
    for (int l = 1; l < 5; l++)
    for (int m = 2; m < 5; m++)
    
    if (array[m] != 5)
    {
        curr_sum2 = array[k] + array[l] + array[m];
    }
    
    if (max_sum < curr_sum1 && max_sum < curr_sum2)
    {
        if (curr_sum1 > curr_sum2)
        {
            max_sum = curr_sum1;
        }
        else
        {
            max_sum = curr_sum2;
        }
    }
    
    cout << "Max Sum:"<< max_sum<<endl;
    
    
}
int main() {

    max_sum();
    return 0;
}