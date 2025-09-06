// /Copy one array into another (without using the same variable).
#include <iostream>
using namespace std;

int main() {
    // Original array
    int original[5] = {10, 20, 30, 40, 50};

    int copy[5];

    for (int i = 0; i < 5; i++)
    {
        copy[i] =  original[i];
    }
    
    cout << "copied elemnt in array are";
    for (int i = 0; i < 5; i++)
    {
        cout << copy[i] <<" ";
    }
    
}
