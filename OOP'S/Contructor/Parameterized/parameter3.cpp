// Class: Book

// Private: ISBN

// Public: title, author

// Use:

// Default constructor sets title = "Untitled", author = "Unknown"

// Parameterized constructor allows custom book info

// Display book details with a function

#include<iostream>
using namespace std;

class book{
private:
    int ISBN;
public:
    string tittle;
    string auther;
public:
    book(int ISB,string tittl = "Untitled",string ather ="Unknown"){
        ISBN = ISB;
        tittle = tittl;
        auther = ather;
    }
    void dispay();
};
void book:: dispay(){
        cout << "ISBN:" <<" " << ISBN <<endl;
        cout << "Tittle:" <<" " << tittle <<endl;
        cout << "Auther:" <<" " << auther <<endl;
}
int main()
{
    book b1(34);
    b1.dispay();

    book b2(35634,"cpp programing","sudais");
    b2.dispay();
}