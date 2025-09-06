// // Data members (all private):

// // accountNumber (int)

// // balance (int)

// // Public member functions:

// // setData() → to set both values

// // display() → to print the values

// // In main():

// // Create one object

// // Use setData() to assign values

// // Call display() to show the output

// #include<iostream>
// using namespace std;

// class account{
// private:
//     int balance;
//     int accountnumber;
// public:
//     void setdata(int x,int y){
//         balance = x;
//         accountnumber = y;
//     }
//     void display(){
//         cout << "Balance: "<< " " << balance <<endl;
//         cout << "Account number: "<< " " << accountnumber <<endl;
//     }
// };
// int main()
// {
//     account account1;

//     int a,b;

//     cout << "Enter balance";
//     cin >> a;
//     cout << "Enter Account number: ";
//     cin >> b;
//     account1.setdata(a,b);
//     account1.display();
// }


// * Making a class `Student`
// * Private members: `rollNo`, `marks`
// * Public methods: `setData()`, `getData()` (with conditions like marks should not be negative)
// * Show how it protects invalid data

#include<iostream>
using namespace std;
class student {
    int rollno;
    int marks;
public:
    void setData(int r, int m){
        rollno = r;
        marks = m;
    }

    int getData(){
        if (marks < 0)
            cout << "Invalid marks\n";
        else
            cout << "Roll No " <<" " <<rollno <<endl;
            cout << "MArks" <<" " << marks <<endl;
    }
};l

int main() {

    return 0;
}