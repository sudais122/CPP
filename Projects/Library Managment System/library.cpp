#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AddBook
{
    int BOOKID;
    string Tittle;
    string Auther;
    string status;

public:
    void addbook()
    {
        ifstream readid("bookid.txt");
        if (!readid)
        {
            BOOKID = 1000; 
        }
        else
        {
            readid >> BOOKID;
        }
        readid.close();

        BOOKID++;

        ofstream writeid("bookid.txt");
        writeid << BOOKID;
        writeid.close();

        cin.ignore(); 
        cout << "Enter Tittle: ";
        getline(cin, Tittle);

        cout << "Enter Auther: ";
        getline(cin, Auther);

        cout << "Enter Status: ";
        getline(cin, status);

        cout << "\n-----Book Added Successfully-----\n";
        cout << "Tittle: " << Tittle << endl;
        cout << "Book ID: " << BOOKID << endl;
        cout << "Auther: " << Auther << endl;
        cout << "Status: " << status << endl;

        ofstream save("library.txt", ios::app);
        save << "Tittle: " << Tittle << endl;
        save << "Book ID: " << BOOKID << endl;
        save << "Auther: " << Auther << endl;
        save << "Status: " << status << endl;
        save << "---------------------------\n";
        save.close();
    }
};

class DeleteBook
{
public:
    void deletebook()
    {
        ifstream real("library.txt");
        ofstream temp("temp.txt");
        bool found = false;
        string tittle;
        cin.ignore();
        cout << "Enter Book Tittle: ";
        getline(cin,tittle);

        string line;
        string mlinr = "Tittle: " + tittle;
 
        while (getline(real,line))
        {
            if (line == mlinr)
            {
                found = true;
                for (int i = 0; i < 5; i++)
                {
                    getline(real,line);
                    continue;
                }
            }
            else
            {
                temp << line <<endl;
            }
        }
        if (!found)
        {
            cout << "Book Not found";
        }
        else
        {
            cout <<"Book Deleted Sucessfully!\n";
        }

        real.close();
        temp.close();

        remove("library.txt");
        rename("temp.txt","library.txt");
    }
};

class Serch
{
public:
    void searchBook()
    {
        bool isfound = false;
        ifstream searchbook("library.txt");
        string line;
        string search;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Book Tittle: ";
        getline(cin,search);

        string match_line = "Tittle: " + search;
        while (getline(searchbook,line))
        {
            if (line == match_line)
            {
                isfound = true;
                cout << "-----Book Found-----\n";
                cout << line <<endl;
                for (int i = 0; i < 4; i++)
                {
                    getline(searchbook,line);
                    cout << line <<endl;
                }  
            }
            
        }
        if (!isfound)
        {
            cout << "Book Not found\n";
        } 
    }
};

class issue
{
public:
int tittle;
bool bookfound = false;
bool isavalible = false;
    void bookfind()
    {
        ifstream library("library.txt");

        string search;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Book Tittle: ";
        getline(cin,search);
        string line;
        string match_line = "Tittle: " + search;

        while (getline(library,line))
        {
            if (line == match_line)
            {
                bookfound = true;
                cout << "Book Found"<<" ";

                for (int i = 0; i < 4 && getline(library,line); i++)
                {
                    if (line == "Status: Available")
                    {
                        isavalible = true;
                        cout << "and it is Avalible\n";
                        break;
                    }
                }
                break;
            }
        }        

        if (!bookfound)
        {
            cout << "Book not found\n";
        }
        else if (!isavalible)
        {
            cout << "But it is not Avalibele\n";
        }

        library.close();





        if (isavalible)
        {
            string student_name;
            int rollno;
            double contact;
            string department;
            string issue_date;
            int duedateday;
            string duedatemonth;
            int duedateyr;
            bool status_updated = false;
            
            ifstream mainfile("library.txt");
            ofstream temp("temp.txt");
            ofstream issuebook("issuebook.txt",ios::app);

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Student Name: ";
            getline(cin,student_name);
            cout <<"Enter roll no: ";
            cin >> rollno;
            cout << "Enter Contact: ";
            cin>> contact;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Department: ";
            getline(cin,department);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<"Enter Due Date(day):";
            cin >> duedateday;
            cout <<"Enter Due Date(month):";
            cin >> duedatemonth;
            cout <<"Enter Due Date(year):";
            cin >> duedateyr;
            
            while (getline(mainfile,line))
            {
                if (line == match_line)
                {
                    temp << line <<endl;
                    issuebook << line << endl;
                    for (int i = 0; i < 4 && getline(mainfile,line); i++)
                    {
                        if (line == "Status: Available")
                        {
                            line = "Status: Issued";
                            status_updated = true;
                            temp << line << endl;

                            issuebook << line <<endl;
                            issuebook << "Issued to:"<<" " <<student_name<<endl;
                            issuebook << "Roll no:"<<" " << rollno <<endl;
                            issuebook << "Department:" <<" "<< department <<endl;
                            issuebook << "Issue Date:"<< " " << __DATE__ <<endl;
                            issuebook << "Due Date:"<<" "<<duedatemonth<<"-" << duedateday<<"-" << duedateyr <<endl;
                            issuebook <<"-----------------------------\n";
                            cout << "Book Issued sucessfully to " << student_name << endl;
                        }
                        else
                        {
                            temp << line <<endl;
                        }
                    }
                }
                else
                {
                    temp << line <<endl;
                }
            }

            mainfile.close();
            issuebook.close();
            temp.close();

            if (status_updated)
            {
                remove("library.txt");
                rename("temp.txt","library.txt");
            }
        }
    }    
};

