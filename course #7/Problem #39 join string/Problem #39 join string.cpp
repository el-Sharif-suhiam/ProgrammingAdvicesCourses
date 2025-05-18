// Problem #39 join string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


string ReadMsg() {
    string msg;
    cout << "Enter you sentence : \n";
    getline(cin, msg);

    return msg;
}



string joinString(vector<string> vcWords, string delmi) {
    string newString = "";
    for (string& word : vcWords) {
        newString = newString + word + delmi;
    };
    return newString.substr(0, newString.length() - delmi.length());
}

string joinString(string vcWords[], string delmi, short arrNum) {
    string newString = "";
    for (short i = 0; i < arrNum; i++) {
        newString = newString + vcWords[i] + delmi;
    };
    return newString.substr(0, newString.length() - delmi.length());
}
int main()
{
    vector<string> vString{"ali","jhon","morad","ed"};
    string arrString[] { "ali","jhon","morad","ed" };
    cout << "\n new Word = \n" << joinString(vString, " ") << endl;
    cout << "\n new Word by array = \n" << joinString(arrString, " ",4) << endl;

    

    return 0;
}
