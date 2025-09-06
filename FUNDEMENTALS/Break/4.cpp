// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[10] = {10,45,6,56,45,45,4};

//     int i;
//     for ( i = 0; i < 10; i++)
//     {
//         if (arr[i] > 50)
//         {
//             break;
//         }
//       cout << arr[i] <<" ";   
//     }
//            cout <<  "thre are " << i << "digits greater than 50" << endl;
    
// }
#include<iostream>
using namespace std; 
int main()
{
    int num[10],i;

    for ( i = 0; i < 10; i++)
    {
      cin >> num[i];

      if (num[i] % 7 == 0 )
      {
       break;
      }
    }

    cout << "Even numbers are: " << num[i]<< endl;
  
}
