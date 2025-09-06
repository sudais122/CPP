#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& num)
{
    for(int x : num){
        cout << x <<" ";
    }
}
int main() {
    vector<int> num;
    int n;

    cout << "enter size of vector";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter " << n << "Element";
        cin >> value;
        num.push_back(value);
    }
    display(num);
    return 0;
}