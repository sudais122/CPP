/* 
Problem:
Store data of 5 books using a structure Book, with fields:
Book ID
Title
Author name
Then:
Take input for all books
Ask user to enter an author name or book tittle or book id
Search and display all books written by that author.*/
#include<iostream>
using namespace std;

struct  book
{
    int bookID;
    string tittle;
    string Auther_name;
}bookdetail;

int main()
{
book bookdetail[5] = {
    {101, "C++ Programming", "Bjarne Stroustrup"},
    {102, "The Alchemist", "Paulo Coelho"},
    {103, "Clean Code", "Robert C. Martin"},
    {104, "Harry Potter", "J.K. Rowling"},
    {105, "Introduction to Algorithms", "Thomas H. Cormen"}
};

    cout << "search Book"<<endl;
    cout << "1.Search by Auther Nama" <<endl;
    cout << "2.Search by Book Tittle" <<endl;
    cout << "3.Search by Book ID" <<endl;
    cout << "________________________________" <<endl;

    int choice;
    cout << "enter choice";
    cin >>choice;

    string authername,bookname;
    int bookid;

    if (choice == 1)
    {
    cout << "Enter auther name: " <<" ";
    getline(cin,authername);
        for (int i = 0; i < 5; i++)
    {
    if (authername == bookdetail[i]. Auther_name)
    {
        cout <<"Book ID: "<<" "<< bookdetail[i].bookID <<endl;
        cout << "Tittale: "<<" " <<bookdetail[i].Auther_name <<endl;
        cout << "Auther Name: " <<" "<< bookdetail[i].tittle <<endl;
    }
    }
    }


    if (choice == 2)
    cout << "Enter book tittle: " <<" ";
    getline(cin,bookname);
    {
        for (int i = 0; i < 5; i++)
    {
    if (bookname == bookdetail[i].tittle)
    {
        cout <<"Book ID: "<<" "<< bookdetail[i].bookID <<endl;
        cout << "Tittale: "<<" " <<bookdetail[i].Auther_name <<endl;
        cout << "Auther Name: " <<" "<< bookdetail[i].tittle <<endl;
    }
    }
    }


    if (choice == 3)
    cout << "Enter bookid: " <<" ";
    cin >>bookid;
    {
        for (int i = 0; i < 5; i++)
    {
    if (bookid == bookdetail[i].bookID)
    {
        cout <<"Book ID: "<<" "<< bookdetail[i].bookID <<endl;
        cout << "Tittale: "<<" " <<bookdetail[i].Auther_name <<endl;
        cout << "Auther Name: " <<" "<< bookdetail[i].tittle <<endl;
    }
    }
    }
}