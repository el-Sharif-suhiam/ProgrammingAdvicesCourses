// problem #17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


string ReadPassword() {
    string password;

        cout << "Please enter a 3-Letter Password (all capital)?\n";
        cin >> password;
    return password;
}

bool check3LetterPassword(string password) {
    string word = "";
    short count = 0;
    for (short i = 65; i <= 90; i++) {
        for (short j = 65; j <= 90; j++) {
            for (short k = 65; k <= 90; k++) {
                 word = word +char(i);
                 word = word + char(j);
                 word = word + char(k);
                 cout << "Trial [" << count << "]: " << word << endl;

                 if (password == word) {
                     cout << "Password is " << word << endl;
                     cout << "Found after " << count << " Trial(s) \n";
                     return true;
                }
                 count++;
                 word = "";
            }
        }
    }
    return false;
}


int main()
{
    check3LetterPassword(ReadPassword());
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
