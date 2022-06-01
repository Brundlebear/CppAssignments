#include <iostream>
#include <string>
    using namespace std;

    // Function prototype
    bool isPalindrome(string);
    bool repeat = true;

    int main() {
        const int SIZE = 7;

        // Create an array of strings to test.
        string testStrings[SIZE] =
        { "ABLE WAS I ERE I SAW ELBA",
          "FOUR SCORE AND SEVEN YEARS AGO",
          "NOW IS THE TIME FOR ALL GOOD MEN",
          "DESSERTS I STRESSED",
          "AKS NOT WHAT YOUR COUNTRY CAN DO FOR YOU",
          "A man a plan a canal panama",
          "KAYAK" };

        std::string userString = " ";
        string str;

        cout << "This program allows you to enter a word\nor phrase and verify if it ia a palindrome or not.\nA palindrome is a word or phrase that is\nspelled the same forward and backward\n\n";

        // Test the strings.
        for (int i = 0; i < SIZE; i++)
        {
            cout << "\"" << testStrings[i] << "\"";
            if (isPalindrome(testStrings[i]))
                cout << " is a palindrome.\n";
            else
                cout << " is NOT a palindrome.\n";
        }
        while (repeat == true) { //beginning of loop
            string looper = "a";

            cout << "\n\nEnter your own phrase to see if it is a palindrome" << endl;
            getline(cin, userString);
            str = userString;
            str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
            //getline(cin, str);

            if (isPalindrome(str)) {
                cout << "\nYour string is a palindrome!";
            }
            else {
                cout << "\nYour string is not a palindrome.";
            }

            while (looper != "y" && looper != "n" && looper != "Y" && looper != "N") {
                cout << "\nWould you like to test another string ? (y/n)";
                getline(cin, looper);
                if (looper == "n" || looper == "N") {
                    repeat = false;
                }
                else if (looper != "y" && looper != "Y") {
                    cout << "\nPlease make a valid selection" << endl;
                }
            }
        }
    }
    //*******************************************
    // The isPalindrome function returns true   *
    // the argument is a palindrome, false      *
    // otherwise.                               *
    //*******************************************

    bool isPalindrome(string str)
    {
        bool status = false;
        if (str.length() <= 1)
            status = true;
        else if (str.at(0) == str.at(str.length() - 1))
            status = isPalindrome(str.substr(1, str.length() - 2));

        return status;
    }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
