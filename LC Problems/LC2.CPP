#include<iostream>
using namespace std;

int main()
{
    int current_profit = 0,max_profit = 0;
    int array[] = {7,6,4,3,1};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            current_profit = array[j] - array[i];

            if (current_profit > 0)
            {
                if (current_profit > max_profit  )
                {
                    max_profit = current_profit;
                }
            }

        }
    }
    cout << "Max Profit: " << max_profit << endl;
    
    return 0;
}