#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class newaccount {
protected:
    string name;
    string account_type;
    double initial_deposite;

public:
    void setnewaccount() {
        cout << "Enter Account Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account type (current or saving): ";
        cin >> account_type;

        cout << "Enter Initial Deposite: ";
        cin >> initial_deposite;

        if (initial_deposite < 10000) {
            cout << "Minimum deposit is 10000. Please enter again: ";
            cin >> initial_deposite;
        }
    }

    void shownewaccount() {
        srand(time(0));
        int randnum = rand() % 90000 + 10000;

        ofstream BANK("bank.txt", ios::app);
        if (BANK.is_open()) {
            cout << "\n----- Account Created Successfully -----\n";
            cout << "Account Number: " << randnum << endl;
            BANK << "Account Number: " << randnum << endl;

            cout << "Name: " << name << endl;
            BANK << "Name: " << name << endl;

            cout << "Account Type: " << account_type << endl;
            BANK << "Account Type: " << account_type << endl;

            cout << "Initial Deposite: " << initial_deposite << endl;
            BANK << "Initial Deposite: " << initial_deposite << endl;

            BANK << "_______________________________________\n";
            BANK.close();
        } else {
            cout << "Error opening file.\n";
        }
    }
};

class Deposit : public newaccount {
    int accnum;

public:
    void findacc() {
        cout << "Enter Account Number: ";
        cin >> accnum;

        ifstream infile("bank.txt");
        ofstream tempfile("temp.txt");

        string line;
        string match = "Account Number: " + to_string(accnum);
        bool found = false;

        while (getline(infile, line)) {
            tempfile << line << endl;

            if (line == match) {
                string lines;
                for (int i = 0; i < 3; i++) {
                    getline(infile, lines);
                    tempfile << lines<< endl;
                }

                double old_balance = stod(lines.substr(lines.find(":") + 2)); 

                getline(infile, line);
                double previous_balance = old_balance;
                if (line.find("Current Balance:") != string::npos) {
                    previous_balance = stod(line.substr(line.find(":") + 2));

                    getline(infile, line);  
                }

                double dep;
                cout << "Account Found! Enter amount to deposit: ";
                cin >> dep;
                double updated_balance = previous_balance + dep;

                tempfile << "Current Balance: " << updated_balance << endl;
                tempfile << "_______________________________________\n";
                found = true;
            }
        }

        infile.close();
        tempfile.close();

        remove("bank.txt");
        rename("temp.txt", "bank.txt");

        if (found)
            cout << " Deposit successful! Balance updated.\n";
        else
            cout << "Account not found.\n";
    }
};

class withdraw : public newaccount
{
public:
    void withdrawamount()
{
    int accnum;
    cout << "Enter Account Number: ";
    cin >> accnum;

    string line;
    bool found = false;
    string match = "Account Number: " + to_string(accnum);

    ifstream bank("bank.txt");
    ofstream temp("temp.txt");

    while (getline(bank, line)) {
        temp << line << endl;

        if (line == match) {
            for (int i = 0; i < 3; i++) {
                getline(bank, line);
                temp << line << endl;
            }

            getline(bank, line);

            double old_amount = stod(line.substr(line.find(":") + 2));
            double pre_amount = old_amount;

            if (line.find("Current Balance:") != string::npos) {
                pre_amount = stod(line.substr(line.find(":") + 2));
            } else {
                temp << line << endl; 
                getline(bank, line);  
            }

            int withdraw;
            cout << "Enter Amount to Withdraw: ";
            cin >> withdraw;

            if (withdraw <= pre_amount) {
                double updated = pre_amount - withdraw;
                temp << "Current Balance: " << updated << endl;
                found = true;
            } else {
                cout << "Insufficient Balance!\n";
            }
        }
    }

    bank.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (found)
        cout << "Money Withdrawn Successfully\n";
    else
        cout << "Account not found\n";
}

};

class Accountdetais : public newaccount
{
public:
    void show_acc_details()
    {
        int accnum;
        cout << "Enter Account Number: "<<" ";
        cin >> accnum;

        string line;
        bool find = false;
        ifstream read("bank.txt");

        string mline = "Account Number: " + to_string(accnum);
        if (read.is_open())
        {
            while (getline(read,line))
            {
                if (line == mline)
                {
                    find =  true;
                    cout << "-----Account Found------\n";
                    cout << line << endl;
                    for (int i = 0; i < 4; i++)
                    {
                       getline(read,line);
                       cout << line << endl;
                    }
                } 
            }
            
        }
        
        if (!find)
        {
            cout << "Accunt Not found\n";
        } 
    }
};

class delacc :public newaccount
{
public:
    void accd_delete()
    {
        int accnum;
        bool deleted = true;
        cout << "Enter Account Number: ";
        cin >> accnum;

        ifstream real("bank.txt");
        ofstream tempfile("temp.txt");

        string line;
        string mline = "Account Number: " + to_string(accnum);

        while (getline(real,line))
        {
            if (line == mline)
            {
                deleted = true;
                for (int i = 0; i < 5; i++)
                {
                    while (getline(real,line));
                    continue;
                }
            }
            else
            {
                tempfile << line <<endl;
            }   
        }
        
        if (!deleted)
        {
            cout << "Account Not Found\n";
        }

        real.close();
        tempfile.close();

        remove("bank.txt");
        rename("temp.txt","bank.txt");
    }
};

class Diplayacc : public newaccount
{
public:
    void displayAcc()
    {
        ifstream read("bank.txt");

        string line;

        if (read.is_open())
        {
        cout << "-----Accounts Details-----\n";
        while (getline(read,line))
        {
            cout << line <<endl;
        }   
        }
        else
        {
            cout << "File opening ERROR!\n";
        }
        
    }
};
int main() {
    newaccount newacc;
    Deposit dep;
    withdraw withdrawmoney;
    Accountdetais accdetail;
    delacc Delacc;
    Diplayacc Accdeiaply;
    int choice;

    cout << "\n-------- Welcome To UBL Bank ----------\n";
    cout << "1. Create a New Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. See Account Details\n";
    cout << "5. Delete Account\n";
    cout << "6. Display All Account\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            newacc.setnewaccount();
            newacc.shownewaccount();
            break;
        case 2:
            dep.findacc();
            break;
        case 3:
            withdrawmoney.withdrawamount();
            break;
        case 4:
            accdetail.show_acc_details();
            break;
        case 5:
            Delacc.accd_delete();
        case 6: 
            Accdeiaply.displayAcc();
        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}
