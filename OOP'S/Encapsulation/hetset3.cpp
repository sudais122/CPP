// private: int speed

// public:

// setSpeed(int) → speed must be between 0–200.

// getSpeed() →
// If speed > 120 → “Over Speeding”
// Else → “Normal Driving”
#include<iostream>
using namespace std;

class student {
private: 
    int speed;         
public:
    void setspeed(int s){
        speed = s;
    }

    int geetspeed(){
        if (speed  > 120)
        {
            cout << "over speeding" <<endl;
        }
        else
        {
            cout  << "normal driving" <<endl;
        }
        return speed;
    }                 
};
int main() {
    student s1;
    s1.setspeed(121);
    int x =  s1.geetspeed();
    cout << x;
    return 0;
}