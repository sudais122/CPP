#include<iostream>
#include<cmath>
#include<fstream>
#define pi 3.14
using namespace std;

// Basic opration function
void basicopration()
{
    ofstream history("history.txt",ios::app);
    int a,b;
    char op;
    cout << "Enter ist number" << " ";
    cin >> a;

    cout << "Enter opration(+,-,*,/,%)" <<" ";
    cin >> op;

    cout << "Enter Second number" <<" ";
    cin >> b;

    switch (op)
    {
    case '+':
        cout << "Result: " <<" " << a+b <<endl;
        history << " Result of sum: " << " " << a+b <<endl;
        history << "---------------------" <<endl;
        break;
    case '-':
        cout << "Result: "<<" "  <<a-b <<endl;
        history << " Result of minus: " << " " << a-b <<endl;
        history << "---------------------" <<endl;
        break;
    case '/':
    if (b == 0)
    {
        cout << "division is not possible" <<endl;
    }
    else
    {
        float convert = (float)a/b;
        cout << "Result o division: " << convert <<endl;
        history << " Result: " << " " << convert <<endl;
        history << "---------------------" <<endl;
    }
    break;
    case '%':
        cout << "Result of Modulas: " <<" "  << a%b << endl;
        history << " Result: " << " " << a%b <<endl;
        history << "---------------------" <<endl;
        break;
    case '*':
        cout << "Result of Multiplication: " <<" " << a*b << endl;
        history << " Result: " << " " << a*b<<endl;
        history << "---------------------" <<endl;
    default:
        cout <<"invalid ERROR";
        break;
    }
}

//powe function
void power()
{
    ofstream history("history.txt",ios::app);
    int base,power,result = 1;

    cout << "Enter Base"<<" ";
    cin >> base;
    cout << "Enter power" <<" ";
    cin >> power;

    for (int i = 1; i <= power; i++)
    {
        result *= base;
    }
    cout << base << "raise to the power" << power << "=" << " " << result  <<endl;
    history << base << "raise to the power" << power << "=" << " " << result  <<endl;
    history << "---------------------" <<endl;
}

//squareroot function
void squaretoot()
{
    ofstream history("history.txt",ios::app);
    int x;
    cout << "Enter number to find square root: " <<" ";
    cin >> x;
    if (x > 0)
    {
         int result = sqrt(x);
         cout << "Square root of " << x  << "is" << result<<endl;
         history << "Square root of " << x  << "is" << result<<endl;
         history << "---------------------" <<endl;
         
    }
    else
    {
        cout << "Square root not found";
    }
}

//cube root function
void cuberoot()
{
    ofstream history("history.txt",ios::app);
    int x;
    cout << "Enter number to find cube root";
    cin >> x;

    int result = cbrt(x);
    cout << "The cube root of"  <<" "<< x  <<"is" <<" " << result <<endl;
    history << "The cube root of"  <<" "<< x  <<"is" <<" " << result <<endl;
    history << "---------------------" <<endl;
}

// factorial
void factorial()
{
    int x,fact=1;
    cout << "Enter number: " <<"" ;
    cin >> x;

    for (int i = 1; i <= x; i++)
    {
        fact *=i;
    }
    cout << "Factorial of " << " "<< x <<" is"  << " " << fact <<endl;
}

void findmean()
{
    ofstream history("history.txt",ios::app);
    int size,count=0,sum = 0;
    float mean = 1;
    cout << "For how many elemt you find the means" <<" ";
    cin >> size;

    int array[size];

    cout << "Enter" << " " << size <<" "<< "numbers to find Mean\n";
    for (int i = 0; i < size; i++)
    {
       cin >> array[i];
    }

    for (int i = 0; i < size; i++)
    {
        count++;
    }

    for (int i = 0; i < size; i++)
    {
        int lastdigit = array[i] % 10;
        sum += lastdigit;
    }

    mean = sum / count;

    cout << "The mean is: " << " " << mean << endl;
    history << "The mean is: " << " " << mean << endl;
    history << "---------------------" <<endl;
}

// for median function

void findmedian()
{
    ofstream history("history.txt",ios::app);

    int size;

    cout << "How many number you find the median" <<" ";
    cin >> size;

    int array[size];

    cout << "Enter" << " " << size << "Elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    
     if (size % 2 == 1) {
        cout << "Middle value: " << array[size / 2] << endl;
        history << "Middle value: " << array[size / 2] << endl;
        history << "---------------------" <<endl;
    } else {
        double middle = (array[size / 2 - 1] + array[size / 2]) / 2.0;
        cout << "Middle value (average of two): " << middle << endl;
        history << "Middle value (average of two): " << middle << endl;
        history << "---------------------" <<endl;
    }
    
}

