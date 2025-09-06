#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

class Admin
{
private:
    string username = "CEO";
    string password = "931357";
public:
    bool adminlogin()
    {
        bool islogin = false;
        string pass,user;
        cout << "Enter Username: ";
        cin >> user;
        cout << "Enter Password: ";
        cin >> pass;

        if (user == username && pass == password)
        {
            islogin =true;
            cout << "Acess Granted Welcom Login Sucessfull\n";
        }
        
        if (!islogin)
        {
            cout << "Acess Denied Login failed\n";
        }
        return islogin;
    }
};

class ManageDoctor : public Admin
{
private:
    string fullname,Specialization,Qualification,Years_of_Experience;
    string phone_number,email,shedule,status;
    int room;
public:
    void ADDdoctor(){
        ofstream docdetail("Dr Details.txt",ios::app);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Full Name: ";
        getline(cin,fullname);
        cout << "Enter Specialization: ";
        getline(cin,Specialization);
        cout << "Enter Qualification: ";
        getline(cin,Qualification);
        cout << "Enter Years of Experience: ";
        cin >> Years_of_Experience;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Phone Number: ";
        cin >> phone_number;
        cout << " Enter Email: ";
        cin >> email;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Shedule(Mon-Fri 9am-2pm): ";
        getline(cin,shedule);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Status: ";
        cin >> status;

        if (docdetail.is_open())
        {
            docdetail << "Doctor Name:"<<" "<< fullname<<endl;
            docdetail << "Specialization:"<<" "<<Specialization <<endl;
            docdetail << "Qualification:"<<" "<< Qualification<<endl;
            docdetail << "Years of Experience:"<<" "<< Years_of_Experience<<endl;
            docdetail << "Phone Number:"<<" "<< phone_number<<endl;
            docdetail << "Email:"<<" "<< email<<endl;
            docdetail << "Shedule:"<< " "<< shedule<<endl;
            docdetail << "Status:"<< " " << status<<endl;
            docdetail <<"---------------------------------------------\n";

            cout << "-----Detail Added Sucessfully-----\n";
            cout << " Full Name:"<<" "<< fullname<<endl;
            cout << " Specialization:"<<" "<<Specialization <<endl;
            cout << " Qualification:"<<" "<< Qualification<<endl;
            cout << " Years of Experience:"<<" "<< Years_of_Experience<<endl;
            cout << " Phone Number:"<<" "<< phone_number<<endl;
            cout << " Email:"<<" "<< email<<endl;
            cout << " Shedule"<< " "<< shedule<<endl;
            cout << " Status:"<< " " << status<<endl;

        }
        else
        {
            cout << "File opening ERROR\n";
        }
    }

    // delte doctor
    void Deletedoctor()
    {
        bool isdrfound = false;
        string drname;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Doctor Full Name: ";
        getline(cin,drname);

        string line;
        ifstream deldr("Dr Details.txt");
        ofstream temp("temp.txt");

        string dr_match = "Doctor Name: " + drname;
        while (getline(deldr,line))
        {
            if (line == dr_match)
            {
                isdrfound = true;
                for (int i = 0; i < 9; i++)
                {
                    getline(deldr,line);
                }  
            }
            else
            {
                temp << line <<endl;
            }
        }
        
        if (!isdrfound)
        {
            cout << "Doctor"<<" " <<drname <<" "<<"Not found in record\n";
        }
        else
        {
            cout << "Doctor"<<" " <<drname <<" "<<"Deleted Sucessfully\n";
        }
        
        deldr.close();

        remove("Dr Details.txt");
        rename("temp.txt","Dr Details.txt");
    }

    //view details of all deoctors
    void viewdetails()
    {
        ifstream details("Dr Details.txt");
        string line;

        if (details.is_open())
        {
            cout << "-----All Doctors Details-----\n";
            while (getline(details,line))
            {
                cout << line <<endl;
            }
        }
        else
        {
            cout << "File Opening Error\n";
        }  
        details.close();
    }
};

class Managepatient : public Admin
{
private:
    string fullName;
    string age;
    string gender;
    string phoneNumber;
    string email;
    string disease;
    string admittedRoom;
    string doctorAssigned;
    string status;
public:
    void addpatient()
    {
        ofstream addpatient("Patient.txt",ios::app);
        ifstream searchDR("Dr Details.txt");
        ifstream room("Rooms.txt");
        ofstream temp("temp.txt");

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Enter full name: ";
        getline(cin,fullName);
        cout << "Enter Age: ";
        getline(cin,age);
        cout << "Enter Gender: ";
        getline(cin,gender);
        cout << "Enter Phone Number: ";
        getline(cin,phoneNumber);
        cout << "Enter Email: ";
        getline(cin,email);
        cout << "Enter Disease: ";
        getline(cin,disease);
        cout << "Enter Admitted Room No: ";
        getline(cin,admittedRoom);
        cout << "Enter Doctor Assign: ";
        getline(cin ,doctorAssigned);
        cout << "Enter status: ";
        getline(cin,status);

        // find doctoe if found assign to parient else error
        string line;
        string roomline;
        bool DRfound = false;
        bool isroomavalible = false;
        while (getline(searchDR,line))
        {
            if (line.find("Doctor Name: " + doctorAssigned) !=string::npos)
            {
                DRfound = true;
                break;
            }
            
        }
        if (!DRfound)
        {
            cout << "Doctor not found ist add doctor details\n";
        }

        
        //chech if current room is booked are avalible
        while (getline(room,roomline))
        {
            if (roomline.find("Room Number: " + admittedRoom) !=string::npos)
            {
                temp << roomline << endl;
                getline(room,roomline);
                temp << roomline << endl;

                getline(room,roomline);
                if (roomline.find("Status: Available") != string::npos)
                {
                    isroomavalible = true;
                    roomline  = "Status: Booked";
                    temp << roomline << endl;
                }
                else
                {
                    temp << roomline <<endl;
                }
            }
            else
            {
                temp << roomline <<endl;
            }   
        }
        if (!DRfound)
        {
            cout << "Doctor not found\n";
        }
        if (!isroomavalible)
        {
            cout << "Sorry Room Number"<<" "<< admittedRoom <<" "<<"is booked\n";
        }
        
        remove("Rooms.txt");
        rename("temp.txt","Rooms.txt");
        
        if (DRfound && isroomavalible)
        {
            if (addpatient.is_open())
                {
                    addpatient << "Name:"<<" "<<fullName <<endl;
                    addpatient << "Age:" <<" "<<age<<endl;
                    addpatient << "Gender:"<<" "<<gender<<endl;
                    addpatient << "Phone Number:"<<" "<<phoneNumber<<endl;;
                    addpatient << "Email:"<<" "<<email<<endl;
                    addpatient << "Disease:"<<" "<<disease<<endl;
                    addpatient << "Admitted Room No:"<<" "<<admittedRoom<<endl;
                    addpatient << "Doctor Assign:"<<" "<<doctorAssigned<<endl;
                    addpatient << "status:"<<" "<<status<<endl;
                    addpatient <<"-----------------------------------\n";
                }
                 else
                {
                    cout << "File Opening Error!\n";
                }

                string filepath = "Dr Patients/" +  doctorAssigned + ".txt";
                ofstream drfile(filepath,ios::app);

                if (drfile.is_open())
                {
                    drfile << "Name:"<<" "<<fullName <<endl;
                    drfile << "Age:" <<" "<<age<<endl;
                    drfile << "Disease:"<<" "<<disease<<endl;
                    drfile << "Room No: "<<" "<< admittedRoom <<endl;
                    drfile << "status:"<<" "<<status<<endl;
                    drfile <<"-----------------------------------\n";
                }
                else
                {
                    cout << "File Openin ERROR!\n";
                }

                cout << "-----Patient Record Added Sucessfully-----\n";
                cout << "Assigned Doctor:"<<" "<<doctorAssigned <<endl;
                cout <<"Added in Record of"<<" "<<doctorAssigned <<endl;
        }
        
    }

