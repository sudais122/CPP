#include<iostream>
using namespace std;

class book{
    string tittle;
    int price;
public:
    book(string tittle,int price){
        this ->tittle = tittle;
        this ->price = price; 
    }
    void display(){
        cout << "Tittle:"<<" " << tittle <<endl;
        cout << "Price:" <<" " <<price <<endl; 
    }
};
int main() {
    
book b[3] = { book("C++", 200),     
            book("Java", 300),
            book("Python", 250)
             };

             for (int i = 0; i < 3; i++)
             {
                b[i].display();
             }
             
    return 0;
}