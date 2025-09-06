#include<iostream>
using namespace std;

class Movie{
    static int count;
    string tittle;
    string genre;
    float rating;
    int objcount;
public:
    Movie(string tittle,string genre,float rating,int objcount)
    {
        this ->tittle = tittle;
        this ->genre = genre;
        this ->rating = rating;
        this ->objcount = objcount;
        count++;
    }

    Movie (Movie& m1)
    {
        tittle = m1.tittle;
        genre = m1.genre;
        rating = m1.rating;
    }

    void display()
    {
        cout << "Tittle:" <<" " <<tittle <<endl;
        cout << "Genre:" <<" " <<genre <<endl;
        cout << "Rating:" <<" " << rating<<endl;
        cout << "Total Object's:"<<" " << count <<"\n";
    }

    ~Movie()
    {
        cout << objcount <<" " << "Destroyed" <<"\n";
    }
};

int Movie::count = 0;
int main() {
    cout <<"------1------\n";
    Movie m1("The toy","horror",4.3,1);
    m1.display();

    cout <<"------2------\n";
    Movie m2 = m1;
    m2 = Movie("Bad Newz","Comedy",3.9,2);
    m2.display();

    cout <<"------3------\n";
    Movie m3 = m2;
    m3= Movie("Damsel","Action",4.6,3);
    m3.display();

    cout <<"-----------------\n";
    return 0;
}