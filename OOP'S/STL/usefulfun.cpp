#include<iostream>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6};

    v.push_back(5); // add 5 after 6 means add elemt to the last
    for (int i = 0; i < 7; i++)
    {
        cout << v[i]<<" ";
    }
    cout << endl;
    cout << v.front()<<" "<<v.back()<<endl; //frot print the lst element and back print the last element

    cout << endl;
    v.pop_back(); //remove the last element
    for (int i = 0; i < 7; i++)
    {
        cout << v[i]<<" ";
    }
    cout << endl;
    cout << v.front() <<" " <<v.back();
    // front to get the ist element 
    // back is used to get the last element
    return 0;
}