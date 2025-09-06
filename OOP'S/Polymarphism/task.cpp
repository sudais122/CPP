#include<iostream>
using namespace std;

class point2D
{
    int x,y;
public:
    point2D(int x,int y)
    {
        this->x = x;
        this -> y = y;
    }

    point2D operator+(point2D p)
    {
        return point2D(x + p.x,y+p.y);
    }

    void dispaly()
    {
        cout << "(" << x << "," <<y << ")\n";
    }
};
int main() {
    point2D p1(2, 3), p2(4, 5);
    point2D p3 = p1 + p2;  
    p3.dispaly();

}
