#include<iostream>
using namespace std;

class vechiles
{
protected:
    long totalrent;
    int days;
    string Brand;
    int rateperday;
    string cartype;
    int seatingcapicity;
public:
    virtual void input()
    {
        cout << "Enter Brand Name:" <<" ";
        cin >>Brand;
        cout << "Enter Car Type:"<< " ";
        cin >> cartype;
    }

    virtual void calculaterent()
    {
        cout << "Enter Rate per day:"<<" ";
        cin >> rateperday;
        cout << "Enter Total Days:"<<" ";
        cin >> days;

        totalrent = rateperday * days;
    }

    virtual void display()
    {
        cout << "\n";
        cout << "\n";
        cout << "-----Vechile info-----\n";
        cout <<"Brand: " << Brand <<endl;
        cout << "Car Type: " <<cartype <<endl;
        cout << "Total Rent: " <<totalrent <<endl;
    }
};

class car : public vechiles
{
public:
    void inputbike()
    {
        cout << "Enter Brand Name:" <<" ";
        cin >>Brand;
        cout << "Enter Car Type:"<< " ";
        cin >> cartype;
    }

    void calculaterent()
    {
        cout << "Enter Rate per day:"<<" ";
        cin >> rateperday;
        cout << "Enter Total Days:"<<" ";
        cin >> days;

        totalrent = rateperday * days;
    }

    void display()
    {
        cout << "\n";
        cout << "\n";
        cout << "-----Vechile info-----\n";
        cout <<"Brand: " << Brand <<endl;
        cout << "Car Type: " <<cartype <<endl;
        cout << "Total Rent: " <<totalrent <<endl;
    }
};


class bike : public vechiles
{
public:
    void input()
    {
        cout << "Enter Brand Name:" <<" ";
        cin >>Brand;
        cout << "Enter Car Type:"<< " ";
        cin >> cartype;
    }

    void calculaterent()
    {
        cout << "Enter Rate per day:"<<" ";
        cin >> rateperday;
        cout << "Enter Total Days:"<<" ";
        cin >> days;

        totalrent = rateperday * days;
    }

    void display()
    {
        cout << "\n";
        cout << "\n";
        cout << "-----Vechile info-----\n";
        cout <<"Brand: " << Brand <<endl;
        cout << "Car Type: " <<cartype <<endl;
        cout << "Total Rent: " <<totalrent <<endl;
    }
};


class Bus :public vechiles
{
public:
    void inputbike()
    {
        cout << "Enter Brand Name:" <<" ";
        cin >>Brand;
        cout << "Enter Car Type:"<< " ";
        cin >> cartype;
        cout << "Enter seting capicity: " <<" ";
        cin >> seatingcapicity;
    }

    void calculaterent()
    {
        cout << "Enter Rate per day:"<<" ";
        cin >> rateperday;
        cout << "Enter Total Days:"<<" ";
        cin >> days;
        cout << "Seating Capicity: " <<" ";
        cin >> seatingcapicity;

        totalrent = rateperday * days;
    }

    void display()
    {
        cout << "\n";
        cout << "\n";
        cout << "-----Vechile info-----\n";
        cout <<"Brand: " << Brand <<endl;
        cout << "Car Type: " <<cartype <<endl;
        cout << "Total Rent: " <<totalrent <<endl;
        cout << "Seating capicity: " <<seatingcapicity <<endl;
    }
};
int main() {
    vechiles*ptr;
    int choice;

    cout << "1.Car\n";
    cout << "2.Bike\n";
    cout << "3.Bus\n";
    cout << "4.Exit\n";

    cout << "Enter Choice: ";
    cin >>choice;

    switch (choice)
    {
    case 1:
    {
    car c;
        ptr = &c;
        ptr->input();
        ptr->calculaterent();
        ptr->display();
    }
        break;
    case 2:
    {
    bike b;
        ptr = &b;
        ptr->input();
        ptr->calculaterent();
        ptr->display();
    }
    break;
    case 3:
    {
        Bus B;
        ptr = &B;
        ptr->input();
        ptr->calculaterent();
        ptr->display();
    }
    break;
    case 4:
        cout << "Good Bye\n";
    }
    return 0;
}