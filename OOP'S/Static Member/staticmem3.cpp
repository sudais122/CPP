// bjective: Store common config values using static constants.
// Requirements:
// * Create a class AppConfig with:
//     * static const string appName
//     * static const float version
//     * static const int maxUsers
// * Initialize them properly.
// * Print them using a static function.

#include<iostream>
using namespace std;

class AppConfig{
    static const string appName;
    static const float version;
    static const int maxUsers;
public:
    static void print(){
        cout << "App Name:" <<" " <<appName <<endl;
        cout << "Version:" <<" " <<version <<endl;
        cout << "max Users" <<" " << maxUsers <<endl;
    }
};
const string AppConfig ::appName = "Mobiko";
const float AppConfig :: version = 4.55;
const int AppConfig :: maxUsers = 43;
int main() {
    AppConfig a1;
    a1.print();
    return 0;
}