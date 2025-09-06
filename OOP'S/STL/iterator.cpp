#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main() {
    
    vector<int> v = {1,2,4,3,5,7,};

    v.push_back(7);

    list <int> l; 

    l.push_front(7);
    l.push_back(9);
    l.push_front(0);

    for (auto j = l.begin(); j != l.end(); j++)
    {
        cout << *(j)<<" ";
    }
    cout <<endl;
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        cout << *(i) <<" ";
    }
    
    return 0;
}