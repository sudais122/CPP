#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct details 
{
    string name;
    long long Phonenumber;
    string Email;
} contactdetail;

//add new contact
void add_new_contact()
{
    ofstream store_record("phonerecord.txt",ios::app);

    cin.ignore();
    cout << "Enter Full name: " << " ";
    getline(cin,contactdetail.name);
    cout << "Enter Contact NUmber:" << " ";
    cin >> contactdetail.Phonenumber;
    cout << "Enter Email: " <<" ";
    cin >>contactdetail.Email;

    cout << "Name: " << contactdetail.name<<endl;
    cout << "Contact: " << contactdetail.Phonenumber<< endl;
    cout << "Email: " << contactdetail.Email<< endl;

    if (store_record.is_open())
    {
    store_record << "Name: " << contactdetail.name<<endl;
    store_record << "Contact: " << contactdetail.Phonenumber<< endl;
    store_record << "Email: " << contactdetail.Email<< endl;
    store_record << "________________________________________________\n";
    cout << "Record Added Sucessfully\n";
    cout<< "________________________________________________\n";
    }
    else
    {
        cout << "File Opening Error\n";
    }
}

//display contact
void Display_conatct()
{
    ifstream display("phonerecord.txt");

    string allcontact;
    if (display.is_open())
    {
        cout << "All Contacts Dispalyed\n";
        while (getline(display,allcontact))
        {
            cout<< allcontact <<endl;
        }
    }
    else
    {
        cout <<"File Opening Error\n";
    }
}

//search contact
void search_contact()
{
    ifstream search_file("phonerecord.txt"); 

    if (!search_file.is_open()) {
        cout << "File Opening Error\n";
    }

    string searchname, line;
    bool found = false;

    cout << "Enter name to find Contact: ";
    cin.ignore();
    getline(cin, searchname);

    // This is the key change
    string search_target = "Name: " + searchname;

    while (getline(search_file, line))
    {
        if (line.find(search_target) != string::npos)
        {
            found = true;
            cout << "\nContact Found:\n";
            cout << line << endl; 

            for (int i = 0; i < 2; ++i)
            {
                if (getline(search_file, line))
                    cout << line << endl;
            }
            cout << "________________________________\n";
            break; 
        }
    }

    if (!found)
    {
        cout << "Contact not found.\n";
    }
    search_file.close();
}   
int main()
{
    int choice;
    do
    {
    cout << "1.Add New Contact\n";
    cout << "2.Display All Contacts\n";
    cout << "3.Search Contact\n";
    cout << "4.Exit\n";

    cout << "Enter chioce:"<<" ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add_new_contact();
        break;
    case 2:
        Display_conatct();
        break;
    case 3:
        search_contact();
    default:
        break;
    case 4:
        cout << "Exit Program Good BYE!";
    }
    } while (choice !=4);
    
    
}