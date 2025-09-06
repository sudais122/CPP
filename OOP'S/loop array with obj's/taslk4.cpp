#include<iostream>
using namespace std;

class File {
    static int count;  // shared across all objects
    int id;            // unique ID for each object

public:
    // Constructor assigns unique ID and prints creation
    File() {
        count++;
        id = count;
        cout << "✅ Object " << id << " created\n";
    }

    // Destructor prints destruction message
    ~File() {
        cout << "🗑️ Object " << id << " destroyed\n";
    }
};

// Initialize static member outside the class
int File::count = 0;

int main() {
    File f[3];  // 🔁 Creates 3 objects: f[0], f[1], f[2]
    return 0;
}
