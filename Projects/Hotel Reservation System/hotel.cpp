#include<iostream>
#include<fstream>
#include<vector>
#include <iomanip>
using namespace std;

class User
{
    string name;
    string password;
    string username;
    string email;

public:
    void newaccount()
    {
        ofstream account("Accounts.txt", ios::app);
        cin.ignore();

        cout << "Enter your Full Name: ";
        getline(cin, name);

        cout << "Enter User Name: ";
        cin >> username;

        cout << "Enter Your Password: ";
        cin >> password;

        cout << "Enter Your Email: ";
        cin >> email;

        cout << "-----Account Created Successfully-----\n";
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Email: " << email << endl;

        account << "Name: " << name << endl;
        account << "Username: " << username << endl;
        account << "Password: " << password << endl;
        account << "Email: " << email << endl;
        account << "---------------------------\n";

        account.close();
    }


    bool login()
    {
        ifstream loginFile("Accounts.txt");
        string inputUsername, inputPassword;
        string line;
        bool accFound = false;

        cout << "Enter Username: ";
        cin >> inputUsername;

        cout << "Enter Password: ";
        cin >> inputPassword;

        string username_line = "Username: " + inputUsername;
        string password_line = "Password: " + inputPassword;

        while (getline(loginFile, line))
        {
            if (line == username_line)
            {
                // check next lines for password
                while (getline(loginFile, line))
                {
                    if (line == password_line)
                    {
                        accFound = true;
                        cout << "\nWELCOME To SERENA HOTEL, " << inputUsername << "!\n";
                        break;
                    }
                    if (line.find("Username:") == 0)
                        break;
                }
                break;
            }
        }

        loginFile.close();

        if (!accFound)
        {
            cout << "Account Not Found or Incorrect Password\n";
        }

        return accFound;  
    }
};

class SearchAvalible : public User
{
public:
    void search()
    {
        bool avalibleroom = false;
        ifstream SEARCH("All Rooms.txt");
        string line;
        vector <string> lines;

        while (getline(SEARCH,line))
        {
            lines.push_back(line);
        }
        

        cout <<"-----Avalible Rooms Details-----\n";

        for (int i = 0; i < lines.size(); i++)
        {              
            if (lines[i] == "Status: Available")
            {
                avalibleroom = true;
                if (i >= 4)
                {
                    cout << lines[i - 4] << endl; 
                    cout << lines[i - 3] << endl; 
                    cout << lines[i - 2] << endl; 
                    cout << lines[i - 1] << endl; 
                }
                cout << lines[i] <<endl;
                cout <<"---------------\n";
            }
        }  
        if (!avalibleroom)
        {
            cout << "All Rooms are Booked\n";
        }
    }
};

class BookRoom : public User
{
public:
    void searchbytype()
    {
        cout << "-----Rooms Details-----\n";
        cout << "1.Single Rooms\n";
        cout << "2.Double Rooms\n";
        cout << "3.Suite Rooms\n";
        int choice;
        cout << "Enter Choice: ";
        cin >>choice;

        string line;
        ifstream single("Single.txt");
        ifstream Double("Double.txt");
        ifstream suite("suite.txt");

        if (choice == 1){while (getline(single,line)){cout << line <<endl;}}
        else if (choice == 2){while (getline(Double,line)){cout << line <<endl;}}
        else if (choice == 3){while (getline(suite,line)){cout << line <<endl;}}
        else {cout << "Invalid choice";};
    }

