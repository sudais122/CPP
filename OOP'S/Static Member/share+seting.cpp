#include<iostream>
using namespace std;

class player{
    string name;
    int score;
    static string difficultyLevel;
public:
    void setPlayer(string n, int s){
        name = n;
        score  = s;
    }
    void dsiplay(){
        cout << "Name:" <<" " <<name <<endl;
        cout << "Score:" << " " << score <<endl;
        cout << "Difficulty Level:" <<" " << difficultyLevel <<endl;
        cout <<"------------------------------\n";
    }
    static void setDifficulty(string level){
        difficultyLevel = level;
    }
};

string player :: difficultyLevel = "easy";
int main() {
    player player1,player2;

    player1.setPlayer("Ali",1200);
    player2.setPlayer("Khan",1350);

    player1.dsiplay();
    player2.dsiplay();

    player::setDifficulty("Hard");

    player1.setPlayer("Ali",1200);
    player2.setPlayer("Khan",1350);

    player1.dsiplay();
    player2.dsiplay();

    player::setDifficulty("Impossible");

    player1.setPlayer("Ali",1200);
    player2.setPlayer("Khan",1350);

    player1.dsiplay();
    player2.dsiplay();

    return 0;
}