// Problem #41 revese words.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
void PrintWord(vector<string> vcWord) {
    for (short i = 0; i < vcWord.size(); i++) {
        cout << vcWord[i] << endl;
    }
}
string RevserseWordsInString(string msg) {
    string newString = "";
    vector<string> vcWords = splitFunc(msg, " ");
    vector<string>::iterator iter = vcWords.end();
    while (iter != vcWords.begin()) {
        --iter;
        newString += *iter + " ";
    }
    
    return newString.substr(0, newString.length() - 1);
}


int main()
{

    string message = ReadMsg();

    //string arrString[]{ "ali","jhon","morad","ed" };
    cout << "\n new Word = \n" << RevserseWordsInString(message) << endl;
    //cout << "\n new Word by array = \n" << joinString(arrString, " ", 4) << endl;



    return 0;
}
