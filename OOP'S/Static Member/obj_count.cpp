#include<iostream>
using namespace std;

class name{
    static int obj_count;
    int a;
public:
    void counter(int b){
        a = b;
        obj_count++;
        cout << "value of object" <<" "<< obj_count <<" " << " is"<<" " << a <<endl;
    }
    static void display(){
        cout << " Total objects count: " << " " << obj_count <<endl;
        cout << "--------------------------\n";
    }
};

int name::obj_count = 0;
int main() {
    name n1,n2,n3;

    n1.counter(4);
    n2.counter(5);
    n3.counter(6);

    cout << endl;
    
    name :: display();

    return 0;
}