class Return
{
public:
    void returnbook()
    {
        string line;
        bool returnbook = false;
        string tittle;
        ifstream realfile("issuebook.txt");
        ofstream newfile("temp.txt");

        cin.ignore();
        cout << "Enter book Tittle to Return: ";
        getline(cin,tittle);
        string match_line = "Tittle: " + tittle;
        while (getline(realfile,line))
        {
            if (line == match_line)
            {
                returnbook = true;   
                for (int i = 0; i < 8; i++)
                {
                    getline(realfile,line);
                }
            } 
            else
            {
                newfile <<line << endl;
            }
        }

        if (!returnbook)
        {
            cout << "Book Not found\n";
        }
        
        realfile.close();
        newfile.close();

        remove("issuebook.txt");
        rename("temp.txt","issuebook.txt");

        if (returnbook)
        {
            ifstream reurnBOOK("library.txt");
            ofstream  tempfile("temp.txt");
            string line;
            bool updated = false;

            while (getline(reurnBOOK,line))
            {
                if(line == match_line)
                {
                    tempfile << line <<endl;
                    for (int i = 0; i < 3 && getline(reurnBOOK,line); i++)
                    {
                        if (line == "Status: Issued")
                        {
                            line =  "Status: Available";
                            updated = true;
                            tempfile << line << endl;
                        } 
                        else
                        {
                            tempfile << line << endl;
                        }
                    }   
                }  
                else
                {
                    tempfile << line << endl;
                }
            }
            
            reurnBOOK.close();
            tempfile.close();

            remove("library.txt");
            rename("temp.txt","library.txt");

            cout << "Book"<<" "<<tittle <<" "<< "Return Sucessfully\n";
        }
        
    }
};

class Display
{
public:
    void display()
    {
        ifstream library("library.txt");
        string line;

        if (library.is_open())
        {
            cout << "-----All Books Details------\n";
            while (getline(library,line))
            {
                cout << line << endl;
            }
        }
        else
        {
            cout <<"File opening ERROR\n";
        }

        library.close();
    }
};
int main()
{
    cout << "-----Welcome To AWKUM Central Library-----\n";
    cout << "1.Add New Book\n";
    cout << "2.Delete Book\n";
    cout << "3.Search Book\n";
    cout << "4.Issue Book\n";
    cout << "5.Return Book\n";
    cout << "6.Display All Books\n";
    cout << "7.Exit\n";
    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    AddBook bookadd;
    DeleteBook deleteBOOK;
    Serch booksearch;
    issue bookissue;
    Return RETURNbook;
    Display displaybooks;
    switch (choice)
    {
    case 1:
        bookadd.addbook();
        break;
    case 2:
        deleteBOOK.deletebook();
        break;
    case 3:
        booksearch.searchBook();
        break;
    case 4:
        bookissue.bookfind();
        break;
    case 5:
        RETURNbook.returnbook();
        break;
    case 6:
        displaybooks.display();
        break;
    case 7:
        cout << "Good Bye!\n";
        break;
    default:
        cout << "invalid Choice\n";
    }
    return 0;
}