    //delete patient
    void delpatient()
    {
        ifstream DEL("patient.txt");
        ofstream temp("temp.txt");
        bool deleted = false;
        string line,name;

        cout << "Enter Parient Name to delete: ";
        cin >> name;
        while (getline(DEL,line))
        {
            if (line.find("Name: " + name) !=string::npos)
            {
                deleted =  true;
                for (int i = 0; i < 10; i++)
                {
                    getline(DEL,line);
                    continue;
                }
            }
            else
            {
                temp << line << endl;
            }
        }
        if (!deleted)
        {
            cout << "Patient not found!\n";
        }
        else
        {
            cout << "Patient"<<" "<< name <<" "<< "Deleted Sucessfully!";
        }
        
        DEL.close();
        remove("patient.txt");
        rename("temp.txt","patient.txt");
    }

    //view all patients
    void patientdetails()
    {
        string line;
        ifstream details("patient.txt");

        cout << "-----Patients Details-----\n";
        while (getline(details,line))
        {
            cout << line <<endl;
        }
        
    }
};

class MangeStaff : public Admin
{
private:
    string name;
    string age;
    string gender;
    string phone;
    string qualification;
    string Assignddoctor;
    string shift;
    string nursename;
    string drname;
public:
    void addnurse()
    {
        ofstream nurse("Nurses/Details.txt",ios::app);
        ifstream Dr("Dr Details.txt");
        string line;
        bool assigndrfound = false;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin,name);
        cout << "Enter Age: ";
        getline(cin,age);
        cout << "Enter Gender: ";
        getline(cin,gender);
        cout << "Enter Phone: ";
        getline(cin,phone);
        cout << "Enter Qualifaction: ";
        getline(cin,qualification);
        cout << "Enter Assign Doctor: ";
        getline(cin,Assignddoctor);

        while (getline(Dr,line))
        {
            if (line == "Doctor Name: " + Assignddoctor)
            {
                assigndrfound = true;
            }
        }
        
        if (assigndrfound)
        {
            if (nurse.is_open())
            {
                nurse << "Name:"<<" "<<name<<endl;
                nurse << "Age:"<<" " <<age<<endl;
                nurse << "Gender:"<<gender<<endl;
                nurse << "Phone:"<<phone<<endl;
                nurse << "Qualifaction:"<<" "<<qualification<<endl;
                nurse << "Assign Doctor:"<<" "<<Assignddoctor<<endl;
                nurse <<"-----------------------------------\n";
            }
            else
            {
                cout << "File Opening ERROR!\n";
            }
            cout << "-----Nurse Record Added Sucessfully----\n";
            cout << "Name:"<<" "<<name<<endl;
            cout << "Age:"<<" "<<age<<endl;
            cout << "Gender:"<<" "<<gender<<endl;
            cout << "Phone:"<<" "<<phone<<endl;
            cout << "Qualifaction:"<<" "<<qualification<<endl;
            cout << "Assign Doctor:"<<" "<<Assignddoctor<<endl;
        }
        else
        {
            cout << "Assign Doctor Not Found Record Not added!\n";
        }
    }

    //assign nurse to doctor
    void assignnursetodoctor()
    {
        string nurse_line;
        string assign_line;
        string dr_line;
        bool drfound = false;
        bool nursefound = false;

        ifstream nurse("Nurses/Details.txt");
        ofstream Assign("Nurses/Assignment.txt",ios::app);
        ifstream Dr("Dr Details.txt");

        if(!nurse){cout << "Nurses/Details .txt file opening error\n";};
        if(!Assign){cout << "Nurses/Assignment.txt file opening error\n";};
        if(!Dr){cout << "Dr Details.txt file opening error\n";};
        
        cin.ignore();
        cout << "Enter Doctor Name: ";
        getline(cin,drname);
        cout << "Enter Nurse Name: ";
        getline(cin,nursename);
        cout << "Enter Shift: ";
        getline(cin,shift);

        while (getline(Dr,dr_line))
        {
            if (dr_line.find("Doctor Name: "+ drname) !=string::npos)
            {
                drfound =true;
            }
            else
            {
                cout << "Doctor not found\n";
            }
        }
        
        while (getline(nurse,nurse_line))
        {
            if (nurse_line.find("Name: " + nursename) !=string::npos)
            {
                nursefound = true;
            }
            else
            {
                cout << "Nurse Not found\n";
            }
        }


            if (drfound && nursefound)
            {
                Assign << "Doctor:" <<" "<<drname <<endl;
                Assign << "NUrse Assign:" <<" "<<nursename<<endl;
                Assign << "Shift:" <<" "<<shift<<endl;
                Assign <<"---------------------"<<endl;
                cout << "Nurse Assign Sucessfully to"<<" "<< drname <<"."<< endl;
            }
    }
      
    //view nurse details
    void viewnurses()
    {
        string line;
        fstream nurse("Nurses/Details.txt");

        if (nurse.is_open())
        {
            cout << "-----All Nurses Details-----\n";
            while (getline(nurse,line))
            {
                cout << line <<endl;
            }
        }
        else
        {
            cout << "File opening Error!\n";
        }
    }

    // delete nurse
    void deletenurse()
    {
        string line;
        ifstream nurse("Nurses/Details.txt");
        ofstream temp("Nurses/temp.txt");
        bool isdeleted = false;

        cin.ignore();
        cout << "Enter Nurse Name to delete:";
        getline(cin,nursename);

        if (nurse.is_open())
        {
            while (getline(nurse,line))
            {
                if (line.find("Name: " + nursename) !=string::npos)
                {
                    for (int i = 0; i < 7; i++)
                    {
                        isdeleted = true;
                        getline(nurse,line);
                        continue;
                    }
                }
                else
                {
                    temp << line <<endl;
                }
            }
            
        }
        else
        {
            cout << "File OPening ERROR!\n";
        }
        

        if (!isdeleted)
        {
            cout << "Nurse"<<" "<<nursename<<" "<<"Deleted Sucessfully\n";
        }
        
        remove("Nurses/Details.txt");
        rename("Nurses/temp.txt","Nurses/Details.txt");
    }
};

