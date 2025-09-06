#include<iostream>
using namespace std;

class laptop{
private:
    string Brand;
    int price;
    int ram_in_GB;
public:
    laptop(){
        Brand = "Unknown";
        price = 0;
        ram_in_GB = 0;
    }
    laptop(string b){
        Brand = b;
        price = 0;
        ram_in_GB = 0;
    }
    laptop(string b,int p){
        Brand = b;
        price = p;
        ram_in_GB = 0;
    }    
    laptop(string b,int p,int r){
        Brand = b;
        price = p;
        ram_in_GB = r;
    }
    void display();
};

void laptop::display(){
    cout << "Brand:" <<" " << Brand <<endl;
    cout << "Price: " <<" " << price << endl;
    cout << "Ram:" <<" " << ram_in_GB << "GB" <<endl;
    cout << "----------------------------------\n"; 
    }
int main()
{
    laptop l1;
    l1.display();

    laptop l2("Dell");
    l2.display();

    laptop l3("Lenove",85000);
    l3.display();

    laptop l4("Apple",200000,16);
    l4.display();
}