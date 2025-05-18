// Problem #28 Invert all letters.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

char InvertChar(char letter) {
    return isupper(letter) ? tolower(letter) : toupper(letter);

}
string InvertCase(string sentence) {
    cout << "\nInverted case : \n";
    for (int i = 0; i < sentence.length(); i++) {

        sentence[i] = InvertChar(sentence[i]);
    }
    return sentence;
}

int main()
{
    string msg = ReadMsg();
    cout << InvertCase(msg) << "\n\n";

    return 0;
}
