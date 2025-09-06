// Class: Car

// Data members: string brand, int year

// In default constructor:

// Set brand = "Unknown", year = 2000

// Print both values

// Create 2 objects

#include<iostream>
using namespace std;

class car{
public:
    string brand;
    int year;
    car(){
        brand = "Bogatee";
        year = 2024;
        cout << " Brand" <<" "<< brand << endl;
        cout << "year" <<" " << year <<endl;
    }
};
int main()
{
    car c1;
    car c2;
}