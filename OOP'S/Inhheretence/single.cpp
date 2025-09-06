#include<iostream>
using namespace std;

// Base class
class Vehicle {
public:
    void start() {
        cout << "Vehicle started" << endl;
    }

    void stop() {
        cout << "Vehicle stopped" << endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    void playMusic() {
        cout << "Playing music in Car" << endl;
    }
};

int main() {
    Car c;
    c.start();       // Inherited from Vehicle
    c.playMusic();   // Car's own function

    return 0;
}
