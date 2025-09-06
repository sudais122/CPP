// Print only unique elements from the array (remove duplicates).
#include <iostream>
using namespace std;

int main() {
    int original[5] = {10, 10, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        int j;
        for (j = 0; j < i; j++)
        {
            if (original[i] == original[j])
            {
                break;
            }
            
        }
        if (i == j)
        {
            cout << original[i] <<endl;
        }
    }
    
    return 0;
}
