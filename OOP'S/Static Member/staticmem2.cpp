// Create a class User with static nextID and non-static userID.

// Each time an object is created, assign it nextID and increment nextID.

// Print each user’s unique ID.

#include<iostream>
using namespace std;

class user{
    static int nextID;
    int userid;
public:
    void getuser(){
        userid = ++nextID;
    }
    void printID(){
        cout << "User ID:"<<" " <<userid <<endl;
    }
    static void printid(){
        cout << "Next Avalible ID:"<<" " << nextID + 1 <<endl;
    }
};

int user::nextID = 1000;
int main() {
    user u1;
    u1.getuser();
    u1.printID();

    user u2;
    u2.getuser();
    u2.printID();

    user u3;
    u3.getuser();
    u3.printID();

    user ::printid();
    return 0;
}