class Managerooms : public Admin
{
private:
    int roomno;
    int price;
public:
    void addroom()
    {
        cout << "Ente Room No: ";
        cin >> roomno;
        cout << "Enter Room Price: ";
        cin >> price;

        ofstream room("Rooms.txt",ios::app);

        if (room.is_open())
        {
            room << "Room Number:"<<" "<<roomno<<endl;
            room << "Price per Night:"<<" "<<price <<endl;
            room << "Status: Available"<<endl;
            room << "---------------------\n"<<endl;
        }
        else{
            cout << "File opening ERROR!\n";
        }
        
        cout << "---Room Added Sucessfully----\n";
        cout << "Room Number:"<<" "<<roomno<<endl;
        cout << "Price per Night:"<<" "<<price <<endl;
        cout << "Status: Available"<<endl;
    }

    //view all rooms
    void viewallrooms()
    {
        ifstream rooms("Rooms.txt");
        string line;

        if (rooms.is_open())
        {
            while (getline(rooms,line))
            {
                cout << line <<endl;
            }
        }else{
            cout << "File opening ERROR!\n";
        }
    }

    //delete room
    void deleteroom()
    {
        ifstream rooms("Rooms.txt");
        ofstream temp("temp.txt");

        string line;
        int delroom;
        bool isbooked = false;
        
        cout << "Enter Room Number to Delete: ";
        cin >>delroom;

        while (getline(rooms,line))
        {
            if (line.find("Room Number: " + to_string(delroom)) !=string::npos)
            {
                for (int i = 0; i < 4; i++)
                {
                    getline(rooms,line);
                    if (line.find("Status: Booked") !=string::npos)
                    {
                        isbooked = true;
                        cout << "Can't Deleted a booked Room\n";
                    }
                }  
            }
        }

        rooms.clear();
        rooms.seekg(0,ios::beg);

        if (!isbooked)
        {
            while (getline(rooms,line))
            {
                if (line.find("Room Number: " + to_string(delroom)) !=string::npos)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        getline(rooms,line);
                        continue;
                    }
                }else{
                    temp << line << endl;
                }
                
            }
            
        }
        remove("Rooms.txt");
        rename("temp.txt","Rooms.txt");

    }
};

class Doctor{
private:
    string fullname;
    string email;
    string username;
    string password;
public:
    void DoctorRegister()
    {
        ofstream draccount("Register Acct's/DR.txt",ios::app);

        cin.ignore();
        cout << "Enter Full Name: ";
        getline(cin,fullname);
        cout << "Enter Email: ";
        getline(cin,email);
        cout << "Enter Username: ";
        getline(cin, username);
        cout << "Enter Password: ";
        getline(cin,password);

        if (draccount.is_open())
        {
            draccount << "Full Name:"<<" "<<fullname<< endl;
            draccount << "Email:"<<" "<<email<< endl;
            draccount << "Username:"<<" "<<username<< endl;
            draccount << "Password:"<<" "<<password<< endl;
            draccount << "--------------------------------\n";

            cout << "---Account Register Sucessfully---\n";
            cout << "Full Name:"<<" "<<fullname<< endl;
            cout << "Email:"<<" "<<email<< endl;
            cout << "Username:"<<" "<<username<< endl;
            cout << "Password:"<<" "<<password<< endl;
            cout << "--------------------------------\n";
        }
        else{
            cout << "File opening ERROR!\n";
        }
    }

    // doctor login
    bool doctorlogin()
    {
        string U_username,U_password,line;
        ifstream login("Register Acct's/DR.txt");

        bool islogin = false;

        cout << "Enter Username: ";
        cin >> U_username;
        cout << "Enter Password: ";
        cin >> U_password;

        while (getline(login,line))
        {
            if (line.find("Username: " + U_username) !=string::npos)
            {
                getline(login,line);
                if (line.find("Password: " + U_password) !=string::npos)
                {
                    islogin = true;
                }  
            }
        }
        
        return islogin;
    }