// find average
void findaverage()
{
    ofstream history("history.txt",ios::app);

    int size,count = 0,sum = 0,average = 1;

    cout << "For how many value you want find average"<< " ";
    cin  >> size;

    int array[size];

    cout << "Enter " <<" " << size <<" "<< "elements\n";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < size; i++)
    {
        sum +=array[i];
    }

    for (int i = 0; i < size; i++)
    {
        count ++;
    }
    
    average = sum /count;
    cout << "Average is" << " " <<  average <<endl;
    history << "Average is" << " " <<  average <<endl;
    history << "---------------------" <<endl;
    
}

// rectengle area
void area_of_rectegle(){
    ofstream history("history.txt",ios::app);

    int Area,length,width;

    cout << "Enter Length"<<" ";
    cin >> length;
    cout << "Enter Width"<<" ";
    cin >> width;

    Area = length * width;
    cout << "Area of rectengle: " <<" " << Area <<endl;
    history << "Area of rectengle: " <<" " << Area <<endl;
    history << "---------------------" <<endl;
}

//area_of_triangle
void area_of_triangle()
{
    ofstream history("history.txt",ios::app);

    int Area,base,height;
    cout << "Enter base"<<" ";
    cin >> base;
    cout << "Enter height"<<" ";
    cin >> height;

    Area = 0.5 * base * height;

    cout << "Area of Triangle" <<" " <<Area <<endl;
    history << "Area of Triangle" <<" " <<Area <<endl;
    history << "---------------------" <<endl;

}

 //Area_of_Circle
 void  Area_of_Circle()
 {
    ofstream history("history.txt",ios::app);

    int radius,Area;
    cout << "Enter ridius"<<" ";
    cin >> radius;
    Area = pi * radius * radius;

    cout << "Area of Circle: "<<" " <<  Area <<endl;
    history << "Area of Circle: " <<" " <<  Area <<endl;
    history << "---------------------" <<endl;

 }

 //Perimeter of Rectangle
 void Perimeter_of_Rectangle()
 {
     ofstream history("history.txt",ios::app);

    int Perimeter,length,width;

    cout << "Enter length: "<<" " ;
    cin >> length;
    cout << "Enter width: "<<" " ;
    cin >> width;
    Perimeter = 2 * (length + width);
    cout << "Perimeter of Rectangle:" <<" " <<Perimeter <<endl;
    history<< "Perimeter of Rectangle:" <<" " <<Perimeter <<endl;
    history << "---------------------" <<endl;
 }

 //Perimeter_of_Triangle();
void Perimeter_of_Triangle()
 {
     ofstream history("history.txt",ios::app);

    int Perimeter,side1,side2,side3;

    cout << "Enter Side1: "<<" " ;
    cin >> side1;
    cout << "Enter side2: "<<" " ;
    cin >> side2;
    cout << "Enter side3"<<"";
    cin >> side3;
    Perimeter = side1 + side2 + side3;
    cout << "Perimeter of Triangle:" <<" " <<Perimeter <<endl;
    history<< "Perimeter of Triangle:" <<" " <<Perimeter <<endl;
    history << "---------------------" <<endl;
 }

//Perimeter_of_Circle();
void Perimeter_of_Circle()
{
    ofstream history("history.txt",ios::app);

    int radius,Perimeter;
    cout << "Enter radius" <<" ";
    cin >> radius;
    Perimeter = 2 * pi * radius;
    cout << "Perimeter of Circle" <<" " << Perimeter <<endl;
    history<< "Perimeter of Circle" <<" " << Perimeter <<endl;
    history << "---------------------" <<endl;
}

//volume_of_Rectangle();
void volume_of_Rectangle()
{   
     ofstream history("history.txt",ios::app);

    int Volume,side;
    cout << "Enter side" <<" ";
    cin >>side;
    Volume = side * side * side;
    cout << "Volume of Rectengle: " <<" " << Volume <<endl;
    history << "Volume of Rectengle: " <<" " << Volume <<endl;
    history << "---------------------" <<endl;
}

 //volumeof_Triangle();