    void bookdetail()
    {
        bool isroom = false;
        bool isavalible = false;
        int roombook;

        cout << "Enter Room Number to Book: ";
        cin >>roombook;

        ifstream allrooms("All Rooms.txt");
        ofstream temp("temp.txt");
        string line;
    
        string match_line = "Room Number: " + to_string(roombook);
        if (allrooms.is_open())
        {
            while (getline(allrooms,line))
            {
                if (line == match_line)
                {
                    isroom = true;
                    cout << "Room Found"<<" ";
                    for (int i = 0; i < 5 && getline(allrooms,line); i++)
                    {
                        if (line == "Status: Available")
                        {
                            isavalible = true;
                            cout << "and Avalible for Booking.\n";
                            break;
                        }
                    }
                    break;   
                }
            }
            if (!isroom)
            {
                cout << "Room Not Found\n";
            }
            else if (!isavalible)
            {
                cout << "But Booked\n";
            }   
        }
        allrooms.seekg(0,ios::beg);

        if (isavalible)
        {
            ofstream bookedroom("Booked Rooms.txt",ios::app);
            cout << "-----Enter your Information-----\n";
            string Name;
            string Contact_number,CNIC;
            int Number_of_guests;
            string Check_in_date,check_out_dates;
            int final_price;
            int total_nights;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Full Name: ";
            getline(cin,Name);
            cout <<"Enter Contact Number: ";
            cin >> Contact_number;
            cin.ignore();
            cout << "Enter CNIC: ";
            cin >> CNIC;
            cin.ignore();
            cout << "Enter total Nights: ";
            cin >> total_nights;
            cout << "Enter No of Guests: ";
            cin >> Number_of_guests;
            cout << "Enter Check In date: ";
            cin >> Check_in_date;
            cout << "Enter Check out dates: ";
            cin >> check_out_dates;

            string calprice;
            while (getline(allrooms,calprice))
            {
                if (calprice == match_line)
                {
                    getline(allrooms,calprice);
                    if (calprice == "Room Type: Single")
                    {
                        final_price= total_nights*5000;
                    }
                    else if (calprice == "Room Type: Double")
                    {
                        final_price = total_nights*8000;
                    }
                    else if(calprice == "Room Type: Suite")
                    {
                        final_price = total_nights*15000;
                    }                
                }
            }
            
            allrooms.clear();
            allrooms.seekg(0,ios::beg);
            cout << "-----Booked Summary-----\n";
            cout << "Name: "<<" " <<Name <<endl;
            cout << "Contact: "<<" " <<Contact_number <<endl;
            cout << "CNIC: "<<" " <<CNIC <<endl;
            cout << "No of Guests: "<<" " <<Number_of_guests <<endl;
            cout << "Total Nights: "<<" "<< total_nights << endl;
            cout << "Chech In Date: "<<" " <<Check_in_date <<endl;
            cout << "Chech out Date: "<<" " <<check_out_dates <<endl;

            string roomline;
            while (getline(allrooms,roomline))
            {
                if (roomline == match_line)
                {
                    cout << roomline <<endl;
                    bookedroom << roomline <<endl;
                    for (int i = 0; i < 3; i++)
                    {
                        getline(allrooms,roomline);
                        cout << roomline <<endl;
                        bookedroom << roomline <<endl;
                    }
                }   
            }
            bookedroom << "Name: "<<" " <<Name <<endl;
            bookedroom << "Contact: "<<" " <<Contact_number <<endl;
            bookedroom << "CNIC: "<<" " <<CNIC <<endl;
            bookedroom << "Total Nights: "<<" "<< total_nights << endl;
            bookedroom << "No of Guests: "<<" " <<Number_of_guests <<endl;
            bookedroom << "Chech In Date: "<<" " <<Check_in_date <<endl;
            bookedroom << "Chech out Date: "<<" " <<check_out_dates <<endl;

            cout << "Total Nights: "<<" "<< total_nights << endl;
            cout << "Total Casts: "<<" " << final_price <<endl;
            bookedroom << "Total Nights: "<<" "<< total_nights << endl;
            bookedroom << "Total Casts: "<<" " << final_price <<endl;
            bookedroom <<"---------------------------------------------\n";
            allrooms.clear();
            allrooms.seekg(0,ios::beg);


            //Change the status from avalible to booked
            string update;
            bool status_updated = false;
            while (getline(allrooms,update))
            {
                if (update == match_line)
                {
                    temp << update <<endl;
                    for (int i = 0; i < 4 && getline(allrooms,update); i++)
                    {
                        if (update == "Status: Available")
                        {
                            update = "Status: Booked";
                            temp << update <<endl;
                            status_updated = true;
                        }
                        else
                        {
                            temp << update << endl;
                        }
                    }
                }
                else
                {
                    temp << update <<endl;
                }
                
            }
            temp.close();
            allrooms.close();
            remove("All Rooms.txt");
            rename("temp.txt","All Rooms.txt");
        }
        
    }
    
};

