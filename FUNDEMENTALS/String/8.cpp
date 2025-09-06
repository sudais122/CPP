#include <iostream>
#include <string>
using namespace std;

string makeMessage(string name, double marks) {
    return "hello"  + name + "your marks are"+ " " +to_string(marks);
}

int main() {
    cout << makeMessage("sudais",20);
    return 0;
}
3