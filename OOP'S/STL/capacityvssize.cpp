#include<iostream>
#include<vector>
using namespace std;

int main() {
    //the simple concept of the capacity is that when the current alocated memory is full then the memory 
    // is grow from its orignal size to double
    vector<int> demo;
    cout << demo.size() <<" " << demo.capacity()<<endl;

    demo.push_back(10);
    cout << demo.size() <<" " << demo.capacity()<<endl;

    demo.push_back(15);
    cout << demo.size() <<" " << demo.capacity()<<endl;

    demo.push_back(20);
    cout << demo.size() <<" " << demo.capacity()<<endl;

    demo.push_back(20);
    cout << demo.size() <<" " << demo.capacity()<<endl;

    demo.push_back(25);
    cout << demo.size() <<" " << demo.capacity()<<endl;

        demo.push_back(27);
    cout << demo.size() <<" " << demo.capacity()<<endl;

        demo.push_back(29);
    cout << demo.size() <<" " << demo.capacity()<<endl;

        demo.push_back(90);
    cout << demo.size() <<" " << demo.capacity()<<endl;

        demo.push_back(25);
    cout << demo.size() <<" " << demo.capacity()<<endl;

        demo.push_back(25);
    cout << demo.size() <<" " << demo.capacity()<<endl;
        demo.push_back(25);

}