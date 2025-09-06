// Given an array of numbers and a target number, find two numbers in the array that add up to the target.
// Example: nums = [2,7,11,15], target = 9 → Output: [0,1] (because nums[0]+nums[1] = 9).
#include<iostream>
using namespace std;

int main() {
    int array[] = {5,8,12,7,3}, target = 15;

    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (array[i] + array[j] == target)
            {
                cout << "[" << j <<"," << i << "]" <<endl;
            }
        }
    }
    
    return 0;
}