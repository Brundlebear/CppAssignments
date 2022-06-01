
#include "Essay.h"
#include <iostream>
using namespace std;

int main()
{
    bool repeat = true;

    cout << "This program allows the user to enter grading criteria for a student and outputs the graded components, a final score, and a letter grade" << endl;

	while (repeat == true) {
        string looper = "z";
        Essay Paper;
        int gradeValue = 0;

        // Prompt user for inputs and populate Paper object.
        cout << "\n\nEnter Student's grammar points (0-30): ";
        cin >> gradeValue;
        Paper.setGrammar(gradeValue);
        cout << "\nEnter Student's spelling points (0-20): ";
        cin >> gradeValue;
        Paper.setSpelling(gradeValue);
        cout << "\nEnter Student's length points (0-20): ";
        cin >> gradeValue;
        Paper.setLength(gradeValue);
        cout << "\nEnter Student's content points (0-30): ";
        cin >> gradeValue;
        Paper.setContent(gradeValue);


        //Return Grade information and values.
        cout << "\n\nEssay score results:";
        cout << "\n-----------------------------------------" << endl;
        cout << "Grammar: " << Paper.getGrammar() << endl;
        cout << "Spelling: " << Paper.getSpelling() << endl;
        cout << "Correct Length: " << Paper.getLength() << endl;
        cout << "Content: " << Paper.getContent() << endl;
        cout << "Total Score: " << Paper.getScore() << endl;
        cout << "Essay Letter Grade: " << Paper.getLetterScore() << endl;

        
        //Looping structure
        while (looper != "y" && looper != "n" && looper != "Y" && looper != "N") {
            cout << "\n\nWould you like to repeat the program? (y/n)";
            cin >> looper;
            if (looper == "n" || looper == "N") {
                repeat = false;
            }
            else if (looper != "y" && looper != "Y") {
                cout << "\nPlease make a valid selection" << endl;
            }
        }
	};
}
