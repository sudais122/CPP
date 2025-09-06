// equirements:
// Class: Mobile

// Data: brand, model, price

// One constructor with default price = 0

// One constructor with full details (brand, model, price)

// Show details of two mobiles: one using default price, one using custom price
#include<iostream>
using namespace std;
class mobile{
private:
    string brand;
    int model;
    int price;
public:
    //constructor
    mobile(string brnd, int mdel, int prce = 0){
        brand = brnd;
        model = mdel;
        price = prce;
    }
    //getter
    void display();

    //
    int varname(){
        return price;
    }
};
void mobile::display(){
        cout << "Brand: " << brand <<endl;
        cout << "model: " << model<<endl;
        cout << "price: " << price <<endl;
}
int main()
{
    mobile m("oppo",34);
    m.display();
    mobile m1("vivo",340,90000);
    m1.display();
}