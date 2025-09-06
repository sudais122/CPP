#include<iostream>
using namespace std;

// Function to display array elements and modify size (demonstrating pass by reference)
void fun(int arr[], int &size)   // Passing array by address and size by reference
{
    // Loop runs from index 0 up to (size - 1)
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i];  // Printing each element of the array one by one

        // ❌ Dangerous operation: Modifying size inside the loop
        // This will change the loop limit while the loop is still running
        // Which will cause the loop to run beyond array bounds → Garbage values / crash
        size = 43;  
    }
}

int main()
{
    // Declare and initialize an array of 10 integers
    int array[10] = {1,2,3,4,5,6,7,8,9,10};

    // Declare and initialize the size variable to track array size
    int size = 10;

    // Displaying values from specific positions before calling the function
    cout << "Before function call: ";
    cout << array[2] << " " << array[3] << endl;  // Should print: 3 4
    cout << "Size before: " << size << endl;      // Should print: 10

    // Calling the function → Array passed by reference (address), size passed by reference too
    fun(array, size);

    // Displaying values again after function call
    cout << "\nAfter function call: ";
    cout << array[2] << " " << array[3] << endl;  // Expected to stay same if array not modified
    cout << "Size after: " << size << endl;       // This will now print: 43 (because size was modified inside function)

    // ✅ Expected behavior:
    // → Array values will remain same (since we only printed, didn't modify array)
    // → But size is now changed to 43, because of pass by reference
    // ❌ However: The loop in fun() will have run way beyond valid array limits causing garbage output
}
