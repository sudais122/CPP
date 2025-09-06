#include<iostream>
using namespace std;

class Time
{
    int hr;
    int min;
public:
    Time(int hr,int min)
    {
        this ->hr =hr;
        this -> min = min;
    }

    Time operator+(Time t)
    {
        int titalmin = min + t.min;
        int totalhr = hr + t.hr + (titalmin/60);
        titalmin = titalmin % 60; 
    }

    void display()
    {
        cout << hr <<" hr " << min << " min\n";
    }
};
int main() {
    Time t1(2,50 );
    Time t2(3,80);
    Time t3 = t1+t2;
    t3.display();
    return 0;
}