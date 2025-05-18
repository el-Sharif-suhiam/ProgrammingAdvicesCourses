// Problem #44.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


short countWords(string txt) {
    string delmi = " ";
    short pos = 0;
    string subtxt;
    short count = 0;
    while ((pos = txt.find(delmi)) != std::string::npos) {
        subtxt = txt.substr(0, pos);
        if (subtxt != "") {
            count++;
        }

        txt.erase(0, pos + delmi.length());
    }
    if (txt != "") {

        count++;
    }
    return count++;
}

vector<string> splitFunc(string msg, string delmi) {
    vector<string> vcWords;
    short pos = 0;
    string subtxt;
    while ((pos = msg.find(delmi)) != std::string::npos) {
        subtxt = msg.substr(0, pos);
        if (subtxt != "") {
            vcWords.push_back(subtxt);
        }

        msg.erase(0, pos + delmi.length());
    }
    if (msg != "") {

        vcWords.push_back(msg);
    }
    return vcWords;
}

string LowerAllString(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

string ReplaceWordWithAnother(string txt, string wantReplace, string toReplace, bool matchCase = false) {

    vector<string> vcString = splitFunc(txt, " ");
    for (string& word : vcString) {
        if (matchCase) {
            if (word == toReplace) {
                word = toReplace;
            }
        }
        else {
            if (LowerAllString(word) == LowerAllString(wantReplace)) {
                word = toReplace;
            }
        }
    }

    string newWord = joinString(vcString, " ");

    return newWord;
}

int main()
{
    //std::cout << "Hello World!\n";
    string message1 = "I am Alsharif from Libya , Libya is good country.";
    cout << message1 << endl;
    cout << ReplaceWordWithAnother(message1, "libya", "UK") << endl;
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
