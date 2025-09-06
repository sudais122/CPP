#include<iostream>
using namespace std;

class A
{
    int a;
    A(int aa)
    {
        aa = a;
    }

    A operator+(A c)
    {
        A obj;
        obj.a = a + c.a;
    }

    void dsipaly()
    {
        cout << "Result:"<<" "<< aa;
    }
};
int main() {                                            
    A aa(3);
    A bb(34);
    A cc = aa+bb;
    dsipaly();
}
