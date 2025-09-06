#include<iostream>
using namespace std;

void countnum(){
    int num,count=0,orignal;

    cout << "enter num";
    cin >>  num;

    orignal = num;

    while (num != 0)
    {
        count++;
        num =  num /10; //remove last digit
    }

    cout << "there are " << count << "digit in" << orignal <<endl; 
    
}
int main()
{
 countnum();
}