class cancell : public User
{
public:
   void Cancell()
   {
        int roomno;
        string line;
        cout << "Enter Room No to Cancell: ";
        cin >>roomno;
        
        ifstream cancellRoom("Booked Rooms.txt");
        ofstream temp("temp.txt");

        while (getline(cancellRoom,line))
        {
            if (line == "Room Number: " + to_string(roomno))
            {
                for (int i = 0; i < 13; i++)
                {
                    getline(cancellRoom,line);
                }
            }
            else
            {
                temp << line <<endl;
            }
        }
        
        cout <<"Room Number"<<" "<< roomno <<" "<< "Canceled Sucessfully" <<endl;
        remove("Booked Rooms.txt");
        rename("temp.txt","Booked Rooms.txt");


        ifstream allrooms("All Rooms.txt");
        ofstream statustemp("statustemp.txt");
        string updteline;
        bool islineupdated = false;

       while (getline(allrooms,updteline))
        {
            if (updteline == "Room Number: " + to_string(roomno))
            {
                statustemp << updteline <<endl;
                for (int i = 0; i < 4 && getline(allrooms,updteline); i++)
                {
                    if (updteline == "Status: Booked")
                    {
                        islineupdated = true;
                        updteline = "Status: Available";
                        statustemp << updteline <<endl;
                    }
                    else
                    {
                        statustemp << updteline <<endl;
                    }
                }   
            }
            else
            {
                statustemp << updteline <<endl;
            }
        }    

        remove("All Rooms.txt");
        rename("statustemp.txt","All Rooms.txt");

        if (!islineupdated)
        {
            cout << "Sorry this Room is not Booked\n";
        }
    
}
};

class adminlogin
{
private:
        string username = "admin";
        string pssword = "931357";
public:
    bool Adminlogin()
    {
        bool adminlogin = false;
        string u_username,u_pssword;

        cout<<"Enter Admin Usename:"<<" ";
        cin >> u_username;
        cout << "Enter Admin Password:"<<" ";
        cin >> u_pssword;

        if (u_username == username && u_pssword == pssword)
        {
            adminlogin =true;
            return true;
        }
        if (!adminlogin)
        {
            cout <<"Incorrect Usernme or Password\n";
        }
    }
};

class Admin
{
public:
    void viewbooking()
    {
        ifstream Booking("Booked Rooms.txt");
        string lines;

        cout << "-----Here are Booking Details-----\n";
        while (getline(Booking,lines))
        {
            cout << lines <<endl;
        }
        Booking.close();
    }
};

class addroom : public Admin
{
public:
    void AddRoom()
    {
        ofstream ADDROOM("All Rooms.txt",ios::app);

        int roomno,price_per_night;
        string roomtype,description,status,line;
    
        cout <<"Enter Room No: ";
        cin >> roomno;
        cout << "Enter Room type: ";
        cin >> roomtype;
        cout << "Enter Price Per Night: ";
        cin >> price_per_night;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Description: ";
        getline(cin,description);

        cout << "--Room Details--\n";
        cout << "Room Number:"<<" " << roomno <<endl;
        cout << "Room Type:"<<" " << roomtype <<endl;
        cout << "Price Per Night:"<<" " << price_per_night <<endl;
        cout << "Description:" <<" " << description << endl;
        cout << "Status: Available"<<endl;
        cout << "Room No"<<" "<<roomno <<"added Sucessfully.\n";


        ADDROOM<< "Room Number:"<<" " << roomno <<endl;
        ADDROOM<< "Room Type:"<<" " << roomtype <<endl;
        ADDROOM<< "Price Per Night:"<<" " << price_per_night <<endl;
        ADDROOM<< "Description:" <<" " << description << endl;
        ADDROOM<< "Status: Available"<<endl;
        ADDROOM<< "_____________________________________\n";

        ADDROOM.close();
    }
};

