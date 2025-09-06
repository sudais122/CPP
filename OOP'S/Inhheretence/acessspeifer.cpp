#include<iostream>
using namespace std;

class Account{
    int account_number;
    float balance;
protected:
    string branchName;
public:
    string name;
    void setAccountData(int account_number,float balance,string name)
    {
        this ->account_number =account_number;
        this ->balance = balance;
        this->name = name;
    }

    // set and get branch name
    void setbranch(string branchName)
    {
        this->branchName =branchName;
    }

    string getbranchname()
    {
        return branchName;
    }

    //set and get name
    void Setname(string name)
    {
        this->name=name;
    }

    string getbranch()
    {
        return name;
    }
    void displayAccountData()
    {
        cout << "Name:"<<" "<< name<<"\n";
        cout << "Branch Name:"<<" "<< branchName<< "\n";
    }
};

class savingaccounts : public Account{
private:
    float intrestrate;
public:
    void setsavingaccounts(float intrestrate)
    {
        this ->intrestrate =intrestrate;
    }

    float getsavingaccounts()
    {
        return intrestrate;
    }
    void showsavingaccounts()
    {
        cout <<"Intrest Rate:" <<" "<<intrestrate<<"%"<<endl;
    }
};
int main() {
    Account acc;
    savingaccounts save;
    
    int accountno;
    float balance,intrestrate;
    string name,branchname;

    cout << "Enter name:"<<" ";
    cin >>name;
    cout << "Enter Account No:"<<" ";
    cin >>accountno;
    cout << "Enter balance:"<<" ";
    cin >>balance;
    cout << "Enter Branc Name:"<<" ";
    cin >>branchname;
    cout << "Enter Intrestrate:"<<" ";
    cin >>intrestrate;

    acc.setbranch(branchname);
    acc.getbranchname();
    save.setsavingaccounts(intrestrate);
    save.getsavingaccounts();
    
    cout << "---Account Details---\n";
    acc.displayAccountData();

    cout << "---Saving Details---\n";
    save.showsavingaccounts();
    return 0;
}