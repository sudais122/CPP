#include<iostream>
using namespace std;

// 📚 Book class to represent a book's data
class Book {
    string tittle;
    string auther;
    int price;

public:
    // 🎯 Parameterized constructor
    Book(string tittle, string auther, int price) {
        this->tittle = tittle;
        this->auther = auther;
        this->price = price;
    }

    // 🔁 Copy constructor (copies all values from another object)
    Book(const Book& stdnt) {
        tittle = stdnt.tittle;
        auther = stdnt.auther;
        price = stdnt.price;
    }

    // ✍️ Setter for title
    void settittle(string tittle) {
        this->tittle = tittle;
    }

    // ✍️ Setter for author
    void setauther(string auther) {
        this->auther = auther;
    }

    // ✍️ Setter for price
    void setprice(int price) {
        this->price = price;
    }

    // 📤 Getter for title (⚠️ function name should be `gettittle`)
    string settittle() {
        return tittle;
    }

    // 📤 Getter for author (⚠️ function name should be `getauther`)
    string setauther() {
        return auther;
    }

    // 📤 Getter for price (⚠️ function name should be `getprice`)
    int setprice() {
        return price;
    }

    // 📋 Display book details
    void display() {
        cout << "Title: " << tittle << endl;
        cout << "Author: " << auther << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    cout << "📚 Original Book:\n";

    // 🔹 Create original book
    Book b1("Object Oriented Programming", "Muhammad Sudais", 500);
    b1.display();

    cout << "------------------\n";

    // 🔹 Create copy of b1 using copy constructor
    Book b2 = b1;

    // 🔹 Modify copied book using setters
    cout << "📕 Modified Book:\n";
    b2.settittle("OOP in Practice");
    b2.setauther("Sudais M");
    b2.setprice(600);
    b2.display();

    cout << "------------------\n";

    // 🔹 Modify again to simulate second level copy
    cout << "📘 Copied Book:\n";
    b2.settittle("Copy of OOP in Practice");
    b2.display();

    return 0;
}
