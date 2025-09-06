#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    char correc_choice;
    char user_choice;
    int score_count =0,totalmarks = 10;
    float percentage;
    int choice;
    cout << "------WELCOME to Quiz\n";
    cout << "NOTE: Please Enter the Answer in Block letter only (A,B,C,D)\n";
    cout << "Press 1 to strt quiz\n";
    cout <<"Total Marks 20\n";
    cin >> choice;

    if (choice == 1)
    {
        //MCQS NO ist
       cout << "Q1. What is the correct syntax to output Hello World in C++?\n";
        cout << "A) print(\"Hello World\")\n";
        cout << "B) echo(\"Hello World\");\n";
        cout << "C) cout << \"Hello World\";\n";
        cout << "D) Console.Write(\"Hello World\");\n";
        cout <<"____________________________________________\n";
    correc_choice = 'C';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }

    //MCQS NO 2nd
        cout << "Q2. Which of the following is a correct comment in C++?\n";
        cout << "A) # This is a comment\n";
        cout << "B) // This is a comment\n";
        cout << "C) ** This is a comment **\n";
        cout << "D) <!-- This is a comment -->\n\n";        
        cout <<"____________________________________________\n";
    correc_choice = 'B';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }
    //third mcqs
        cout << "Q3. Which data type is used to create a variable that should store text?\n";
        cout << "A) myString\n";
        cout << "B) string\n";
        cout << "C) String\n";
        cout << "D) Txt\n\n";
        cout <<"____________________________________________\n";
    correc_choice = 'C';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }

    //fouth MCQS
        cout << "Q4. How do you create a variable with the numeric value 5?\n";
        cout << "A) num x = 5;\n";
        cout << "B) x = 5;\n";
        cout << "C) int x = 5;\n";
        cout << "D) double x = \"5\";\n\n";
        cout <<"____________________________________________\n";
    correc_choice = 'A';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }

    //fifth MCQS
        cout << "Q5. Which operator is used to add together two values?\n";
        cout << "A) &\n";
        cout << "B) +\n";
        cout << "C) add\n";
        cout << "D) &&\n\n";
        cout <<"____________________________________________\n";
    correc_choice = 'B';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }
    }

    //Sizth MCQS
        cout << "Q6. How do you create a function in C++?\n";
        cout<< "A) functionName[]\n";
        cout << "B) void functionName()\n";
        cout << "C) create functionName()\n";
        cout<< "D) function functionName()\n\n";
        cout <<"____________________________________________\n";
            correc_choice = 'B';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }

    //7 MCQS
        cout << "Q7. How do you call a function named 'myFunction'?\n";
        cout << "A) call myFunction();\n";
        cout << "B) myFunction();\n";
        cout << "C) call function myFunction();\n";
        cout << "D) Run myFunction();\n\n";
        cout <<"____________________________________________\n";
    correc_choice = 'B';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }

    //8 MCQS
        cout << "Q8. Which keyword is used to return a value inside a function?\n";
        cout << "A) get\n";
        cout << "B) return\n";
        cout << "C) break\n";
        cout << "D) void\n\n";
        cout <<"____________________________________________\n";
    correc_choice = 'B';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }

    //9 mcqs
        cout << "Q9. How do you start writing a for loop in C++?\n";
        cout << "A) for (i = 0; i < 5; i++)\n";
        cout << "B) for i = 1 to 5\n";
        cout << "C) foreach (i in range)\n";
        cout << "D) loop i from 1 to 5\n\n";     
        cout <<"____________________________________________\n";
        correc_choice = 'A';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }

    //10 mcqs
        cout << "Q10. What is the correct way to include a header file in C++?\n";
        cout << "A) #include \"iostream\"\n";
        cout << "B) include <iostream>\n";
        cout << "C) #include <iostream>\n";
        cout << "D) using namespace iostream\n\n";
        cout <<"____________________________________________\n";
    correc_choice = 'B';
    cout << "Enter Correct choice: " <<" ";
    cin >> user_choice;

    if (correc_choice == user_choice)
    {
        score_count++;
    }
    // Final calculation
    percentage = (score_count * 100.0) / totalmarks;
    cout << "Final Score: " << score_count << endl;
    cout << "Percentage: " << percentage << "%" << endl;

string remarks;

if (percentage >= 90) {
    remarks = "Excellent";
}
else if (percentage >= 75) {
    remarks = "Very Good";
}
else if (percentage >= 60) {
    remarks = "Good";
}
else if (percentage >= 50) {
    remarks = "Average";
}
else {
    remarks = "Needs Improvement";
}

cout << "Remarks: " <<" "<< remarks << endl;

}