    //view assign patient
    void viewpatients()
    {
        string drname,line;
        bool drfound = false;

        cin.ignore();
        cout << "Enter Doctor Name: ";
        getline(cin,drname);

        string filepath = "Dr Patients/" + drname + ".txt";

        ifstream patient(filepath);

        cout << "-----Dr Patients Details-----\n";
        while (getline(patient,line))
        {
            drfound = true;
            cout << line << endl;
        }

        if (!drfound)
        {
            cout << "Doctor Not found!\n";
        }
        
    }

    //Add Prescription
    void updatepatientstatus()
    {
        string line,patientname,drname;
        bool statusupdated = false;
        bool patientfound = false;

        cin.ignore();
        cout << "Enter DR Name: ";
        getline(cin,drname);
        cout << "Enter Patient Name: ";
        getline(cin,patientname);

        string filepath = "Dr Patients/" + drname + ".txt";
        string tempfilepath = "Dr Patients/temp.txt";
        ofstream dischage("Dr Patients/Discharge History.txt");

        ifstream drfile(filepath);
        ofstream tempdrfile(tempfilepath);

        if(!drfile){cout << "Dr file opening ERROR!";}
        if (!dischage){cout << "Discharge file ERROR\n";}
        if(!tempdrfile){cout << "Temp file opening ERROR!\n";}

        while (getline(drfile,line))
        {
            if (line.find("Name: " + patientname) !=string::npos)
            {
                tempdrfile << line << endl;
                patientfound = true;
                for (int i = 0; i < 4; i++)
                {
                    getline(drfile,line);
                    if (line.find("Status: Admitted") !=string::npos)
                    {
                        line = "Status: Ready for Discharge";
                        statusupdated = true;
                        tempdrfile << line <<endl;
                    }
                    else
                    {
                        tempdrfile << line <<endl;
                    }  
                }
            }
            else
            {
                tempdrfile << line <<endl;
            }
        }
        remove(filepath.c_str());
        rename(tempfilepath.c_str(), filepath.c_str()); // not undertansad by c_str() study itlatter

        if (patientfound && statusupdated)
        {
            cout << "Patient"<<" "<< patientname <<" "<< "Ready for Discharge \n";
        }
        if(!patientfound)
        {
            cout << "Patient Not found\n";
        }
        if (!statusupdated)
        {
            cout << "Status not upadted";
        }
        
    }


    void searchpatient()
    {
        string line,drname,patientname;  
        bool patienfound = false;

        cin.ignore();
        cout << "Enter Dr Name: ";
        getline(cin,drname);
        cout << "Enter patient Name: ";
        getline(cin,patientname);

        ifstream search("Dr Patients/" + drname + ".txt");

        if(!search){cout << "File not found!\n";}
        while (getline(search,line))
        {
            if (line == "Name: " + patientname)
            {
                cout << "----Patient Found-----\n";
                cout << line <<endl;
                patienfound = true;
                for (int i = 0; i < 5; i++)
                {
                    getline(search,line);
                    cout << line << endl;
                }
            }
        }
        if (!patienfound)
        {
            cout << "Patient Not found in record\n";
        }
    }

    void assignnurse()
    {
        string line,drname;
        bool nursefound = false;

        cin.ignore();
        cout << "Enter Dr Name: ";
        getline(cin,drname);

        ifstream asign("Nurses/Assignment.txt");
        if(!asign){cout << "File opening ERROR!\n";}

        while (getline(asign,line))
        {
            if (line.find("Doctor: " + drname) !=string::npos)
            {
                cout << "---Nurse Details---\n";
                cout << line <<endl;
                nursefound = true;
                for (int i = 0; i < 3; i++)
                {
                    getline(asign,line);
                    cout << line << endl;
                }
                
            }
            
        }
        
        if (!nursefound)
        {
            cout << "Nurse is not assign to Dr " << drname << endl; 
        }        
    }
};

class Nurse
{
private:
    string fullname;    
    string emial;
    string username;
    string password;  
    string Temp;
    string BP;
    string HR;
    string Respiration;
    string SO;
public:
    void registernurse()
    {
        ofstream nurseregister("Register Acct's/nurse.txt",ios::app);

        cin.ignore();
        cout << "Enter Full Name: ";
        getline(cin,fullname);
        cout << "Enter Email: ";
        getline(cin,emial);
        cout << "Enter Username: ";
        getline(cin, username);
        cout << "Enter Password: ";
        getline(cin,password);

        if (nurseregister.is_open())
        {
            nurseregister << "Full Name:"<<" "<<fullname<< endl;
            nurseregister << "Email:"<<" "<<emial<< endl;
            nurseregister << "Username:"<<" "<<username<< endl;
            nurseregister << "Password:"<<" "<<password<< endl;
            nurseregister << "--------------------------------\n";

            cout << "---Account Register Sucessfully---\n";
            cout << "Full Name:"<<" "<<fullname<< endl;
            cout << "Email:"<<" "<<emial<< endl;
            cout << "Username:"<<" "<<username<< endl;
            cout << "Password:"<<" "<<password<< endl;
            cout << "--------------------------------\n";
        }
        else{
            cout << "File opening ERROR!\n";
        }
    }

    //nurse account login
    bool nurselogin()
    {
        string line;
        ifstream loginnurse("Register Acct's/nurse.txt");
        bool login = false;

        if(!loginnurse){cout << "File Opening ERROR!\n";}

        cin.ignore();
        cout << "Enter User Name: ";
        getline(cin,username);
        cout << "Enter Password: ";
        getline(cin,password);


        while (getline(loginnurse,line))
        {
            if (line.find("Username: " + username) !=string::npos)
            {
                getline(loginnurse,line);
                if (line.find("Password: " + password) !=string::npos)
                {
                    login = true;
                }   
            }
        }
        
        return login;
    }

