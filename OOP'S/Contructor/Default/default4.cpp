#include <iostream>
using namespace std;

class A {
public:
    int x;
  
  	// Parameterized constructor
  	A(int val) {
      	x = val;
      cout << x;
    }
};

int main() {
  
  	// Creating object and calling parameterized constructor
    A a(10);
    
    return 0;
}