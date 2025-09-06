#include<iostream>
using namespace std;

void largestnum()
{

    int num,largest=0,orignal;

    cout << "enter num ";
    cin >> num ;
    
    orignal = num;

    while (num != 0)
    {
        int lastgidit =  num % 10;
        if (lastgidit > largest)
        {
            largest = lastgidit;
        }
        num = num /10;
    }
     cout << largest <<"is a largest in "  <<  orignal ;
}

int main()
{
    largestnum();
    return 0;
}
