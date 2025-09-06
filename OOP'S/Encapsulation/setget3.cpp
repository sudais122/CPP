// private: float temp

// public:

// setTemp(float)

// getTemp() →
// If temp >= 37.5, display “Fever”
// Else display “Normal”

#include<iostream>
using namespace std;

class temperature {
private: 
    float temp;
public:
    void setfloat(int f){
        temp = f;
    }       
    int gettemp(){
        if (temp >= 37.5)
        {
            cout << "Fever\n";
        }
        else
        {
            cout << "Normal\n";
        }
        return temp;
    }           
};
int main() {
    temperature t;
    t.setfloat(55);
    int k = t.gettemp();

    cout << k ;
    return 0;
}