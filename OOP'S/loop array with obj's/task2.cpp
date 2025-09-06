#include<iostream>
using namespace std;

class movie{
    string Name;
    float rating;
public:
    void setdata(string Name,int rating)
    {
        this ->Name =  Name;
        this ->rating = rating;
    }

    void show(){
        cout << "Name:"<<" "<< Name<<"\n";
        cout << "Rating:"<<" " <<rating << "\n";
    }
};
int main() {
    movie m[3];
    string name;
    int RATING;


    for (int i = 0; i < 3; i++)
    {
        cout <<"------Deatils-------\n"; 
        cout << "Enter movie name";
        cin >> name;
        cout << "Enter Rating";
        cin >> RATING;
        m[i].setdata(name,RATING);        
    }
    

    for (int i = 0; i < 3; i++)
    {
        cout <<"------Deatils-------\n"; 
        m[i].show();
    }
    

    return 0;
}