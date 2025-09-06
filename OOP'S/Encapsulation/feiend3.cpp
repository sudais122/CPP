// Create a class Car with a private price.

// Make a friend function discount(Car c) that changes the price to 90% of the original.

// Show price before and after calling the function.
#include<iostream>
using namespace std;

class car{
    int speed;
public:
    void setvalur(int p){
        speed = p;
    }
    friend void discount(car c);
};

void discount(car c){
    int increse  = c.speed + 100;
    cout << "new speed: " <<" " << increse <<endl;
}
int main() {
    car c1;
    c1.setvalur(50);

    discount(c1);
    return 0;
}