    //see assign patients
    void assignpatients()
    {
        string line,assigndr;
        bool nursefound = false;
        ifstream nursedetail("Nurses/Assignment.txt");

        if(!nursedetail){cout << "Nurses/Assignment.txt opening ERROR!\n";}

        cin.ignore();
        cout << "Enter Nurse Name: ";
        getline(cin,fullname);

        while (getline(nursedetail,line))
        {
            if (line.find("Nurse Assign: " + fullname) !=string::npos)
            {
                getline(nursedetail,line);
                assigndr = line.substr(8); //extract the doctor name form the line
            }
        }
        
        string filepath = "Dr Patients/" + assigndr + ".txt";
        ifstream patientfile(filepath);

        if (patientfile.is_open())
        {
            cout << "-----Patients Asiign Details-----\n";
            cout << fullname <<" "<< "Nurse is Assign to Dr" <<" "<< assigndr <<endl;
            while (getline(patientfile,line))
            {
                cout << line << endl;
            }
        }
        else
        {
            cout << "File opening ERROR!\n";
        }
        
    }

    //add patient vital details
    void patientvitals()
    {
        string line,assigndr,patientname;
        bool nursefound = false;
        bool patientfound = false;
        ifstream nurse("Nurses/Assignment.txt");

        if(!nurse){cout << "Nurses/Assignment.txt File Opening ERROR!";}

        cin.ignore();
        cout << "Enter Nurse Name: ";
        getline(cin,fullname);

        while (getline(nurse,line))
        {
            if (line.find("Nurse Assign: " + fullname) !=string::npos)
            {
                nursefound = true;
                getline(nurse,line);
                assigndr = line.substr(8); // extract dr name from e.g Doctor: Ali Khan
                break;
            }
            
        }
        cout << "Nurse"<<" " <<fullname <<" " <<"is Assign to Dr " << assigndr <<endl;

        if (!nursefound)
        {
            cout << "Nursr not found in the record\n";
        }

        
        if (nursefound)
        {
            string filepath = "Dr Patients/" + assigndr + ".txt";
            ifstream drfile(filepath);
            ofstream temp("Dr Patients/temp.txt");

            if(!drfile){cout << "Dr patient file Opening ERROR!\n";}

            cout << "Enter Patient Name: ";
            getline(cin,patientname);

            string drline;
            while (getline(drfile,line))
            {
                if (line.find("Name: " + patientname) !=string::npos)
                {
                    temp << line <<endl;
                    for (int i = 0; i < 4; i++)
                    {
                        getline(drfile,line);
                        temp << line <<endl;
                    }
                
                    patientfound = true;
                    cout << "Enter Temperature: ";cin >> Temp;
                    cout << "Enter BP: ";cin >> BP;
                    cout << "Enter HR: ";cin >> HR;
                    cout << "Enter Respiration: ";cin >>Respiration;
                    cout << "Enter SO: ";cin >> SO;

                    temp << "Vitals Details:\n";
                    temp << "   Temperature: "<< Temp<<endl;
                    temp << "   BP: "<< BP<<endl;
                    temp << "   HR: "<< HR<<endl;
                    temp << "   Respiration: "<< Respiration<<endl;
                    temp << "   SO: : "<< SO<<endl;

                    cout << "Vital Record Added Sucessfully in Record.\n";
                }
                else
                {
                    temp << line << endl;
                }
            
            }
            remove(filepath.c_str());
            rename("Dr Patients/temp.txt",filepath.c_str());   
        }
    }

    //patient dischege
    void patientdischarge()
    {
        bool isdischarge = false;
        bool nursefound = false;
        bool patienfoud= false;
        string patientname,nursename,line,assigndr;

        cin.ignore();
        cout << "Enter nurse Name: ";
        getline(cin,nursename);

        ifstream nursefile("Nurses/Assignment.txt");
        if(!nursefile){cout << "Nurse file opening ERROR!\n";}
        while (getline(nursefile,line))
        {
            if (line.find("Nurse Assign: " + nursename) !=string::npos)
            {

                nursefound = true;
                getline(nursefile,line);
                assigndr = line.substr(8);
                break;
            }
            
        }
        
        string filepath = "Dr Patients/" + assigndr + ".txt";

        ifstream drfile(filepath);
        ofstream temp("Dr Patients/temp.txt");
        ofstream discharge("Dr Patients/Discharge History.txt",ios::app);

        if(!drfile) {cout << "Dr file opening ERROR!\n";}
        if(!temp) {cout << "temp file opening ERROR\n";}

        cin.ignore();
        cout << "Enter Patient Nane: ";getline(cin,patientname);

        while (getline(drfile,line))
        {
            if (line.find("Name: " + patientname) !=string::npos)
            {
                temp << line <<endl;
                patienfoud = true;

                for (int i = 0; i < 4; i++)
                {
                    getline(drfile,line);
                    if (line.find("Status: Ready for Discharge") !=string::npos)
                    {
                        line = "Status: Discharge";
                        temp << line << endl;
                        isdischarge = true;
                    }else{
                        temp << line << endl;
                    }   
                }
            }else{
                temp << line <<endl;
            }  
        }
        if (!isdischarge)
        {
            cout << "Patient Already discharge\n";
        }else
        {
            cout << "Patient"<<" " <<patientname<<" "<< "is Discharge by"<<" "<< assigndr <<endl;
            discharge << "Patient"<<" " <<patientname<<" "<< "is Discharge by"<<" "<< assigndr <<endl;
            discharge <<"---------------------------------------\n";
        }
        
        remove(filepath.c_str());
        rename("Dr Patients/temp.txt", filepath.c_str());

        drfile.clear();
        drfile.seekg(0,ios::beg);

        //room chage from book to avalible
        if (isdischarge)
        {
            string roomno,patientroomno,room,extracrroom;

            while (getline(drfile,line))
            {
                if ((line.find("Name: " + patientname) !=string::npos))
                {
                    getline(drfile,line);
                    getline(drfile,line);
                    getline(drfile,line);
  
                    if (line.find("Room No: ") !=string::npos)
                    {
                        patientroomno = line.substr(9);
                    } 
                }
            }
            bool roomatch = false;
            ifstream roomsdetail("Rooms.txt");
            ofstream tempfile("temp.txt");

            while (getline(roomsdetail,line))
            {
                if (line.find("Room Number: " + patientroomno) !=string::npos)
                {
                    tempfile << line <<endl; //room no line
                    getline(roomsdetail,line); // price per night
                    tempfile << line << endl;
                    getline(roomsdetail,line); //read the status line
                    tempfile << "Status: Available" <<endl;
                    roomatch = true;
                }else
                {
                    tempfile << line <<endl;
                }
            }
            if(!roomatch){
                cout << "Room number Not match;\n";
            }
            roomsdetail.close();
            tempfile.close();
            remove("Rooms.txt");
            rename("temp.txt","Rooms.txt");
        }
        

        ifstream patient("patient.txt");
        ofstream tempp("temp.txt");
        string lines;

        while (getline(patient,lines))
        {
            if (lines.find("Name: " + patientname) !=string::npos)
            {
                tempp << lines <<endl;

                for (int i = 0; i < 8; i++)
                {
                    getline(patient,lines);
                    if (lines.find("Status: Admitted") !=string::npos)
                    {
                        lines = "Status: Discharge";
                        tempp << lines << endl;
                    }else{
                        tempp << lines <<endl;
                    }
                }
            }else{
                tempp << lines <<endl;
            }
        }
        patient.close();
        tempp.close();

        remove("patient.txt");
        rename("temp.txt","patient.txt");
        
    }
};

