// MorseConverterKBrundage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{

	static int MORSESIZE = 40; // size of morse code table
  // LETTERMATCH is a parallel array with MORSECODE for matching purposes, Both arrays are lined up by index, lettermatch[0] translates to morsecode[0] and so on
	static char LETTERMATCH[40] = { ' ' , ',' , '.' , '?','0','1','2','3','4','5','6','7','8','9','A','B','C','D',
		'E', 'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	// [SP]							        ,		.		  ?		  0		  1		  2		   3		4
	static string MORSECODE[40] = { " ","--..--",".-.-.-","..--..","-----",".----","..--- ","...--","....- ",

		// 5		6		7		8		9	   A	B		 C		D	  E		F		G	  H		 		
		".....","-.....","--...","---..","----.",".-"," -...","-.-."," -..",".","..-.", "--.","....",

		//I		J	  K		L	   M	N	 O		P	   Q	 R		S	T	 U		V	  W
		"..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--",

		//X		 Y		 Z
		"-..-","-.--","--.." };


	while (true) {
		//Prompt user for a string input to be translated
		string inputString;
		cout << "Please enter a message that you would like translated into Morse code" << endl
			<< "(Up to a maximum of 255 characters): ";
		getline(cin, inputString);
		//
		cout << endl << "\t";	//Starts a new line for the output

		int stringLength = inputString.length();
		for (int n = 0; n <= stringLength - 1; n++) {
			char upperLetter = toupper(inputString[n]);
			for (int i = 0; i <= MORSESIZE - 1; i++) {
				if (LETTERMATCH[i] == upperLetter) { //Finds the letter in the LETTERMATCH array and matches to the same position in MORSECODE array
					string morseLetter = MORSECODE[i];
					int morseLength = morseLetter.length();
					cout << upperLetter << setw(morseLength + 1) << " "; // Properly spaces the letters above their corresponding morse string
				}
			}
		}
		cout << endl << "\t";

		//Space the characters by using (morsecode[n].length)/2 on each side
	//For loop make string[] into uppercase char
		for (int n = 0; n <= stringLength - 1; n++) {
			char upperLetter = toupper(inputString[n]);
			//cout << upperLetter; //Test proper input
	//For loop to translate upperLetter into corresponding morse code and output letter
			for (int i = 0; i <= MORSESIZE - 1; i++) {
				if (LETTERMATCH[i] == upperLetter) {
					string morseLetter = MORSECODE[i];
					cout << morseLetter << "  "; // Outputs the corresponding morsecode string
				}
			}
		}

		cout << endl;

		//Loop to run program again if desired

		cout << "\nWould you like to run the program again? Enter Y for Yes or enter any other value to exit: ";
		string loopInput;
		getline(cin, loopInput);
		if (loopInput != "y" && loopInput != "Y") {
			break;
		}
		else {
			continue;
		}
		

	};
	return(0);
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
