#include<iostream>
using namespace std;

void rotate()
{
    int nums[] = {1,2,3,4,5,6,7};

    int n =6;

    for (int i = n; i >= 0; i--)
    {
        cout << nums[i] << " ";
    }

    cout << "Second rotation" <<endl;
    for (int i = 2; i >= 0; i--)
    {
        cout << nums[i] <<" ";
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] <<" ";
    }
    
    
    

//Rotate by 1 → [7,1,2,3,4,5,6]

// Rotate by 2 → [6,7,1,2,3,4,5]

// Rotate by 3 → [5,6,7,1,2,3,4]
    
}
int main() {
    rotate();
}