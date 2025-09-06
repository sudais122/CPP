 #include<iostream>
 using namespace std;

 class student
 {
    int marks[3][3];
    int sum[3] = {0};
public:
    void input()
    {
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Marks of Student "<<i +1 <<endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter Marks: " << j+1 <<" ";
            cin >> marks[i][j];
            sum[i] += marks[i][j];
         }
    }
    }

    void show()
    {
        cout << "----Result----\n";
        for (int i = 0; i < 3; i++)
    {
        cout << "Marks of Student "<<i +1 <<endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Marks:"<< j+1 <<":" << marks[i][j]<<"\n";
        }
        cout << "Sum: " <<sum[i]<<endl;
    }
    }

    void topscorer()
    {
        int top = sum[0];
        int toperindex = 0;
        
        for (int i = 1; i < 3; i++)
        {
            if (sum[i] > toperindex)
            {
                top = sum[i];
                toperindex = i;
            }
        }
        cout << "Top Scorer: Student " << toperindex + 1 << " with Total Marks = " << top << endl;
    }
};
 int main() {
     
    student s;
    s.input();
    s.show();
    s.topscorer();
     return 0;
 }