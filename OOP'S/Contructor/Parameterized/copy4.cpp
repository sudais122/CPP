#include<iostream>
using namespace std;

class Book{
    string Title;
    string Author;
    int Price;
public:
    Book(string Title,string Author,int Price)
    {
        this -> Title = Title;
        this -> Author = Author;
        this -> Price = Price; 
    }

    Book (const Book& b1)
    {
        Title = b1.Title;
        Author = b1.Author;
        Price = b1.Price;
    }

    void setprice(int Price)
    {
        this ->Price = Price;
    }

    int getprice(){
        return Price;
    }

    void Display(){
        cout << "Tittle:"<<" " <<Title <<endl;
        cout << "Auther:"<<" " <<Author <<endl;
        cout << "Price:" <<" " <<Price <<endl;
    }
};
int main() {
    Book b1("DSA,John" ,"Smith",750);
    b1.Display();

    Book b2 = b1;
    cout <<"------------\n";
    b2.setprice(700);
    b2.getprice();
    b2.Display();
    return 0;
}