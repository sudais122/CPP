// Objective: Block users after too many failed login attempts.
// Requirements:
// * Class LoginSystem
//     * Static const int maxAttempts = 3
//     * Non-static int attempts
//     * void login() function (simulates login and increments attempts)
// * Block the user after 3 failed attempts.
#include<iostream>
using namespace std;

class loginsysytem{
    const static int maxattempts = 3;
    static int attempts;
    int login;
public:
    void loginsys(int log){
        if ( attempts >=  maxattempts)
        {
            cout << "to many attempts you are blocked" << endl;
        }
        else
        {
            login = log;
            attempts++;
            cout << "Login sucessful\n";
            cout << "Totla Attempts" <<" "<< attempts <<endl;
            cout << "------------------------\n";
        }
    }
};
int loginsysytem :: attempts = 0;
int main() {
 
    loginsysytem login1;
    for (int i = 0; i < 4; i++)
    {
        int a;
        cout << "Enter acc number" <<" ";
        cin >> a;

        login1.loginsys(a);
    }

    return 0;
}