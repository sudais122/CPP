#include<iostream>
using namespace std;
const int MAX = 100;

// Function to input and display a 1D array
void inputarray(int arr[], int size) {
    cout << "Enter array Elements: \n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Array: \n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

// Calculate mean of array elements
void calculatemean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    float mean = float(sum) / size;
    cout << "Mean is: " << mean << endl;
}

// Calculate median of array elements (requires sorting in general)
void calculatemedian(int arr[], int size) {
    if (size % 2 == 1) {
        cout << "Middle value: " << arr[size / 2] << endl;
    } else {
        double middle = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        cout << "Middle value (average of two): " << middle << endl;
    }
}

// Calculate average of array elements
void calculateaverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    float average = float(sum) / size;
    cout << "Average: " << average << endl;
}

// Find maximum value in array
void findmax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "Maximum value is: " << max << endl;
}

// Find minimum value in array
void findmin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Minimum value is: " << min << endl;
}

// Search for a specific value in array
void findelement(int arr[], int size) {
    int search;
    cout << "Enter value to search: ";
    cin >> search;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == search) {
            found = true;
            break;
        }
    }
    cout << (found ? "Value found" : "Value not found") << endl;
}

// Input and display 2D array
void inputAndDisplay2DArray(int array2d[MAX][MAX], int rows, int columns) {
    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> array2d[i][j];
        }
    }
    cout << "\n2D Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << array2d[i][j] << " ";
        }
        cout << endl;
    }
}

// Calculate mean of 2D array
void calculatemean2d(int arr2d[MAX][MAX], int row, int column) {
    int sum = 0, count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            sum += arr2d[i][j];
            count++;
        }
    }
    float mean = static_cast<float>(sum) / count;
    cout << "Mean is: " << mean << endl;
}

// Calculate average of 2D array
void average2d(int arr2d[MAX][MAX], int row, int column) {
    int sum = 0, count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            sum += arr2d[i][j];
            count++;
        }
    }
    float average = static_cast<float>(sum) / count;
    cout << "Average: " << average << endl;
}

// Find maximum in 2D array
void findmax2d(int arr2d[MAX][MAX], int row, int column) {
    int max = arr2d[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (arr2d[i][j] > max) {
                max = arr2d[i][j];
            }
        }
    }
    cout << "Maximum value: " << max << endl;
}

// Find minimum in 2D array
void findmin2d(int arr2d[MAX][MAX], int row, int column) {
    int min = arr2d[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (arr2d[i][j] < min) {
                min = arr2d[i][j];
            }
        }
    }
    cout << "Minimum value: " << min << endl;
}

// Search value in 2D array
void search2darray(int arr2d[MAX][MAX], int row, int column) {
    int search;
    cout << "Enter value to search: ";
    cin >> search;
    bool found = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (arr2d[i][j] == search) {
                found = true;
                break;
            }
        }
    }
    cout << (found ? "Value found" : "Value not found") << endl;
}

// Transpose a 2D array
void transpose(int arr2d[MAX][MAX], int row, int column) {
    cout << "Transpose of matrix: \n";
    for (int j = 0; j < column; j++) {
        for (int i = 0; i < row; i++) {
            cout << arr2d[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "1. Input Array\n2. Input 2D Array\n3. Exit\n";
    int arraytypeinput;
    cout << "Enter choice: ";
    cin >> arraytypeinput;

    if (arraytypeinput == 1) {
        // 1D array operations
        int size;
        cout << "Enter size: ";
        cin >> size;
        int array[size];
        inputarray(array, size);

        cout << "------Array Operations-------\n";
        cout << "1. Calculate Mean\n2. Calculate Median\n3. Calculate Average\n4. Find Maximum\n5. Find Minimum\n6. Search Element\n7. Exit\n";

        int arrayoperation;
        cout << "Enter Choice: ";
        cin >> arrayoperation;

        switch (arrayoperation) {
        case 1:
            calculatemean(array, size);
            break;
        case 2:
            calculatemedian(array, size);
            break;
        case 3:
            calculateaverage(array, size);
            break;
        case 4:
            findmax(array, size);
            break;
        case 5:
            findmin(array, size);
            break;
        case 6:
            findelement(array, size);
            break;
        case 7:
            cout << "Exit Good Bye!";
            break;
        default:
            cout << "Error: 404";
            break;
        }
    } else if (arraytypeinput == 2) {
        // 2D array operations
        int array2d[MAX][MAX];
        int rows, columns;

        cout << "Enter rows: ";
        cin >> rows;
        cout << "Enter columns: ";
        cin >> columns;

        inputAndDisplay2DArray(array2d, rows, columns);

        cout << "------2D Array Operations-------\n";
        cout << "1. Calculate Mean\n2. Calculate Average\n3. Find Maximum\n4. Find Minimum\n5. Search Element\n6. Transpose\n7. Exit\n";

        int arraychoice;
        cout << "Enter choice: ";
        cin >> arraychoice;

        switch (arraychoice) {
        case 1:
            calculatemean2d(array2d, rows, columns);
            break;
        case 2:
            average2d(array2d, rows, columns);
            break;
        case 3:
            findmax2d(array2d, rows, columns);
            break;
        case 4:
            findmin2d(array2d, rows, columns);
            break;
        case 5:
            search2darray(array2d, rows, columns);
            break;
        case 6:
            transpose(array2d, rows, columns);
            break;
        case 7:
            cout << "Exit Good Bye!";
            break;
        default:
            cout << "Error 404";
            break;
        }
    } else if (arraytypeinput == 3) {
        cout << "Exit Program Good bye!";
    } else {
        cout << "Error 404";
    }

    return 0;
}
