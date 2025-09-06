// Try making a class called Mobile with these constructors:

// Default: sets brand to "Unknown" and price 0

// 1 parameter: brand

// 2 parameters: brand + price

// Display function to show mobile details
#include<iostream>
using namespace std;

class mobile{
    string brand;
    int price;
public:
    mobile(){
        brand  = "unknown";
        price = 0;
    }
    mobile(string b,int p){
        brand = b;
        price = p;
    }
    void displat();
};

void mobile::displat(){
    cout << "Brand: " <<" " << brand <<endl;
    cout << "Price: " <<" " << price <<endl;
}
int main()
{
    mobile m1;
    m1.displat();

    mobile m2("iphone",120000);
    m2.displat();
}