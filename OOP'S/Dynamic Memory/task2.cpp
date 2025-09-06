#include<iostream>
using namespace std;

class file
{
    string filename;
    float size;
    static int copycount;
public:
    file(string filename,float size)
    {
        this ->filename =filename;
        this ->size = size;
    }

    file (file& f1)
    {
        filename = f1.filename;
        size = f1.size;
        ++copycount;
    }
    void display(){
        cout << "File Name:" <<" " << filename <<"\n";
        cout << "Size:" <<" " <<size <<"\n";
        cout << "Copy Const Called: "<< " " << copycount <<"\n"; 
    }
};

int file::copycount = 0;
int main() {
    file f("OOP",4.5);
    f.display();

    file f2 =f;
    f2 = file("DSA",4);
    f2.display();
    return 0;
}