// Problem #44 remove punctuations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


string ReadMsg() {
    string msg;
    cout << "Enter you sentence : \n";
    getline(cin, msg);

    return msg;
}

string removePunct(string txt) {

    for (short i = 0; i < txt.length(); i++) {
        if (ispunct(txt[i])) {
            txt[i] = ' ';
        }
    }
    return txt;
}
int main()
{
    string msg = ReadMsg();

    cout << "\n" << removePunct(msg) << endl;

    return 0;
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
