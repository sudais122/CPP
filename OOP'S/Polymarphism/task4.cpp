
// Create a base class `Shape` with a virtual function `area()` and `display()`.
// Then create 2 derived classes: `Rectangle` and `Circle`.
// Use **base class pointers** to call the `area()` and `display()` functions.

#include<iostream>
using namespace std;

class Shape
{
    float area;
public:
    virtual void area1(int area)
    {
        this -> area = area;
    }

    void display()
    {
        cout << "Area: " << " " << area <<"\n";
    }
};

class Rectangle : public Shape
{
    int length;
    int width;
public:
    void area1(int length,int width)
    {
        this -> length = length;
        this -> width = width;
    }

    void display()
    {
        cout << "Rectangle Length: " <<length << "," << "Width: " << width << "\n";   
    }
};

class circle : public Shape
{
    float area;
public:
    void area1(int area)
    {
        this -> area = area;
    }

    void display()
    {
        cout << "Area of circle : " << area << "\n";
    }
};

int main() {
    Shape *shp;
  

    Shape shp1;
    shp = &shp1;
    shp1.area1(34);
    shp1.display();

    Rectangle r;
    shp = &r;
    r.area1(12,4);
    r.display();

    circle c;
    shp = &c;
    c.area1(43.4);
    c.display();
    return 0;
}