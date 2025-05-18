// Problem #26.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
string ToUpperCase(string sentence) {
    cout << "To Upper case : \n";
    for (int i = 0; i < sentence.length(); i++) {
        
            sentence[i] = toupper(sentence[i]);
    }
    return sentence;
}

string ToLowerCase(string sentence) {
    cout << "To Upper case : \n";
    for (int i = 0; i < sentence.length(); i++) {

        sentence[i] = tolower(sentence[i]);
    }
    return sentence;
}
int main()
{
    string msg = ReadMsg();
    cout << ToUpperCase(msg) << "\n\n";
    cout << ToLowerCase(msg) << "\n\n";


}
