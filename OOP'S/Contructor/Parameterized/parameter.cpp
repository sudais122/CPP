// Create a class `Student` that has:

// * private `roll`, public `name`
// * parameterized constructor to set both
// * display function
//   Create 2 objects with different values.
#include<iostream>
using namespace std;

class student{
private:
    int rollno;
    string name;
public:
  student(int n,string a){
        rollno = n;
        name = a;
        cout << "Name: " << " " << n <<endl;
        cout << "Age: " << " " << a <<endl;
  }
};
int main()
{
    student s1(23,"sudais");
    student s2(23,"khan");
}