#include<iostream>
using namespace std;
// Define a class named Mobile

// Add public members:

// brand (string)

// model (string)

// price (int)

// Create an object of Mobile named mobile1

// Assign values and display them using a function
class mobile{
    public:
    string brand;
    string model;
    int price;

    void display()
    {
        cout << "brand: " <<" " << brand<<endl;
        cout << "model: " <<" " << model <<endl;
        cout << "price: " <<" " << price<<endl;
    }
};

int main()
{
    mobile mobile1;
    
    mobile1.brand= "IPHONE";
    mobile1.model = "14 pro max";
    mobile1.price = 203000;
    mobile1.display();
}