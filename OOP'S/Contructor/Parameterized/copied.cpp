#include<iostream>
using namespace std;
//copy constructor is the valid exapmle of the deep copy
// 📚 Book class definition
class Book {
    static int countobj;
    string title;
    string author;
    int price;
    int objname;

public:
    // 🎯 Parameterized constructor to initialize book details
    Book(string title, string author, int price, int objname) {
        this->title = title;
        this->author = author;
        this->price = price;
        this -> objname = objname;
        countobj++;
    }

    // 🔁 Copy constructor to create a new Book from an existing one
    Book(Book& obj) {
        title = obj.title;      // Copy the title
        author = obj.author;    // Copy the author
        price = obj.price;
        objname = obj.objname;      // Copy the price
    }

    // 📋 Display function to print book details
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Object Count:" << objname <<"\n";
    }
    ~Book(){
        cout << "Object"<<" "<< objname << " " << "Destroyed\n"; 
    }
};
int Book::countobj = 0;
int main() {
    // 📘 Create original book object
    Book b1("Cpp Mastery", "Sudais", 300,1);
    cout << "📗 Original Book:\n";
    b1.display();

    // 🧾 Create a new book using the copy constructor
    cout << "\n📘 Copied Book:\n";
    Book b2 = b1;
    b2 = Book("java","book",4567,2);
    b2.display();
    
    cout << "\n Next object";
    Book b3 = b2;
    b3 = Book("python","book",43,3);
    b3.display();
    return 0;
}
