#include<iostream>
using namespace std;

void removedupliate()
{
   int nums[] = {1,1,1, 2, 2, 3, 3, 4, 5, 5,5,6,6};

   int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++)
    {
        if (nums[i-1] == nums[i])
        {
            continue;
        }
        else
        {
            cout << nums[i] <<" ";
        }
        
    }
    
}
int main() {
    removedupliate();

    return 0;
}