class Patient
{
private:
    string fullname;
    string email;
    string username;
    string password;
public:
    void patientresgister()
    {
        cin.ignore();
        cout << "Enter full Name: "; getline(cin,fullname);
        cout << "Enter Email: "; getline(cin,email);
        cout << "Enter Username: "; getline(cin,username);
        cout << "Enter Password: "; getline(cin,password);

        ofstream patient("Register Acct's/patient.txt",ios::app);
        if(!patient) {cout << "File patien opening ERROR\n";}
        
        patient << "Full Name: " <<fullname<<endl;
        patient << "Email: "<<email<<endl;
        patient << "Username: "<<username<<endl;
        patient << "Password: "<<password<<endl;
        patient << "-----------------------\n";

        cout << "----Registration Sucessfull-----\n";
        cout << "full Name: " <<fullname<<endl;
        cout << "Email: "<<email<<endl;
        cout << "Username: "<<username<<endl;
        cout << "Password: "<<password<<endl;

    }

    //patient login
    bool patientlogin()
    {
        string u_username,u_password,line;
        bool accfound = false;
        cin.ignore();
        cout << "Enter username: "; getline(cin,u_username);
        cout << "Enter password: "; getline(cin,u_password);

        ifstream login("Register Acct's/patient.txt");

        while (getline(login,line))
        {
            if (line.find("Username: " + u_username) !=string::npos)
            {
                getline(login,line);
                if (line.find("Password: " + u_password) !=string::npos)
                {
                    accfound = true;
                }
            }
            
        }
        
        return accfound;
    }

    //view personel details
    void patiendetails()
    {
        ifstream patient("patient.txt");
        if(!patient){cout << "Patient file opening ERROR!\n";}
        string line;
        bool patienfound = false;

        cin.ignore();
        cout << "Enter Full Name: ";
        getline(cin,fullname);

        while (getline(patient,line))
        {
            if (line.find("Name: " + fullname) !=string::npos)
            {
                patienfound = true;
                cout << line <<endl;
                getline(patient,line);
                for (int i = 0; i < 8; i++)
                {
                    getline(patient,line);
                    cout << line << endl;
                }
            }   
        }
        if (!patienfound)
        {
            cout << "Patient not found in Record\n";
        }
        
    }

    //view assign doctor
    void view_assign_dr_and_nurse()
    {
        string lines;
        string doctorname;
        bool drfound = false;
        bool patienfound = false;

        cin.ignore();
        cout << "Enter Patient full Name: ";
        getline(cin,fullname);

        ifstream patientfile("patient.txt");
        if(!patientfile){cout << "Patient File opening ERROR!\n";}

        while (getline(patientfile,lines))
        {
            if (lines.find("Name: " + fullname) !=string::npos)
            {
                cout << "Patient " << lines <<endl;
                patienfound = true;
                getline(patientfile,lines);
                for (int i = 0; i < 8; i++)
                {
                    getline(patientfile,lines);
                    if (lines.find("Doctor Assign: ") !=string::npos)
                    {
                        cout << lines << endl; 
                        getline(patientfile,lines);
                        doctorname = lines.substr(15);
                        drfound = true;
                    }
                }
            }
            
        }
        if (!drfound)
        {
            cout << "Doctor iS s not asign to te patient\n";
        }
        if(!patienfound){
            cout << "Ptient not found in record\n";
        }
        
    }

    //view room inforamtion
    void roominfo()
    {
        string roomno,roomline;
        bool roomfind = false;
        cout << "Enter Room Number: ";
        cin >> roomno;

        ifstream rooms("Rooms.txt");

        while (getline(rooms,roomline))
        {
            if (roomline.find("Room Number: " + roomno) !=string::npos)
            {
                cout << roomline <<endl;
                roomfind = true;
                for (int i = 0; i < 3; i++)
                {                
                    getline(rooms,roomline);
                    cout << roomline <<endl;
                }
                break;
            }
            
        }
        if (!roomfind)
        {
            cout << "Room not found. Please check the room number.\n";
        }
        
    }

};

class Reposrts
{
public:
    void roomsreports()
    {
        string line;
        int avalible = 0 , booked = 0, totalrooms = 0 , revenuerooms = 0;
        int occupacy = 0;
        ifstream rooms("Rooms.txt");

        while (getline(rooms,line))
        {
            if (line.find("Status: Available") !=string::npos)
            {
                avalible++;     
            }

            if (line.find("Status: Booked") !=string::npos)
            {
                booked++;
            }
            
        }
        rooms.clear();
        rooms.seekg(0,ios::beg);

         while (getline(rooms,line))
        {
            if (line.find("Room Number: ") !=string::npos)
            {
                totalrooms++;
            }
        }

        revenuerooms = booked*5000;

        occupacy = (booked * 100)/totalrooms;

        cout << "===== All Rooms Report ====\n";
        cout << "Total Rooms: "<<totalrooms <<endl;
        cout << "Total Booked Rooms: "<<booked <<endl;
        cout << "Total Avaliable Rooms: "<<avalible <<endl;
        cout << "Occupancy Rate: " << occupacy <<"%"<<endl;
        cout << "Revenue: " <<revenuerooms <<endl;
    }

