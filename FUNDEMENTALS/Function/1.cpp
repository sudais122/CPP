#include<iostream>
#include<string>
using namespace std;

void anstrom()
{
  int sum =0,cube =0,lastdigit,orignal,num;

  cout << "enter number";
  cin >> num;

  orignal = num;

  do
  {

    lastdigit = num % 10;
    cube = lastdigit*lastdigit*lastdigit;
    sum += cube;
    num = num /10;

  } while (num != 0);
  
  if (sum == orignal)
  {
    cout << orignal<< "is angstrom";
  }
  else
  {
    cout <<orignal<< "is not anstrom";
  }
}

int main()
{
  anstrom();

}