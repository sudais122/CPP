#include<iostream>
#include<vector>
using namespace std;

int main() {
    
    vector<int> vct;
    int value;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter value";
        cin >> value;
        vct.push_back(value);
    }
    
    for (int i = 0; i < 3; i++)
    {
        cout << vct[i] <<" ";
    }
    

    vector<int> vct1(5,8);  // print the 5 times 8 like this 5 5 5 5 5 5 5 5

    for (int i = 0; i < 5; i++) {
        cout << vct1[i] << " ";
    }

     vector<int> vct1(5);  // print the 5 times 0 like by default it is initialize to 0

    for (int i = 0; i < 5; i++) {
        cout << vct1[i] << " ";
    }
    

 vector<float> vct3 = {1, 4, 3, 2};  // initialize with 4 floats

    vct3.push_back(45);                // add element at end
    vct3.push_back(8);                 // add another element

    cout << vct3[5];                    // prints the 4th element (value: 2)
    for (int i = 0; i < 6; i++)
    {
        cout << vct3[i]<<" "; //prints the all elements
    }
    

    return 0;
}