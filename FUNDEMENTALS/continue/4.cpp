#include <iostream>
using namespace std;

int main() {
    char vowels[5];
    int i = 0;

    while (i < 5) {
        char ch;
        cin >> ch;

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels[i] = ch;
            i++;  
        } else {
            continue;
        }
    }

    for (int j = 0; j < 5; j++) {
        cout << vowels[j] << " ";
    }
}