    //patient record
    void patientreport()
    {
        ifstream patientrecord("patient.txt");
        ifstream dischargehistory("Dr Patients/Discharge History.txt");

        string line;
        int total = 0 , admitted = 0 , discharged = 0;
        int M=0 , F =0;
        
        while (getline(patientrecord,line))
        {
            if(line.find("Name: ") !=string::npos){total++;}
            if(line.find("Status: Admitted") !=string::npos){admitted++;}
            if(line.find("Status: Discharge") !=string::npos){discharged++;}
            if(line.find("Gender: Male") !=string::npos){M++;}
            if(line.find("Gender: Female") !=string::npos){F++;}
        }

        cout << "===== Patient Summary Report =====\n";
        cout << "Total Patient: "<<total <<endl;
        cout << "Currently Admitted: "<<admitted<<endl;
        cout << "Total Male : " <<M<<endl;
        cout << "Total Female : " <<F<<endl;
        cout << "Total Discharge: "<<discharged<<endl;
        
        patientrecord.clear();
        patientrecord.seekg(0,ios::beg);
        
        cout << "===== Detailed Patient Records =====\n";
        while (getline(patientrecord,line))
        {
            cout << line <<endl;
        }

        cout << "===== Patient Discharge History =====\n";
        while (getline(dischargehistory,line))
        {
            cout << line <<endl;
        }

    }

    //dr details
    void Dr_record()
    {
        ifstream drecord("Dr Details.txt");
        string line;
        int total;

        while (getline(drecord,line))
        {
            if(line.find("Doctor Name: ") !=string::npos){total++;}
        }
        
        drecord.clear();
        drecord.seekg(0,ios::beg);

        string drname;
        while (getline(drecord,line))
        {
            if(line.find("Doctor Name: ") !=string::npos){drname = line.substr(14);}
        }
    }

    //nurses record 
    void nursereport()
    {
        ifstream nurses("Nurses/Details.txt");
        ifstream nursesAssign("Nurses/Assignment.txt");

        string line;

        int M = 0, F = 0,assigntodr = 0,freenurse = 0;
        int total = 0;

        while (getline(nurses,line))
        {
            if(line.find("Name: ") !=string::npos){total++;}
            if(line.find("Gender: M") !=string::npos){M++;}
            if(line.find("Gender: F") !=string::npos){F++;}
            if(line.find("Assign Doctor: ") !=string::npos){assigntodr++;}
        }
        cout << "===== Nurses Summary Report =====\n";
        cout << "Total: "<<total<<endl; 
        cout << "Total Male: "<<M<<endl; 
        cout << "Total Female: "<<F<<endl; 
        cout << "Total Assign to Dr's: "<<assigntodr<<endl; 

        cout << "===== Nurses Assignment Details =====\n";
        while (getline(nursesAssign,line))
        {
            cout << line <<endl;
        }
    }

