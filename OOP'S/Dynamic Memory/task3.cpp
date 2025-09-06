#include<iostream>
using namespace std;

class Movie {
    int* marks;  // 🧠 Pointer to dynamically allocated marks (stored on heap)

public:
    // 🎯 Constructor - allocates memory and stores the given mark
    Movie(int m) {
        marks = new int;   // Allocate memory on heap
        *marks = m;        // Store value at allocated memory
    }

    // 📋 Display function - shows the value and memory address
    void display() {
        cout << "Marks: " << *marks << " Address: " << marks << endl;
    }

    // 🗑️ Destructor - deletes the allocated memory
    ~Movie() {
        cout << "🗑️ Destructor Called for address: " << marks << endl;
        delete marks;
    }
};

int main() {
    cout << "------1------\n";

    // 🧪 Create original object with value 32
    Movie m1(32);
    m1.display();

    cout << "------2------\n";

    // ⚠️ Create m2 using default shallow copy (danger!)
    Movie m2 = m1;

    // 🔁 Replace m2 with a temporary object
    m2 = Movie(34);  // Temporary object is created and destroyed after assignment

    m2.display();

    return 0;
}