class DeleteRoom :public Admin
{
public:
    void DELroom(){
        bool isdeleted = false;
        int roomno;
        string line;
        cout << "Enter Room Number to Delete:"<<" ";
        cin >> roomno;

        ifstream delroom("All Rooms.txt");
        ofstream temp("temp.txt");

        while (getline(delroom,line))
        {
            if (line == "Room Number: " + to_string(roomno))
            {
                isdeleted = true;
                for (int i = 0; i < 5; i++)
                {
                    getline(delroom,line);
                    continue;
                } 
            }
            else
            {
                temp << line << endl;
            }
            
        }
        if (!isdeleted)
        {
            cout << "Room Not found\n";
        }
        else
        {
            cout << "Room Number"<<" " << roomno << " Deleted Sucessfully\n";
        }

        delroom.close();
        temp.close();
        remove("All Rooms.txt");
        rename("temp.txt","All Rooms.txt");
    }
};

class Reports : public Admin
{
public:
    void reports()
    {
        int bookcount = 0;
        int totalroom = 0; 
        int avaliblecount = 0;
        string line;

        ifstream report("All Rooms.txt");

        while (getline(report,line))
        {
            if (line == "Status: Booked")
            {
                bookcount++;
            }
            else if (line == "Status: Available")
            {
                avaliblecount++;
            }
            else if (line.find("Room Number:") !=string::npos)
            {
                totalroom++;
            }
        }
        report.close();

        //Revenue Generate
        int total_revenue = 0;
        int sum = 0;
        ifstream revenue("Booked Rooms.txt");
        string line_rev;

        while (getline(revenue,line_rev))
        {
            if (line_rev.find("Total Cost: ") !=string::npos)
            {
                string number_extract = line_rev.substr(12);//extract the number from line
                total_revenue = stoi(number_extract); // conver string to int  
                sum +=total_revenue;           //calculte totalrevenue
            }
        }
        revenue.clear();
        revenue.seekg(0,ios::beg);

        string roomtype;
        int single_room = 0;
        int double_room = 0;
        int suite_room = 0;
        
        while (getline(revenue,roomtype))
        {
            if (roomtype == "Room Type: Single")
            {
                single_room++;
            }
            else if (roomtype == "Room Type: Double")
            {
                double_room++;
            }
            else if (roomtype == "Room Type: Suite")
            {
                suite_room++;
            }
        }
        
        // find most booked room
        string mostroom;
        string leastroom;
        if (single_room > double_room && single_room > suite_room)
        {
            mostroom = "Single";
        }
        else if (double_room > single_room && double_room > suite_room)
        {
            mostroom = "Double";
        }
        else
        {
            mostroom = "Suite";
        }
        
        // find least bookedroom
        if (single_room < double_room && single_room < suite_room)
        {
            leastroom = "Single";
        }
        else if (double_room < single_room && double_room < suite_room)
        {
            leastroom = "Double";
        }
        else
        {
            leastroom =  "Suite";
        }
        
        int registeruser = 0;

        string user_line;
        ifstream registeracc("Accounts.txt");
        while (getline(registeracc,user_line))
        {
            if (user_line.find("Name: ") !=string::npos)
            {
                registeruser++;   
            }
        }

        cout << "-----Hotel Booking Report------\n";
        cout << "Total Rooms:" <<" "<< totalroom <<endl;
        cout << "Booked Rooms:" <<" " << bookcount <<endl;
        cout <<"Single Booked Rooms:"<<" " << single_room<<endl;
        cout <<"Double Booked Rooms:"<<" " << double_room<<endl;
        cout <<"Suite Booked Rooms:"<<" " << suite_room<<endl;
        cout << "Avaliable Rooms:"<<" "<< avaliblecount <<endl;
        
        cout <<"----------------------------------------------\n";
        cout << "Most Booked Room Type:"<<" " << mostroom <<endl;
        cout << "Least Booked Room Type:"<<" " << leastroom <<endl;        
        cout <<"----------------------------------------------\n";
        int occupied = (bookcount*100)/totalroom;
        cout<<"Total Revenue:"<<" "<<sum <<endl;
        cout << "Occupancy Rate: " << occupied <<"%"<<endl;
        cout << "Total Register Accounts:"<< " "<<registeruser <<endl;
    }
};

