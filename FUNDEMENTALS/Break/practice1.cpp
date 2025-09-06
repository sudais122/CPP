// Ask the user to enter 10 numbers.
// As soon as an even number is entered, stop asking and print "Even number found".
// If no even number is found, print "No even number".

#include <iostream>
using namespace std;

int main() {

int array[10];

cout <<"enetr 10 values";

for (int i = 0; i < 10; i++)
{
    cin >> array[i];
}

cout << "orignal array";
for (int i = 0; i < 10; i++)
{
    cout << array[i] << " ";
}

cout << endl;

for (int i = 0; i < 10; i++)
{
    cout << array[i] << " ";

    if (array[i] % 2 == 0)
    {
        break;
    }
    
}

    
}

