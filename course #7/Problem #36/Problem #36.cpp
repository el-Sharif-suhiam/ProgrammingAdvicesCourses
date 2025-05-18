// Problem #36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Problem #35.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


bool isVowle(char letter) {
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'o' || letter == 'i' || letter == 'u');
}
void WriteVowels(string msg) {

    for (short i = 0; i < msg.length(); i++) {
        if (isVowle(msg[i])) {
            cout << msg[i] << " ";
        }
    }
    cout << endl;
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
//void WriteWords(string msg) {
//    string word = "";
//    for (short i = 0; i < msg.length(); i++) {
//        if(msg[i] != ' ') {
//            word += msg[i];
//        }
//        if (msg[i] == ' ' && word.length() > 1 || (i+ 1) == msg.length() && word.length() > 1) {
//            cout << word << endl;
//            word = "";
//        }
//    }
//}

int main()
{
    string msg = ReadMsg();
    //char letter = ReadLetter();

    cout << "\nThe number of Words in your string is: " << countWords(msg) << endl;
  
    return 0;
}
