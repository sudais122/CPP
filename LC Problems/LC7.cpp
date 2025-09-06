//mover zeros to the End
#include<iostream>
using namespace std;

void movezeros()
{
    int nums [] = {0, 1, 0, 3, 12};

    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 0)
        {
            nums[i] = nums[i+1];
        }
        else
        {
            cout << nums[i] <<" ";
        }
    }
}
int main() {
    movezeros();

    return 0;
}