void volumeof_Triangle()
{
    ofstream history("history.txt",ios::app);

    int Volume,radius;
    cout << "Enter radius" <<" ";
    cin >>radius;
    Volume = (4/3.0) * pi * (radius * radius * radius);
    cout << "Volume of Triangle: " <<" " << Volume <<endl;
    history << "Volume of Triangle: " <<" " << Volume <<endl;
    history << "---------------------" <<endl;
}

// volumeof_Circle();
void volumeof_Circle()
{
    ofstream history("history.txt",ios::app); 

    int Volume,radius,height;
    cout << "Enter radius" <<" ";
    cin >>radius;
    cout << "Enter height" <<" ";
    cin >>height;
    Volume = pi * (radius*radius) * height;
    cout << "Volume of circle: " <<" " << Volume <<endl;
    history << "Volume of circle: " <<" " << Volume <<endl;
    history << "---------------------" <<endl;
}
int main()
{
    int choice;

    // Display main menu
    cout << "1. Basic Operations (+, -, /, %, *)\n";
    cout << "2. Advanced Operations\n";
    cout << "3. Statistical Operations\n";
    cout << "4. Geometric Operations\n";
    cout << "5. Exit\n";
    cout << "_______________________________________" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            basicopration();
            break;

        case 2:
            cout << "------ Advanced Operations ------" << endl;
            cout << "1. Power" << endl;
            cout << "2. Square Root" << endl;
            cout << "3. Cube Root" << endl;
            cout << "4. Factorial" << endl;
            cout << "___________________" << endl;

            int advancechoice;
            cout << "Enter your choice: ";
            cin >> advancechoice;

            if (advancechoice == 1)
                power();
            else if (advancechoice == 2)
                squaretoot();
            else if (advancechoice == 3)
                cuberoot();
            else if (advancechoice == 4)
                factorial();
            else
                cout << "Invalid input!" << endl;
            break;

        case 3:
            cout << "------ Statistical Operations ------" << endl;
            cout << "1. Mean" << endl;
            cout << "2. Median" << endl;
            cout << "3. Average" << endl;
            cout << "___________________" << endl;

            int statChoice;
            cout << "Enter your choice: ";
            cin >> statChoice;

            if (statChoice == 1)
                findmean();
            else if (statChoice == 2)
                findmedian();
            else if (statChoice == 3)
                findaverage();
            else
                cout << "Invalid input!" << endl;
            break;

        case 4:
            cout << "------ Geometric Operations ------" << endl;
            cout << "1. Area" << endl;
            cout << "2. Perimeter" << endl;
            cout << "3. Volume" << endl;

            int geoChoice;
            cout << "Enter your choice: ";
            cin >> geoChoice;

            if (geoChoice == 1) {
                cout << "1. Area of Rectangle\n";
                cout << "2. Area of Triangle\n";
                cout << "3. Area of Circle\n";

                int subchoice;
                cout << "Enter your choice: ";
                cin >> subchoice;

                if (subchoice == 1)
                    area_of_rectegle();
                else if (subchoice == 2)
                    area_of_triangle();
                else if (subchoice == 3)
                    Area_of_Circle();
                else
                    cout << "Invalid input!" << endl;

            } else if (geoChoice == 2) {
                cout << "1. Perimeter of Rectangle\n";
                cout << "2. Perimeter of Triangle\n";
                cout << "3. Perimeter of Circle\n";

                int perimeterChoice;
                cout << "Enter your choice: ";
                cin >> perimeterChoice;

                if (perimeterChoice == 1)
                    Perimeter_of_Rectangle();
                else if (perimeterChoice == 2)
                    Perimeter_of_Triangle();
                else if (perimeterChoice == 3)
                    Perimeter_of_Circle();
                else
                    cout << "Invalid input!" << endl;

            } else if (geoChoice == 3) {
                cout << "1. Volume of Cube\n";
                cout << "2. Volume of Sphere\n";
                cout << "3. Volume of Cylinder\n";

                int volumeChoice;
                cout << "Enter your choice: ";
                cin >> volumeChoice;

                if (volumeChoice == 1)
                    volume_of_Rectangle();
                else if (volumeChoice == 2)
                    volumeof_Triangle();  
                else if (volumeChoice == 3)
                    volumeof_Circle();    
                else
                    cout << "Invalid input!" << endl;
            } else {
                cout << "Invalid category choice!" << endl;
            }
            break;

        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid main menu choice!" << endl;
        }

    } while (choice != 5);  
}