    void accountsreport()
    {
        ifstream regaccdr("Register Acct's/Dr.txt");
        ifstream regaccnurse("Register Acct's/nurse.txt");
        ifstream regaccpatient("Register Acct's/patient.txt");
        string line;

        if(!regaccdr){cout << "Dr Accounts File Error!\n";}
        if(!regaccnurse){cout << "Nurses Accounts File Error!\n";}
        if(!regaccpatient){cout << "Patients Accounts File Error!\n";}

        int dr=0,nuese=0,patient=0;
        while (getline(regaccdr,line)) {if(line.find("Full Name: ") !=string::npos){dr++;}}
        while (getline(regaccnurse,line)) {if(line.find("Full Name: ") !=string::npos){nuese++;}}
        while (getline(regaccpatient,line)) {if(line.find("Full Name: ") !=string::npos){patient++;}}

        int totalacc = dr+nuese+patient;

        cout << "===== Accounts Summary =====\n";
        cout << "Total Accounts's Registerd: "<<totalacc <<endl;
        cout << "Total Doctors Accounts's Registerd: "<<dr<<endl;
        cout << "Total Nurses Accounts's Registerd: "<<nuese<<endl;
        cout << "Total Patients Accounts's Registerd: "<<patient<<endl;

        regaccdr.clear();

        regaccdr.clear();
        regaccnurse.clear();
        regaccpatient.seekg(0,ios::beg);
        regaccnurse.seekg(0,ios::beg);
        regaccpatient.seekg(0,ios::beg);

        cout << "===== Doctors Accounts Summary =====\n";
        while (getline(regaccdr,line)) {cout << line <<endl;}
        cout << "===== Nurses Accounts Summary =====\n";
        while (getline(regaccnurse,line)){cout << line <<endl;}
        cout << "===== Patients Accounts Summary =====\n";
        while (getline(regaccpatient,line)){cout << line <<endl;}
    }
};
int main() {
    int choice;
    cout << "--------------------\n";
    cout << "Who are you?\n";
    cout << "1. Admin\n";
    cout << "2. Doctor\n";
    cout << "3. Nurse\n";
    cout << "4. Patient\n";
    cout << "--------------------\n";
    cout << "Enter Your Choice: ";
    cin >> choice;

    if (choice == 1) {
        Admin admin;
        if (admin.adminlogin()) {   
            cout << "====== Admin Panel ======\n";
            cout << "1. Manage Doctors\n";
            cout << "2. Manage Patients\n";
            cout << "3. Manage Staff\n";
            cout << "4. Manage Rooms\n";
            cout << "5. Reports\n";
            cout << "6. Log out\n";
            cout << "=========================\n";

            int choiceadmin;
            cout << "Enter your choice: ";
            cin >> choiceadmin;

            switch (choiceadmin) {
                case 1: {
                    ManageDoctor doctor;
                    int dochoice;
                    cout << "1. Add Doctor\n";
                    cout << "2. Delete Doctor\n";
                    cout << "3. View All Doctors\n";
                    cout << "Enter Choice: ";
                    cin >> dochoice;

                    if (dochoice == 1) {
                        doctor.ADDdoctor();
                    } else if (dochoice == 2) {
                        doctor.Deletedoctor();
                    } else if (dochoice == 3) {
                        doctor.viewdetails();
                    } else {
                        cout << "Invalid Choice\n";
                    }
                    break;
                }

                case 2: {
                    Managepatient patient;
                    int patientchoice;
                    cout << "1.Add Patient\n";
                    cout << "2.Delete Patient\n";
                    cout << "3.View All Patients\n";
                    cout << "Enter Choice: ";
                    cin >> patientchoice;

                    if (patientchoice == 1) {
                        patient.addpatient();
                    } else if (patientchoice == 2) {
                        patient.delpatient();
                    } else if (patientchoice == 3) {
                        patient.patientdetails();
                    } else {
                        cout << "Invalid Choice\n";
                    }
                    break;
                }

                case 3:{
                    MangeStaff Staff;
                    int staffchoice;
                    cout << "1.Add Nurse\n";
                    cout << "2.Assign Nurse to Doctor\n";
                    cout << "3.view All Nurses\n";
                    cout << "4.Delte Nurse\n";
                    cout << "Enter Choice: ";
                    cin >> staffchoice;

                    if (staffchoice == 1) {
                        Staff.addnurse();
                    } else if (staffchoice == 2) {
                        Staff.assignnursetodoctor();
                    } else if (staffchoice == 3) {
                        Staff.viewnurses();
                    } else if(staffchoice == 4){
                        Staff.deletenurse();                   
                    }else{
                        cout << "Invalid Choice\n";
                    }
                    break;
                }
                case 4:{
                    Managerooms room;
                    int roomchoice;
                    cout << "1.Add Room\n";
                    cout << "2.View All Rooms\n";
                    cout << "3.Delete Room\n";
                    cout << "Enter Choice: ";
                    cin >> roomchoice;

                    if (roomchoice == 1)
                    {
                        room.addroom();
                    }else if (roomchoice == 2)
                    {
                        room.viewallrooms();
                    }else if (roomchoice == 3)
                    {
                        room.deleteroom();
                    }else{
                        cout << "Invalid Choice\n";
                    }
                    break;
                }
                case 5:
                    Reposrts reports;
                    reports.roomsreports();
                    reports.patientreport();
                    reports.nursereport();
                    reports.accountsreport();
                    break;
                case 6:
                    cout << "Logging out...\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
                    break;
            }
        } else {
            cout << "Login Failed. Access Denied!\n";
        }
    } else if (choice == 2)
    {
        int choicedr;
        Doctor doctor;
        cout << "1.Registe\n";
        cout << "2.Login \n";
        cout << "Enter Choice: ";
        cin >> choicedr;

        if (choicedr == 1)
        {
            doctor.DoctorRegister();
        }else if(choicedr == 2)
        {
            if (doctor.doctorlogin())
            {
                int drchoice;
                cout << "Login Sucessfull!\n";
                cout << "--------------------\n";
                cout << "1.View Assign Patients\n";
                cout << "2.Update Patient Status\n";
                cout << "3.Search patients\n";
                cout << "4.View Assign Nurse\n";
                cout << "5.Log out\n";

                cout << "Enter Choice: ";
                cin >> drchoice;

                switch (drchoice)
                {
                case 1:
                    doctor.viewpatients();
                    break;
                case 2:
                    doctor.updatepatientstatus();
                    break;
                case 3:
                    doctor.searchpatient();
                    break;
                case 4:
                    doctor.assignnurse();
                    break;
                case 5:
                    cout <<"Good Bye Doctor!\n";
                    break;
                default:
                    cout << "Invalid Choice\n";
                    break;
                }
            }else{
                cout << "Login failed!\n";
            }
            
        }
    }else if (choice == 3)
    {
        int nurse;
        Nurse nurses;
        cout << "1.Register\n";
        cout << "2.Login\n";
        cout << "Enter Choice: ";
        cin >> nurse;

        if (nurse == 1)
        {
            nurses.registernurse();
        }else if(nurse == 2)
        {
            if (nurses.nurselogin())
            {
                int choice;
                cout << "WELCOME! Login Sucessfull\n";
                cout << "1.View Assign Patients\n";
                cout << "2.Add Patient Vital\n";
                cout << "3.Complete Patient Discharge\n";
                cout << "4.Logout\n";

                cout << "Enter choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    nurses.assignpatients();
                    break;
                case 2:
                    nurses.patientvitals();
                    break;
                case 3:
                    nurses.patientdischarge();
                    break;
                case 4:
                    cout << "Good BYE!\n";
                default:
                    cout << "Invalid Choice\n";
                    break;
                }
            }
            else
            {
                cout << "Acess Denied Login Failed\n";
            }
        }        

    }else if(choice == 4){
        Patient patients;
        int choice;
        cout << "1.Refister Account\n";
        cout << "2.Login\n";
        cout << "Enter choice: ";cin >> choice;
        if (choice == 1)
        {
            patients.patientresgister();
        }else if (choice == 2)
        {
            if (patients.patientlogin())
            {
                cout << "WELCOME! Login Sucessfull\n";
                cout << "--------------------\n";
                cout << "1.View My Details\n";
                cout << "2.View Assigned Doctor\n";
                cout << "3.View Room Information\n";
                cout << "4.Logout\n";

                cout << "Enter Choice: ";
                cin >>choice;

                switch (choice)
                {
                case 1:
                    patients.patiendetails();
                    break;
                case 2:
                    patients.view_assign_dr_and_nurse();
                    break;
                case 3:
                    patients.roominfo();
                    break;
                case 4:
                    cout << "Good BYE!\n";
                    break;
                default:
                    break;
                    cout << "Invalid Choice!\n";
                    break;
                }
            }else{
                cout << "Login failed wrong Username or passowrd\n";
            }   
        }
    }else{
        cout << "Invalid Choice\n";
    }

    return 0;
}