class AccountDetails : public Admin
{
public:
    void account()
    {
        ifstream accountdetails("Accounts.txt");
        string lines;
        cout<<"-----Accounts Details-----\n";
        while (getline(accountdetails,lines))
        {
            cout << lines <<endl;
        }
    }
};

class deleteacc :public Admin
{
public:
    void Delete()
    {
        string accname;
        string line;
        cin.ignore();
        cout << "Enter Account Name to Delete: ";
        getline(cin,accname);

        ifstream Accouns("Accounts.txt");
        ofstream temp("temp.txt");

        while (getline(Accouns,line))
        {
            if (line =="Name: "+accname)
            {
                for (int i = 0; i < 4; i++)
                {
                    getline(Accouns,line);
                }
            }
            else
            {
                temp << line <<endl;
            }
        }
        Accouns.close();
        temp.close();
       
       remove("Accounts.txt");
       rename("temp.txt","Accounts.txt"); 
    }
};
int main() {

    int mainchoice;
    adminlogin AdminLogin;
    cout << "1.Log in as a Admin\n";
    cout << "2.Log in as User/Customer\n";
    cout << "Enter your Choice\n";
    cin >> mainchoice;

    if (mainchoice == 1)
    {
       if (AdminLogin.Adminlogin())
       {
            Admin admin;
            SearchAvalible avaliblerooms;
            BookRoom bokrooms;
            cancell Cancell;
            addroom AddRoom;
            DeleteRoom DELETEroom;
            Reports REPORTS;
            AccountDetails accDetails;
            deleteacc Deleteaccount;

            cout << " ---------------------------------\n";
            cout << "HOTEL RESERVATION SYSTEM\n";
            cout << " ---------------------------------\n";
            cout << "1.Search Available Rooms\n";
            cout << "2.Book a Room\n";
            cout << "3.View Bookings Details.\n";
            cout << "4.Cancel a Booking\n";
            cout << "5.Add New Room Type\n";
            cout << "6.Delete Room\n";
            cout << "7.Generate Reports\n";
            cout << "8.View All Register Accounts Details\n";
            cout << "9.Delete User Account\n";
            cout << "0.Exit\n";
            int choice;
            cout << "Enter Your Choice";
            cin >> choice;
            switch (choice)
            {
            case 1:
                avaliblerooms.search();
                break;
            case 2:
                bokrooms.searchbytype();
                bokrooms.bookdetail();
                break;
            case 3:
                admin.viewbooking();
                break;
            case 4:
                Cancell.Cancell();
                break;
            case 5:
                AddRoom.AddRoom();
                break;
            case 6:
                DELETEroom.DELroom();
                break;
            case 7:
                REPORTS.reports();
                break;
            case 8:
                accDetails.account();
                break;
            case 9:
                Deleteaccount.Delete();
                break;
            case 0:
                cout <<" Good BYE!\n";
            default:
                cout << "Invalid Option!\n";
                break;
        }
       }
       
    }
    else if (mainchoice == 2)
    {
        User user;
        BookRoom booking;
        SearchAvalible avaliblerooms;
        cancell RoomCancell;

        int choice;
        cout << "1.Create Account\n";
        cout << "2.Log in\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            user.newaccount();
        }
        else if (choice == 2)
        {
            if (user.login())   
            {
                cout << "---------------------------------\n";
                cout << "SERENA HOTEL RESERVATION SYSTEM\n";
                cout << "---------------------------------\n";
                cout << "1.Search Available Rooms\n";
                cout << "2.Book a Room\n";
                cout << "3.Cancel a Booking\n";
                cout << "0.Exit\n";

                int userchoice;
                cout << "Enter Choice: ";
                cin >> userchoice;

                switch (userchoice)
                {
                case 1:
                    avaliblerooms.search();
                    break;
                case 2:
                    booking.searchbytype();
                    booking.bookdetail();
                    break;
                case 3:
                    RoomCancell.Cancell();
                    break;
                case 0:
                    cout << "Good BYE!\n";
                    break;
                default:
                    cout << "Invalid Choice\n";
                    break;
            }
        }
        else
        {
            cout << "Access Denied! Login failed.\n";
        }
    }
}
}
