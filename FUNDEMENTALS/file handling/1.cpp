#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream file("file.txt",ios::binary);
    string line;
    if (file.is_open())
    {
        while (getline(file,line))
        {
         cout << line << endl;
        }
        
        
    }
    else
    {
        cout << "error occur";
    }
    file.close();
}
