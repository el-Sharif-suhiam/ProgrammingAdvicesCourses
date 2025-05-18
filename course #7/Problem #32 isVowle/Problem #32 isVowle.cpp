// Problem #32 isVowle.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
char ReadLetter() {
    char letter;
    cout << "Enter your letter : \n";
    cin >> letter;

    return letter;
}

bool isVowle(char letter) {
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'o' || letter == 'i' || letter == 'u');
}
short countLetter(string msg, char letter) {
    short Counter = 0;
    for (short i = 0; i < msg.length(); i++) {
        if (tolower(msg[i]) == tolower(letter)) {
            Counter++;
        }
    }
    return  Counter;
}


int main()
{
    //string msg = ReadMsg();
    char letter = ReadLetter();
    if (isVowle(letter))
        cout << "Yes: this letter is vowle \n";
    else
        cout << "No: this letter is NOT a vowle \n";


    return 0;
}
