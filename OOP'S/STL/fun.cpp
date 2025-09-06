#include<iostream>
using namespace std;

int main() {
    vector<int> erasefun = {1,2,3,4,5};

    erasefun.erase(erasefun.begin()+1 , erasefun.begin()+ 4); // values removed betweeb the 1 nad 4 but 4 is excluded
    for(int x : erasefun){
        cout << x <<" ";
    }

    cout << endl;
    vector<int> insertfun = {10,20,40,60};

    insertfun.insert(insertfun.begin(),10); // inser 10 at index 0
    insertfun.insert(insertfun.begin(),3,8); // inser 3 times 8 at index 3 

    for(int x : insertfun){
        cout << x <<" ";
    }

    cout << endl;
    
    insertfun.clear(); // all the elements of the vector
    for(int x : insertfun){
        cout << x <<" ";
    }


    return 0;
}